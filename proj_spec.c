//
//  proj_spec.c
//  C-MACRO
//
//  Created by Alessandro Peri on 18/03/2020.
//  Copyright © 2020 Alessandro Peri. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "usr_decl.h"

// STEP 3. DEFINITION OF THE FUNCTION

// INITIALIZATION OF THE WEALTH FUNCTION: kα + (1 − δ)k
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
