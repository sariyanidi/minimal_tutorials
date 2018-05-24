PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)

# location of the Boost Python include files and library
BOOST_INC = /usr/include/boost148/
BOOST_LIB = /usr/lib64/boost148/

# location of the numpy headers
NUMPY_INC = /usr/lib64/python2.7/site-packages/numpy/core/include

# This is where the file pyopencv_generated_include.h needs to live
OPENCV_PYTHON2_INC = /usr/share/opencv/opencv-3.1.0/build/modules/python2/

# This is where the file pycompat.hpp needs to live
OPENCV_PYTHON_SRC_INC = /usr/share/opencv/opencv-3.1.0/modules/python/src2/

# I use the one below instead of OPENCV_LIB = `pkg-config --libs opencv` because in my case it failed to find all necessary libraries
OPENCV_LIB = -lopencv_core -lopencv_flann -lopencv_features2d -lopencv_ml -lopencv_calib3d -lopencv_highgui -lopencv_imgproc   -lopencv_photo -lopencv_imgcodecs -lopencv_videoio -lopencv_objdetect -lopencv_shape -lopencv_stitching  -lopencv_video

OPENCV_CFLAGS = `pkg-config --cflags opencv`

TARGET = pysomemodule
SRC =  abc.cpp pysomemodule.cpp 
OBJ =  abc.o pysomemodule.o

$(TARGET).so: $(OBJ)
	g++ -fPIC -I$(PYTHON_INCLUDE) -I$(NUMPY_INC) -I$(OPENCV_PYTHON2_INC) -I$(OPENCV_PYTHON_SRC_INC) -shared -fPIC -Wl,--no-undefined -o $(TARGET).so   $(OBJ) -L$(BOOST_LIB)  -L/usr/lib64/python$(PYTHON_VERSION)/config  -L/usr/local/lib/ -lboost_python  -lpython$(PYTHON_VERSION) $(OPENCV_LIB)

$(OBJ): $(SRC)
	g++ -I$(PYTHON_INCLUDE) -I$(OPENCV_PYTHON2_INC) -I$(OPENCV_PYTHON_SRC_INC) -I$(BOOST_INC) $(OPENCV_CFLAGS) -fPIC -c $(SRC)

clean:
	rm -f $(TARGET).so
	rm -f $(OBJ)
