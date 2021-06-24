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
 * @file PreprocessTesseract.h
 *
 * @brief Blob related functions. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */
#ifndef PREPROCESS_TESSERACT_H      
#define PREPROCESS_TESSERACT_H

#include <opencv2/opencv.hpp>
#include <vector>

namespace za {
extern cv::RNG rng;
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
 * \param threshLow [in] first point, type is opencv Point
 * \param threshUp [in] first point, type is opencv Point
 * \param thresh [in] first point, type is opencv Point
 *
 * \return type is double
 *  
 */
cv::Mat binarize(cv::Mat input, int threshLow, int threshUp, cv::ThresholdTypes thresh);

/**
 * \brief Match current frame Blobs to existing Blobs.
 *
 * \details Match current frame Blobs to existing Blobs.
 *
 * \param input [in] existing Blobs, type is vector of Blob
 * \param kernelShape [in] curent Blobs, type is vector of Blob
 * \param countourRelation [in] curent Blobs, type is vector of Blob
 * \param dilateIntensity [in] curent Blobs, type is vector of Blob
 * \param sBox [in] curent Blobs, type is vector of Blob
 * \param square [in] curent Blobs, type is vector of Blob
 *
 * \return type is void
 *  
 */
std::vector<cv::RotatedRect> findTextAreas(cv::Mat input, cv::MorphShapes kernelShape, cv::RetrievalModes countourRelation, int dilateIntensity, int sBox, bool square); 
/**
 * \brief Add Blob to existing Blobs.
 *
 * \details Add Blob to existing Blobs.
 *
 * \param input [in] curent Blob, type is Blob
 * \param box [in] [in] existing Blobs, type is vector of Blob
 * \param InterFlag [in] index, type is int
 * \param angleAdjust [in] index, type is int
 * \param borderType [in] index, type is int
 * \param pos [in] index, type is int
 *
 * \return type is void
 *  
 */
cv::Mat deskewAndCrop(cv::Mat input, const cv::RotatedRect& box, cv::InterpolationFlags InterFlag, int angleAdjust, cv::BorderTypes borderType, std::vector<int> pos);

}

# endif	// PREPROCESS_TESSERACT_H

