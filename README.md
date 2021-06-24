[![LinkedIn][linkedin-shield]][linkedin-url]
<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


[![Github][github-shield]][github.com/zoumson?tab=repositories]
[![Stack Overflow][stackoverflow-shield]][stackoverflow.com/users/11175375/adam]
[![Leetcode][leetcode-shield]][eetcode.com/Hard_Code/]
-->
## Identify Gender and Age From Face Using DNN
![d](https://user-images.githubusercontent.com/38358621/123162190-e5324700-d4a2-11eb-9b61-316e6c7a17f5.png)
<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#file-structure">Files Structure</a>
      <ul>
        <li><a href="#folders">Folders</a></li>
        <li><a href="#entire-files-structure">Entire Files Structure</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->
Age and gender estimation based on face images plays an important role in a wide range of scenarios, including 
* security and defense applications, 
* * border control, 
* human-machine interaction in ambient intelligence applications, and 
* recognition based on soft biometric information
In this project a pre-trained deep neural network model is used to first detect faces from a given image. The face detected is then used for gender and age estimation. 
<!--Built with -->
### Built With

<br>

* [opencv](https://opencv.org/)
* [cmake](https://cmake.org/)

<br>

## File Structure

### Folders

* [resource/](resource/): images.
* [src/](src/): c++ definitions.


### Entire Files Structure 

```
.
├── CMakeLists.txt
├── README.md
├── resource
│   ├── image
│   │   └── christiano.png
│   ├── model
│   │   ├── age_net.caffemodel
│   │   ├── gender_net.caffemodel
│   │   └── opencv_face_detector_uint8.pb
│   ├── proto
│   │   ├── age_deploy.prototxt
│   │   ├── gender_deploy.prototxt
│   │   └── opencv_face_detector.pbtxt
│   └── video
│       └── video.mp4
└── src
    └── demo.cpp

6 directories, 11 files


```


<!-- GETTING STARTED -->
## Getting Started

This is a sample code of how you may use  the opencv dnn to detect face, gender and age.
To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* cmake
  ```sh
  sudo apt-get install cmake
  ```

 * opencv4

 *Installation*
 ```sh
 sudo su
 ```
 ```sh
git clone https://github.com/zoumson/OpencvInstall.git     \
&& cd OpencvInstall && chmod +x install.sh && ./install.sh
 ```
 *keywords* 
 
[2/](https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html?highlight=threshold#threshold/)
[3/](https://learnopencv.com/otsu-thresholding-with-opencv/)
[5/](https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html#gac342a1bb6eabf6f55c803b09268e36dc)
[6/](https://docs.opencv.org/master/d4/d86/group__imgproc__filter.html/)
[8/](https://stackoverflow.com/questions/11182203/helping-using-the-dilate-function-opencv/)
[10/](https://stackoverflow.com/questions/8449378/finding-contours-in-opencv/)
[11/](https://stackoverflow.com/questions/8830619/difference-between-cv-retr-list-cv-retr-tree-cv-retr-external/)
[12/](https://docs.opencv.org/3.4/db/dd6/classcv_1_1RotatedRect.html/)
[15/](https://docs.opencv.org/3.4/db/dd6/classcv_1_1RotatedRect.html/)
[13/](https://docs.opencv.org/3.4/d3/dc0/group__imgproc__shape.html#ga3d476a3417130ae5154aea421ca7ead9/)
[17/](https://docs.opencv.org/3.4/d2/de8/group__core__array.html#gga209f2f4869e304c82d07739337eae7c5aed2e4346047e265c8c5a6d0276dcd838/)
[18/](https://docs.opencv.org/3.4/dc/da3/tutorial_copyMakeBorder.html/)


```
1. cv::cvtColor
2. cv::threshold
3. cv::THRESH_OTSU
4. cv::countNonZero
5. cv::getStructuringElement
6. cv::MORPH_CROSS
7. cv::Size
8. cv::dilate
9. cv::Point
10. cv::findContours
11. cv::RETR_EXTERNAL
12. cv::RotatedRect
13. cv::minAreaRect	
14. cv::getRotationMatrix2D
15. cv::warpAffine
16. cv::getRectSubPix
17. cv::BORDER_CONSTANT
18. cv::copyMakeBorder
```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/zoumson/FindAgeGender.git
   ```
2. Go to the project directory source
   ```sh
   cd FindAgeGender
   ```
3. Create empty directories 
   ```sh
   mkdir build &&  mkdir bin && mkdir result && cd result && mkdir image && cd ..
   ```
5. Generate the exectutable and move it to `bin`
   ```sh
   cd build && cmake .. && make -j4 && cd ..
   ```

<!-- USAGE EXAMPLES -->
### Usage

1. Run the executable 
 ```sh
   ./bin/demo -i=./resource/image/christiano.png -s=./result/image/output.png
```
2. Original Image

![christiano](https://user-images.githubusercontent.com/38358621/123162160-db104880-d4a2-11eb-8c32-d1ba2a3119b2.png)

3. Output image 
![d](https://user-images.githubusercontent.com/38358621/123162190-e5324700-d4a2-11eb-9b61-316e6c7a17f5.png)

4. Back to the initial file structure configuration
   ```sh
   rm -r bin build result 
   ```
<!-- ROADMAP -->
## Roadmap

All the headers files are well docummented, read through the comments

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Adama Zouma - <!-- [@your_twitter](https://twitter.com/your_username) -->- stargue49@gmail.com

Project Link: [https://github.com/zoumson/FindAgeGender](https://github.com/zoumson/FindAgeGender.git)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Google](https://www.google.com/)
* [Stack Overflow](https://stackoverflow.com/)
* [Github](https://github.com/)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: linkedin.com/in/adama-zouma-553bba13a
[product-screenshot]: images/screenshot.png

