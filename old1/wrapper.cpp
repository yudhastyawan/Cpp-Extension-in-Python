#include "Python.h"
#include "hello.cpp"

const char * hello();

static PyObject * hello_wrapper(PyObject * self, PyObject * args)
{
    const char * input;
    const char * result;
    PyObject * ret;
    if (!PyArg_ParseTuple(args, "s", &input)) {
        return NULL;
    }
    result = hello(input);
    ret = PyBytes_FromString(result);
    return ret;
}

static PyMethodDef HelloMethods[] = {
    {"hello", hello_wrapper, METH_VARARGS},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hello_definition = {
    PyModuleDef_HEAD_INIT,
    "hello",
    "A Python module extension for C++ lib",
    -1,
    HelloMethods
};

PyMODINIT_FUNC PyInit_hello(void) {
    Py_Initialize();
    return PyModule_Create(&hello_definition);
}
