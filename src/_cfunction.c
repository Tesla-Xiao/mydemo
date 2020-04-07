#include <Python.h>
#include "cfunction.h"
#include <numpy/arrayobject.h>

static PyObject *py_mycfunc(PyObject *self, PyObject *args) {
    
    PyObject *py_x, *py_y;
    double number_a;
    int number_b;
    char *array_c;

    if (!PyArg_ParseTuple(args,"OOdis", &py_x, &py_y, &number_a, &number_b, &array_c)) {
        return NULL;
    }

    // Interpret the input objects as numpy arrays with contiguous storage. 
    PyObject *py_x_array = PyArray_FROM_OTF(py_x, NPY_DOUBLE, NPY_IN_ARRAY);
    PyObject *py_y_array = PyArray_FROM_OTF(py_y, NPY_INT, NPY_IN_ARRAY);

    // If that didn't work, throw an exception. 
    if (py_x_array == NULL || py_y_array== NULL ) {
        Py_XDECREF(py_x_array);
        Py_XDECREF(py_y_array);
        return NULL;
    }

    // Dimensions.
    int nx, px, ny;
    nx = (int)PyArray_DIM(py_x_array, 0);
    px = (int)PyArray_DIM(py_x_array, 1);
    ny = (int)PyArray_DIM(py_y_array, 0);

    // Exception Handling
    if ( nx !=  ny ) {
        PyErr_SetString(PyExc_ValueError, "Dimensions don't match!!");
        return NULL;
    }

    if ( strcmp(array_c, "cos") != 0 && strcmp(array_c, "sin") != 0) {
        PyErr_SetString(PyExc_TypeError, "Only support cos function and sin function now.");
        return NULL;
    }

    // Get pointers to the data as C-types.
    double *x = (double*) PyArray_DATA(py_x_array);
    int    *y = (int*)    PyArray_DATA(py_y_array);

    // Create an output array.
    double *c_output;
    c_output = (double*)malloc(sizeof(double)*2);

    // Call the external C function.
    mycfunc( x, y, number_a, number_b, array_c, c_output );


    // Create a numpy array and return it.
    npy_intp dims[1] = {2};
    PyObject *ret = PyArray_SimpleNewFromData(1, dims, NPY_DOUBLE, c_output);

    // Clean up. 
    free(c_output);
    Py_DECREF(py_x_array);
    Py_DECREF(py_y_array);

    return ret;
}

/* Documentations */
static char module_docs[] = "Some thing about your module.";

static char cfunction_docs[] = "Some thing about your C function.";


/* Module method table */
static PyMethodDef MydemoMethods[] = {
  {"mycfunc",  py_mycfunc, METH_VARARGS, cfunction_docs},
  /* If your extension module has many export functions, you need write interfaces for each of them. */
  /* And then add them to Module method table. For example: */
  /* {"mycfunc2",  py_mycfunc2, METH_VARARGS, cfunction2_docs}, */
  { NULL, NULL, 0, NULL}
};

/* Module structure */
static struct PyModuleDef demomodule = {
    PyModuleDef_HEAD_INIT,
    "Demo",           /* name of module */
    module_docs,        /* Doc string (may be NULL) */
    -1,                 /* Size of per-interpreter state or -1 */
    MydemoMethods       /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC PyInit_Demo(void) {
    PyObject *object = PyModule_Create(&demomodule);
    if(object == NULL) {
        return NULL;
    }
    import_array();
    return object;
}