#Custom lib
set(Custom_LIBS myTesseract)
#Bring the sources
file(GLOB SOURCES_DEMO ${PROJECT_SOURCE_DIR}/src/demo/*.cpp)

#Build the executable
add_executable(demo ${SOURCES_DEMO})

#Link the libraries 
target_link_libraries(demo ${Custom_LIBS}  ${CONAN_LIBS} ${OpenCV_LIBS} ${TESSERACT_LIBRARIES} ${LEPTONICA_LIBRARIES})