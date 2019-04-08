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

void InitializationV(REAL *V,REAL *W,Parms_type *Parms_){
    
    int nk = NK;
    
#ifdef SHOWV
    printf("Print our Value Function matrix: \n");
#endif
    for(int i=0;i<nk;i++){
        V[i]=W[i];
#ifdef SHOWV
        printf("%lf ",V[i]);
#endif
    }
#ifdef SHOWV
    printf("\n");
#endif

    
    
}
