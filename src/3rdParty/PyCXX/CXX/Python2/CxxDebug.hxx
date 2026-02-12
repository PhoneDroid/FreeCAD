// SPDX-FileCopyrightText: 2008 Barry A. Scott

//
//  CxxDebug.hxx
//
//
#ifndef __CXX_Debug_hxx
#define __CXX_Debug_hxx

//
//  Functions useful when debugging PyCXX
//
#ifdef PYCXX_DEBUG
extern void bpt();
extern void printRefCount( PyObject *obj );
#endif

#endif
