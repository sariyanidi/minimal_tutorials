README:
---------
This is a minimal stand-alone piece of sofware that shows how to run C++ OpenCV code within python for RHEL. This solution is based mostly on the stackoverflow response of lightalchemist at https://stackoverflow.com/questions/12957492/writing-python-bindings-for-c-code-that-use-opencv and uses the following libraries: 

* Python 2.7
* OpenCV 3.1.0
* Boost 1.48 (lib boost-python and possibly others)

The steps are:
1) Compile OpenCV. To run python wrapper you need to build opencv with the -DBUILD_opencv_python2=ON option and others if necessary; see below the example command that I used.
	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -DBUILD_opencv_python2=ON -DBUILD_opencv_python3=OFF -DWITH_CUDA=OFF -DWITH_FFMPEG=OFF -DPYTHON_INCLUDE_DIR=/usr/include/python2.7/  -DPYTHON_LIBRARY=/usr/lib64/python2.7/config/ -D INSTALL_PYTHON_EXAMPLES=ON ..

2) Go to the makefile and replace the locations headers (i.e. *_INC) appropriately and compile file.

3) Run toy.py with python2.7 (i.e., $ python2.7 toy.py). If you seegsu
 processed.png all should be fine.
