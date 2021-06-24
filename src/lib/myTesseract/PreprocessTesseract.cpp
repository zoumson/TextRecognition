#include "PreprocessTesseract.h"
namespace za {

cv::RNG rng(12345);
cv::Mat binarize(cv::Mat input, int threshLow, int threshUp, cv::ThresholdTypes thresh)
{	

	//Uses otsu to threshold the input image
	cv::Mat binaryImage;
	cv::cvtColor(input, input, cv::COLOR_BGR2GRAY);
	//cv::threshold(input, binaryImage, 0, 255, cv::THRESH_OTSU);
	cv::threshold(input, binaryImage, threshLow, threshUp, thresh);

	//Count the number of black and white pixels
	int white = cv::countNonZero(binaryImage);
	int black = binaryImage.size().area() - white;

	//If the image is mostly white (white background), invert it
	return white < black ? binaryImage : ~binaryImage;
}

std::vector<cv::RotatedRect> findTextAreas(cv::Mat input, cv::MorphShapes kernelShape, cv::RetrievalModes countourRelation, int dilateIntensity, int sBox, bool square) 
{
	//Dilate the image
	auto kernel = cv::getStructuringElement(kernelShape, cv::Size(3,3));
	//auto kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3,3));
	cv::Mat dilated;
	cv::dilate(input, dilated, kernel, cv::Point(-1, -1), dilateIntensity);

	//Find all image contours
	std::vector<std::vector<cv::Point>> contours;
	//cv::findContours(dilated, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::findContours(dilated, contours, countourRelation, cv::CHAIN_APPROX_SIMPLE);

	//For each contour
	std::vector<cv::RotatedRect> areas;
	for (const auto& contour : contours) 
	{	
		//Find it's rotated rect
		auto box = cv::minAreaRect(contour);
		
		//Discard very small boxes
		//if (box.size.width < 20 || box.size.height < 20)
		if (box.size.width < sBox || box.size.height < sBox)
			continue;
		
		//Discard squares shaped boxes and boxes 
		//higher than larger

        if(!square)
        {
		double proportion = box.angle < -45.0 ?
			box.size.height / box.size.width : 
			box.size.width / box.size.height;

		if (proportion < 2) continue;
        }
	
		//Add the box
		areas.push_back(box);
	}
	return areas;
}

cv::Mat deskewAndCrop(cv::Mat input, const cv::RotatedRect& box, cv::InterpolationFlags InterFlag, int angleAdjust, cv::BorderTypes borderType, std::vector<int> pos)
{
	double angle = box.angle;	
	auto size = box.size;

	//Adjust the box angle
   if (angle < -45.0) 
	{
        //angle += 90.0;
        angle += angleAdjust;
        std::swap(size.width, size.height);		
	}
	
	//Rotate the text according to the angle
	auto transform = cv::getRotationMatrix2D(box.center, angle, 1.0);
	cv::Mat rotated;
	//cv::warpAffine(input, rotated, transform, input.size(), cv::INTER_CUBIC);
	cv::warpAffine(input, rotated, transform, input.size(),   InterFlag);
	//rotated = input;
	//Crop the result
	cv::Mat cropped;
	cv::getRectSubPix(rotated, size, box.center, cropped);
	//cv::copyMakeBorder(cropped,cropped,10,10,10,10,cv::BORDER_CONSTANT,cv::Scalar(0));
    cv::Scalar borderColor( rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255) );

	cv::copyMakeBorder(cropped,cropped,pos[0],pos[1],pos[2],pos[3],borderType,borderColor);
	return cropped;
}



}