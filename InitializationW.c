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
    
    const int n = NK;
    
#ifdef SHOWW
    printf("Print our wealth matrix: \n");
#endif
    for(int i=0;i<n;i++){
        W[i]=pow(K[i],Parms_->alpha)+(1.-Parms_->delta)*K[i];
#ifdef SHOWW
        printf("%lf ",W[i]);
#endif
    }
#ifdef SHOWW
    printf("\n");
#endif
    
}
