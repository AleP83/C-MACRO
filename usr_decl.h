//
//  usr_decl.h
//  C-MACRO
//
//  Created by Alessandro Peri on 16/03/2020.
//  Copyright © 2020 Alessandro Peri. All rights reserved.
//

#ifndef usr_decl_h
#define usr_decl_h

typedef double REAL;

// Definitions of the state space

// Capital Grid
const int NKGRID = 10;  // Size of capital grid
const REAL KMIN = 0.01; // Minimum of the capital grid
const REAL KMAX = 100.; // Maximum of the capital grid


// Declaration
typedef struct{
    
    // 1. Environment Parameters
    // 1.2. Preferences Parameters
    REAL beta; // Subjective Discount Factor
    REAL sigma; // Arrow-Pratt Coefficient of Relative Risk Aversion - IMRS
    
    // 1.3. Technology Parameters
    REAL alpha; // DRTS parameter
    REAL delta; // Depreciation rate
    
    // 2. Grids
    REAL *kgrid; // Capital Grid
    REAL *V;     // Value Function
    REAL *V0;    // Value Function Guess
    int  *gk;    // Policy Function
    
} Parms_type;


#endif /* usr_decl_h */
