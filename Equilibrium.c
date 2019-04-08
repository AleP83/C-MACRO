//
//  Equilibrium.c
//  C-MACRO
//
//  Created by Alessandro Peri on 03/04/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "usr_decl.h"

int Equilibrium(Agents_type *Ri_,Grids_type *Grids_,Parms_type *Parms_){
    
    // Contraction Mapping
    int nk = NK;
    for(int ik=0;ik<nk;ik++)
    {
        
        // Value Function iteration Step
        // Compute Updated V
        REAL wealth = Ri_->W[ik];
         for(int ikp=0;ikp<nk;ikp++)
         {
             REAL kp = Grids_->K[ikp];
             REAL cons = wealth - kp;
             REAL ret_func;
             if(cons<0)
                 ret_func = -9999999999999.99;
             else
             {
                 ret_func = (pow(cons,1.-Parms_->gamma)-1.)/(1.-Parms_->gamma);
             }
             
             REAL obj_func = ret_func + Parms_->beta * Ri_->V0[ikp];
             
         }
        
        
        // Metric: V - V0
        
        // Update of V with V0
    }
    
    
    return 0;
}
