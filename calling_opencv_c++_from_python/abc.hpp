#ifndef ABC_HPP
#define ABC_HPP

#include <Python.h>
#include <string>

class ABC
{
	public:
  // Other declarations 
    ABC();
    ABC(const std::string& someConfigFile);
    //virtual ~ABC();
    PyObject* doSomething(PyObject* image); // We want our python code to be able to call this function to do some processing using OpenCV and return the result.
  // Other declarations
};

#endif
