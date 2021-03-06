#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

typedef struct {
    PyObject_HEAD
    PyObject *first;
    PyObject *last;
    int number;
} CustomObject;

static void
Custom_dealloc(CustomObject *self) {
    Py_XDECREF(self->first);
    Py_XDECREF(self->last);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
Custom_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    CustomObject *self;
    self = (CustomObject *) type ->tp_alloc(type, 0);
    if (self != NULL) {
        self->first = PyUnicode_FromString("");
        if (self->first == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->last = PyUnicode_FromString("");
        if (self->last == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->number = 0;
    }
    return (PyObject *) self;
}

static int
Custom_init(CustomObject *self, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {(char *)"first", (char *)"last", (char *)"number", NULL};
    PyObject *first = NULL, *last = NULL, *tmp;

    if (!PyArg_ParseTupleAndKeywords(args,kwds,"|OOi",kwlist,
                                    &first,&last,&self->number))
        return -1;
    
    if (first) {
        tmp = self->first;
        Py_INCREF(first);
        self->first = first;
        Py_XDECREF(tmp);
    }
    if (last) {
        tmp = self->last;
        Py_INCREF(last);
        self->last = last;
        Py_XDECREF(tmp);
    }
    return 0;
}

static PyMemberDef Custom_members[] = {
    {"first", T_OBJECT_EX, offsetof(CustomObject, first), 0, "first name"},
    {"last", T_OBJECT_EX, offsetof(CustomObject, last), 0, "last name"},
    {"number", T_INT, offsetof(CustomObject, number), 0, "custom number"},
    {NULL}
};

static PyObject *
Custom_name(CustomObject *self, PyObject *Py_UNUSED(ignored)) {
    if (self->first == NULL) {
        PyErr_SetString(PyExc_AttributeError, "first");
        return NULL;
    }
    if (self->last == NULL) {
        PyErr_SetString(PyExc_AttributeError, "last");
        return NULL;
    }
    return PyUnicode_FromFormat("%S %S", self->first, self->last);
}

static PyMethodDef Custom_methods[] = {
    {"name", (PyCFunction) Custom_name, METH_NOARGS,
     "Return the name, combining the first and last name"
    },
    {NULL}
};

static PyTypeObject CustomType = {
PyVarObject_HEAD_INIT(NULL, 0)
    "yudha.Custom",                /* tp_name */
    sizeof(CustomObject),           /* tp_basicsize */
    0,                              /* tp_itemsize */
    (destructor) Custom_dealloc,    /* tp_dealloc */
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
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "Custom objects",                   /* tp_doc */
    0,                              /* tp_traverse */
    0,                              /* tp_clear */
    0,                              /* tp_richcompare */
    0,                              /* tp_weaklistoffset */
    0,                              /* tp_iter */
    0,                              /* tp_iternext */
    Custom_methods,                              /* tp_methods */
    Custom_members,                              /* tp_members */
    0,                              /* tp_getset */
    0,                              /* tp_base */
    0,                              /* tp_dict */
    0,                              /* tp_descr_get */
    0,                              /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc) Custom_init,         /* tp_init */
    0,                              /* tp_alloc */
    Custom_new,                      /* tp_new */
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
    if (PyType_Ready(&CustomType) < 0)
        return NULL;
    
    m = PyModule_Create(&yudhamodule);
    if (m == NULL)
        return NULL;
    
    Py_INCREF(&CustomType);
    if (PyModule_AddObject(m, "Custom", (PyObject *)&CustomType) < 0) {
        Py_DECREF(&CustomType);
        Py_DECREF(m);
        return NULL;
    }
    return m;
}