//
//  usr_decl.h
//  C-MACRO
//
//  Created by Alessandro Peri on 18/03/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//

#ifndef usr_decl_h
#define usr_decl_h

#define NK 100


typedef double REAL;
typedef struct {
    REAL alpha;
    REAL beta;
    REAL delta;
    REAL r;
    REAL gamma;
} Parms_type;

typedef struct {
    REAL V[NK];
    REAL V0[NK];
    REAL W[NK];
    int G[NK];
} Agents_type;
typedef struct {
    REAL K[NK];
} Grids_type;



void InitializationParms(Parms_type *);
void PrintParms(Parms_type *);
void InitializationK(REAL *,Parms_type *);
void InitializationW(REAL *,REAL *,Parms_type *);
void InitializationV(REAL *,REAL *,Parms_type *);
int Equilibrium(Agents_type *,Grids_type *,Parms_type *);

#define N_PARMS 5
#endif /* usr_decl_h */


// Capital grids definitions
static double alpha_shrink_kss= 0.9;
static double alpha_expand_kss= 1.1;
static int K_MODE = 0;
// 0 trivial: 0-100
// 1 kss steady state
//#define SHOWPARAMETERS
//#define SHOWK
//#define SHOWW
//#define SHOWV
