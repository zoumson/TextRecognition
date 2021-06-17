cmake_minimum_required (VERSION 3.0) 

PROJECT(text)

#Set the compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


#Set ccache (for speeding up)
find_program(CCACHE_FOUND ccache) 
if(CCACHE_FOUND) 
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache) 
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) 
endif(CCACHE_FOUND) 
set (CMAKE_CXX_FLAGS "-DPCL_ONLY_CORE_POINT_TYPES=ON -DNO_EXPLICIT_INSTANTIATIONS") 

IF(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
ENDIF()
#set(TESSDATA_PREFIX "/usr/share/tesseract-ocr/tessdata")
# Requires OpenCV v4.0 or later
FIND_PACKAGE( OpenCV 4 REQUIRED )

find_package( PkgConfig REQUIRED)

pkg_search_module( TESSERACT REQUIRED tesseract )

pkg_search_module( LEPTONICA REQUIRED lept )

include_directories( ${TESSERACT_INCLUDE_DIRS} )

include_directories( ${LEPTONICA_INCLUDE_DIRS} )

link_directories( ${TESSERACT_LIBRARY_DIRS} )

link_directories( ${LEPTONICA_LIBRARY_DIRS} )

include_directories( ${OpenCV_INCLUDE_DIRS} )

ADD_EXECUTABLE( segment ${PROJECT_SOURCE_DIR}/src/segment.cpp )
TARGET_LINK_LIBRARIES( segment  ${CONAN_LIBS} ${OpenCV_LIBS})

ADD_EXECUTABLE( segmentOcr ${PROJECT_SOURCE_DIR}/src/segmentOcr.cpp )
TARGET_LINK_LIBRARIES( segmentOcr  ${CONAN_LIBS} ${OpenCV_LIBS} ${TESSERACT_LIBRARIES} ${LEPTONICA_LIBRARIES})

ADD_EXECUTABLE( segmentOcrHigh ${PROJECT_SOURCE_DIR}/src/segmentOcrHigh.cpp )
TARGET_LINK_LIBRARIES( segmentOcrHigh  ${CONAN_LIBS} ${OpenCV_LIBS} ${TESSERACT_LIBRARIES} ${LEPTONICA_LIBRARIES})
