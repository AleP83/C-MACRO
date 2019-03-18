//
//  macro_library.h
//  C-MACRO
//
//  Created by Alessandro Peri on 11/03/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//

#ifndef macro_library_h
#define macro_library_h

#include <stdio.h>

#define NK 10
const int NN =50;

typedef double * POINTERFORDUMMY;
typedef double REAL;
typedef double distribution[15];
typedef struct{
    double V[NK];
    double gk[NK];
    int a;
} agents;

typedef int capitalgrid[NK];


#endif /* macro_library_h */
