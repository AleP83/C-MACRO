//
//  usr_decl.h
//  C-MACRO
//
//  Created by Alessandro Peri on 18/03/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//

#ifndef usr_decl_h
#define usr_decl_h

typedef double REAL;
typedef struct {
    REAL alpha;
    REAL beta;
    REAL delta;
    REAL r;
    REAL gamma;
} Parms_type;

void InitializationParms(Parms_type *);
void PrintParms(Parms_type *);
void InitializationK(REAL *K);

#define N_PARMS 5
#define NK 100
#endif /* usr_decl_h */
