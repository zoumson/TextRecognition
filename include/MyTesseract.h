/*
* Text Recognition.
* See COPYRIGHT file at the top of the source tree.
*
* This product includes software developed by the
* STARGUE Project (http://www.stargue.org/).
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the STARGUE License Statement and
* the GNU General Public License along with this program. If not,
* see <http://www.lsstcorp.org/LegalNotices/>.
*/

/**
 * @file MyTesseract.h
 *
 * @brief Blob related functions. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */
#ifndef MY_TESSERACT_H      
#define MY_TESSERACT_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <tesseract/baseapi.h>
namespace za {
extern tesseract::TessBaseAPI ocr;
/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Distance between two points.
 *
 * \details Distance between two points.
 *
 * \param input [in] first point, type is opencv Point
 * \param language [in] first point, type is opencv Point
 *
 * \return type is double
 *  
 */
const char* identifyText(cv::Mat input, const char* language = "eng");

}

# endif	// MY_TESSERACT_H


