
#include <opencv2/opencv.hpp>
#include "MyTesseract.h"
#include <fstream>
#include "PreprocessTesseract.h"

int main(int argc, char* argv[]) 
{
setenv("TESSDATA_PREFIX","/usr/share/tesseract-ocr/tessdata",1);
    cv::String keys =
        "{i image |<none>           | image path}"                           
        "{s show |false          | show cropped image}"                           
        "{o output |./result/output.txt           | output text from image}"                           
        "{help h usage ?    |      | show help message}";      
  
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Segment OCR");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }

    cv::String image = parser.get<cv::String>("image"); 
    cv::String output = parser.get<cv::String>("output"); 
    bool show; 
    if (parser.has("help")) show = parser.get<bool>("show"); 

 
    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }
     int threshLow = 0, threshUp = 255;
     cv::ThresholdTypes thresh = cv::THRESH_OTSU;
	//Loads the ticket image and binarize it

	cv::Mat ticket = za::binarize(cv::imread(image), threshLow, threshUp, thresh);	
    cv::MorphShapes kernelShape = cv::MORPH_CROSS;
    cv::RetrievalModes countourRelation = cv::RETR_EXTERNAL;
    int dilateIntensity = 5;
    int sBox = 20;
    bool square = true;
    auto regions = za::findTextAreas(ticket,  kernelShape, countourRelation, dilateIntensity, sBox, square) ;

	std::ofstream file; 
	file.open(output.c_str(), std::ios::out | std::ios::binary);

	//For each region
	for (const auto& region : regions) 
    {
		//Crop 
        cv::InterpolationFlags InterFlag = cv::INTER_CUBIC;
        int angleAdjust = 90 ;
        cv::BorderTypes borderType = cv::BORDER_REPLICATE; 
        std::vector<int> pos = {10, 10, 10 ,10};
        auto cropped = za::deskewAndCrop(ticket, region, InterFlag, angleAdjust, borderType, pos);
        //auto cropped = region; 
        if(parser.has("show")) 
        {
        cv::imshow("Cropped text", cropped);
		cv::waitKey(0);	
		cv::destroyWindow("Cropped text");
        }
		//auto cropped = za::deskewAndCrop(ticket, region);
		//auto text = za::identifyText(cropped, "por");
        // french fra
		auto text = za::identifyText(cropped, "por");
		
		file.write(text, strlen(text));
		file << "\n";
	}
	
	file.close();
}