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
    
    double metric_dV=10;
    int iter_dV=0;
    printf("\n");
    printf("\nPrint this");
    while(metric_dV>Parms_->toll_dV)
    {
        iter_dV=iter_dV+1;
        printf("iteration n. %d\n",iter_dV);
        double spread_dV_real=-99999999.99;
        // Value Function Iteration Step
        for(int ik=0;ik<nk;ik++)
        {
            double max_obj_func = -99999999999.99;
            int ikprime = -1;
            // Value Function iteration Step
            // Compute Updated V
            REAL wealth = Ri_->W[ik];
            for(int ikp=0;ikp<nk;ikp++)
            {
                // Objectuve Function
                REAL kp = Grids_->K[ikp];
                REAL cons = wealth - kp;
                
                // Return Function
                REAL ret_func;
                if(cons<0)
                    ret_func = -9999999999999.99;
                else
                {
                    ret_func = (pow(cons,1.-Parms_->gamma)-1.)/(1.-Parms_->gamma);
                }
                
                // Objectvie Function: Ret Function + Markov Operator
                REAL obj_func = ret_func + Parms_->beta * Ri_->V0[ikp];
                if(obj_func>max_obj_func)
                {
                    max_obj_func = obj_func;
                    Ri_->G[ik] = ikp;
                }
                
            } // ikp
            // Metric: V - V0
            Ri_->V[ik] = max_obj_func;
            
            // Sup-norm
            double spread_dV =fabs(Ri_->V[ik] - Ri_->V0[ik]);
            if(spread_dV > spread_dV_real)
                spread_dV_real = spread_dV;
            // Update of V with V0
            Ri_->V0[ik] = Ri_->V[ik];
            
        } // ik
        
        metric_dV = spread_dV_real;
        
    }
    
    
    
    return 0;
}
