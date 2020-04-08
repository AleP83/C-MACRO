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
    REAL *wealth;// Wealth Grid
    
    // 3. Convergence tolerance
    REAL TOLL_V;
    
    
    REAL *V;     // Value Function
    REAL *V0;    // Value Function Guess
    int  *Gk;    // Policy Function
    
} Parms_type;


// STEP 1. Declaration of Functions
// RETURN_TYPE Function_ID(Input Arguments)
// RETURN_TYPE Function_ID(TYPE_1 Variable_ID_1,TYPE_2 Variable_ID_2)
//void InitializationW(Parms_type *);
void InitializationW(Parms_type *Parmsaddr_){
    
    //wealth = kα + (1 − δ)k;
    // Parmsaddr->wealth Go to the address in Parmsaddr and access (->) the field wealth
    printf("Print Wealth Grid");
    for(int ik = 0;ik < NKGRID;ik++){
        Parmsaddr_->wealth[ik] = pow(Parmsaddr_->kgrid[ik],Parmsaddr_->alpha)+(1. - Parmsaddr_->delta)*Parmsaddr_->kgrid[ik];
        printf("W: %5.3lf k %5.3lf\n",Parmsaddr_->wealth[ik],Parmsaddr_->kgrid[ik]);
    }
    //Parmsaddr_->kgrid = &Parmsaddr_->kgrid[0]
    printf("\n");
}


void InitializationV(Parms_type *Parmsaddr_){
    
    //wealth = kα + (1 − δ)k;
    // Parmsaddr->wealth Go to the address in Parmsaddr and access (->) the field wealth
    printf("Print Value Function\n");
    for(int ik = 0;ik < NKGRID;ik++){
        Parmsaddr_->V0[ik] = Parmsaddr_->wealth[ik]; //1./(1.-Parmsaddr_->sigma)*pow(Parmsaddr_->wealth[ik],1-Parmsaddr_->sigma);
    }
    //Parmsaddr_->kgrid = &Parmsaddr_->kgrid[0]
    printf("\n");
}







#endif /* usr_decl_h */
