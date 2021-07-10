#include <stdio.h>
#include <Python.h>

int main() {
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/mnt/c/Users/Lenovo/Documents/projects/cpp1/old6')");

    PyObject *pModule = NULL;
    PyObject *pDict = NULL;

    pModule = PyImport_ImportModule("mymodul");
    pDict = PyModule_GetDict(pModule);

    PyObject *pFuncOne = PyDict_GetItemString(pDict, "IntListRet");
    PyObject *pFuncRet = PyObject_CallObject(pFuncOne, NULL);
    
    printf("[");
    if (PyList_Check(pFuncRet)) {
        int SizeOfList = PyList_Size(pFuncRet);
        for(int idx_i = 0; idx_i < SizeOfList; idx_i++){
            printf("[");
            PyObject *ListItem = PyList_GetItem(pFuncRet, idx_i);
            int NumOfItems = PyList_Size(ListItem);
            for (int idx_k = 0; idx_k < NumOfItems; idx_k++){
                PyObject *Item = PyList_GetItem(ListItem, idx_k);
                printf("%ld", PyLong_AsLong(Item));
                Py_DECREF(Item);
                if (idx_k != (NumOfItems-1)) {
                    printf(", ");
                }
            }
            Py_DECREF(ListItem);
            if (idx_i != (SizeOfList-1)) {
                printf("], ");
            } else {
                printf("]");
            }
        }
    }
    printf("]\n");

    Py_DECREF(pModule);
    Py_DECREF(pDict);
    Py_DECREF(pFuncOne);
    Py_DECREF(pFuncRet);
    return 0;
}