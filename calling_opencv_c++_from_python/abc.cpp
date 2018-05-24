/*
Taken and modified by evangelos from the stackoverflow response of lightalchemist at https://stackoverflow.com/questions/12957492/writing-python-bindings-for-c-code-that-use-opencv
*/

#include "abc.hpp"
#include "cv2.hpp"

ABC::ABC() {}

// Note the import_array() from NumPy must be called else you will experience segmentation faults.
ABC::ABC(const std::string &someConfigFile)
{
  // Initialization code. Possibly store someConfigFile etc.
  import_array(); // This is a function from NumPy that MUST be called.
  // Do other stuff
}

// The conversions functions above are taken from OpenCV. The following function is 
// what we define to access the C++ code we are interested in.
PyObject* ABC::doSomething(PyObject* image)
{
    cv::Mat cvImage;
    pyopencv_to(image, cvImage); // From OpenCV's source

    //MyCPPClass obj; // Some object from the C++ library.
    cv::Mat processedImage = cvImage*3+4;

    return pyopencv_from(processedImage); // From OpenCV's source
}
