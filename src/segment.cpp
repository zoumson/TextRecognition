#include <opencv2/opencv.hpp>

#include <vector>

using namespace std;
using namespace cv;

cv::Mat binarize(cv::Mat input) 
{	
	setenv("TESSDATA_PREFIX","/usr/share/tesseract-ocr/tessdata",1);
	//Uses otsu to threshold the input image
	cv::Mat binaryImage;
	cv::cvtColor(input, input, COLOR_BGR2GRAY);
	cv::threshold(input, binaryImage, 0, 255, THRESH_OTSU);

	//Count the number of black and white pixels
	int white = countNonZero(binaryImage);
	int black = binaryImage.size().area() - white;

	//If the image is mostly white (white background), invert it
	return white < black ? binaryImage : ~binaryImage;
}

vector<RotatedRect> findTextAreas(cv::Mat input) {
	//Dilate the image
	auto kernel = getStructuringElement(MORPH_CROSS, Size(3,3));
	cv::Mat dilated;
	dilate(input, dilated, kernel, cv::Point(-1, -1), 5);

	//Find all image contours
	vector<vector<Point>> contours;
	findContours(dilated, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//For each contour
	vector<RotatedRect> areas;
	for (const auto& contour : contours) 
	{	
		//Find it's rotated rect
		auto box = minAreaRect(contour);

		//Discard very small boxes
		if (box.size.width < 20 || box.size.height < 20)
			continue;

		//Discard squares shaped boxes and boxes 
		//higher than larger
		double proportion = box.angle < -45.0 ?
			box.size.height / box.size.width : 
			box.size.width / box.size.height;

		if (proportion < 2) 
			continue;

		//Add the box
		areas.push_back(box);
	}
	return areas;
}

cv::Mat deskewAndCrop(cv::Mat input, const RotatedRect& box)
{
	double angle = box.angle;	
	auto size = box.size;

	//Adjust the box angle
   if (angle < -45.0) 
	{
        angle += 90.0;
        std::swap(size.width, size.height);		
	}
	
	//Rotate the text according to the angle
	auto transform = getRotationMatrix2D(box.center, angle, 1.0);
	cv::Mat rotated;
	warpAffine(input, rotated, transform, input.size(), INTER_CUBIC);

	//Crop the result
	cv::Mat cropped;
	getRectSubPix(rotated, size, box.center, cropped);
	copyMakeBorder(cropped,cropped,10,10,10,10,BORDER_CONSTANT,Scalar(0));
	return cropped;
}

int main(int argc, char* argv[]) 
{

    String keys =
        "{i image |<none>           | image path}"                           
        "{help h usage ?    |      | show help message}";      
  
    CommandLineParser parser(argc, argv, keys);
    parser.about("Segment");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }

    String image = parser.get<String>("image"); 

 
    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }

	//Loads the ticket image and binarize it
	auto ticket = binarize(imread(image));
	auto regions = findTextAreas(ticket);
	
	//For each region
	for (const auto& region : regions) {
		//Crop 
		auto cropped = deskewAndCrop(ticket, region);

		//Show
		imshow("Cropped text", cropped);
		waitKey(0);	
		destroyWindow("Cropped text");
	}
}

