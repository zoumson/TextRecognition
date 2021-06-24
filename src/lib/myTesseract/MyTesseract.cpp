#include "MyTesseract.h"
namespace za {
tesseract::TessBaseAPI ocr;

const char* identifyText(cv::Mat input, const char* language)
{	
	ocr.Init(NULL, language, tesseract::OEM_TESSERACT_ONLY);	
	ocr.SetVariable("tessedit_write_images", "1");
	ocr.SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
	ocr.SetImage(input.data, input.cols, input.rows, input.elemSize(), input.cols);
	
	const char* text = ocr.GetUTF8Text();
	std::cout << "Text:\n";
	std::cout << text << "\n";
	std::cout << "Confidence: " << ocr.MeanTextConf() <<"\n\n";
	
    // Get the text    
	return text;
}


}