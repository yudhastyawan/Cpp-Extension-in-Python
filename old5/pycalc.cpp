#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>
#include "myclass.h"

static PyTypeObject PynumberType = {
PyVarObject_HEAD_INIT(NULL, 0)
    "yudha.Custom",                /* tp_name */
    sizeof(PynumberType),           /* tp_basicsize */
    0,                              /* tp_itemsize */
    0,                              /* tp_dealloc */
    0,                              /* tp_vectorcall_offset */
    0,                              /* tp_getattr */
    0,                              /* tp_setattr */
    0,                              /* tp_as_async */
    0,           /* tp_repr */
    0,                              /* tp_as_number */
    0,                              /* tp_as_sequence */
    0,                              /* tp_as_mapping */
    0,                              /* tp_hash */
    0,                              /* tp_call */
    0,                              /* tp_str */
    0,                              /* tp_getattro */
    0,                              /* tp_setattro */
    0,                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                              /* tp_flags */
    "Custom objects",                   /* tp_doc */
    0,                              /* tp_traverse */
    0,                              /* tp_clear */
    0,                              /* tp_richcompare */
    0,                              /* tp_weaklistoffset */
    0,                              /* tp_iter */
    0,                              /* tp_iternext */
    0,                              /* tp_methods */
    0,                              /* tp_members */
    0,                              /* tp_getset */
    0,                              /* tp_base */
    0,                              /* tp_dict */
    0,                              /* tp_descr_get */
    0,                              /* tp_descr_set */
    0,                              /* tp_dictoffset */
    0,                              /* tp_init */
    0,                              /* tp_alloc */
    PyType_GenericNew,                      /* tp_new */
};

static PyModuleDef yudhamodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "yudha",
    .m_doc = "Example module that creates an extension type",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_yudha(void) {
    PyObject *m;
    if (PyType_Ready(&PynumberType) < 0)
        return NULL;
    
    m = PyModule_Create(&yudhamodule);
    if (m == NULL)
        return NULL;
    
    Py_INCREF(&PynumberType);
    if (PyModule_AddObject(m, "Custom", (PyObject *)&PynumberType) < 0) {
        Py_DECREF(&PynumberType);
        Py_DECREF(m);
        return NULL;
    }
    return m;
}