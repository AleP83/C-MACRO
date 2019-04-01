//
//  InitializationK.c
//  C-MACRO
//
//  Created by Alessandro Peri on 18/03/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//

#include <stdio.h>
#include "usr_decl.h"
#include <math.h>

void InitializationW(REAL *W,REAL *K,Parms_type *Parms_){
    
    // Define kmin and kmax
    REAL kss;
    kss = pow(1./Parms_->alpha*(1./Parms_->beta-(1-Parms_->delta)),1./(Parms_->alpha-1.));
    
    REAL KMIN, KMAX;
    KMIN = 0;
    KMIN = 100;
    switch (K_MODE) {
        case 0:
            KMIN = 0;
            KMAX = 100;
            break;
            
        case 1:
            KMIN =alpha_shrink_kss * kss;
            KMAX =alpha_expand_kss * kss;
            break;
    }
    
    // Spread them apart
    const int n = NK;
    REAL deltap = (KMAX-KMIN)/((double) (n-1.));
    //printf("\n");
    //printf("delta = %lf",delta);
    // Define the capital grid
    //printf("\n");
#ifdef SHOWK
    printf("\n");
    for(int i=0;i<n;i++){
        K[i]=KMIN+i*deltap;
        printf("%lf ",K[i]);
    }
    printf("\n");
#endif
    
    
    
}
