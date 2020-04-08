#include <stdio.h>
#include <stdlib.h> // Malloc
#include <math.h>
#include "usr_decl.h"
//typedef double REAL;

int main(){
    
    // Define 
    Parms_type Parms_;
    
    // Allocate Memory
    // Allocate capital grid
    Parms_.kgrid = (REAL *) malloc(NKGRID*sizeof(REAL));
    // malloc: allocates memory in the HEAP (why? because STACK might not be sufficient) -- STACK OVERFLOW
    // how much? NKGRID points of size REAL
    // Once it allocates the memory -> give me the address to that chunk of memory: ^&GSFT&767f76 -> address to memory with REAL
    // Parms_.kgrid = address to that memory
    printf(" Address of Capital Grid is %p\n", Parms_.kgrid);
    
    // Define the Parameters
    Parms_.sigma = 2;    // CRRA
    Parms_.delta = .1;   // Depreciation
    Parms_.alpha = 0.65; // DRTS parameter
    Parms_.beta  = 0.9615; // Annual Subj Discount Factor
    
    
    // Define the Capital Grid
    REAL stepk = (KMAX - KMIN) / ((REAL) NKGRID-1);
    
    printf("\n");
    for(int ik = 0;ik < NKGRID;ik++){
        // Initialization
        Parms_.kgrid[ik] = KMIN + stepk*ik;
        printf("k[%d] = %5.2lf\n",ik,Parms_.kgrid[ik]);
    }
    
    // Initialization of the Wealth:  kα + (1 − δ)k
    // 1. Declare the Wealth Array
    Parms_.wealth = (REAL *) malloc(NKGRID*sizeof(REAL));
    // Parms_.wealth: Go to the cupboard and access the field wealth
    
    // STEP 2. Call of the function
    InitializationW(&Parms_); // Initialization of Wealth function
    
    // Value Function Iteration Algorithm
    Parms_.V0 = (REAL *) malloc(NKGRID*sizeof(REAL));
    Parms_.V  = (REAL *) malloc(NKGRID*sizeof(REAL));
    Parms_.Gk = (int *) malloc(NKGRID*sizeof(int));
    
    InitializationV(&Parms_); // Initialization of Value function
    
    
    Parms_.TOLL_V = 1e-10;
    
    
    REAL metric = 1.;
    
    int iter_dV = 0;
    while(metric > Parms_.TOLL_V){
        
        // VFI Iteration Step
        
        REAL max_distance = -1.7977e+300; // Sup Norm: Max Distance between V1 and V0
        
        // Iterate over the State
        for(int ik=0;ik<NKGRID;ik++){
            
            // Peak Finding: grid search: given k, evaluate objective function at every k' and pick the max
            REAL obj_func_max = -1.7977e+300;
            int ikpstar  = 0;
            
            for(int ikp=0;ikp<NKGRID;ikp++){
                // Compute objective function for (k,k')
                
                REAL consumption = Parms_.wealth[ik] - Parms_.kgrid[ikp];   // c = w(k) - k'
                REAL ret_func = pow(consumption,1.-Parms_.sigma)/(1.-Parms_.sigma);  // c^(1-sigma)/(1-sigma) = (wealth - k')^(1-sigma)/(1-sigma)  (c>0)
                
                // Continuation Value V(k')
                REAL cont_value = Parms_.beta * Parms_.V0[ikp];
                
                // Objective Function (k,k')
                REAL obj_func = ret_func + cont_value;
                
                if(consumption < 0)
                    obj_func = -1.7977e+300;
                
                
                if(obj_func>obj_func_max)
                {
                    obj_func_max = obj_func;
                    ikpstar = ikp;
                }
                
            } // ikp control variable
            
            // Store Maximizers
            Parms_.V[ik]  = obj_func_max;
            Parms_.Gk[ik] = ikpstar;
            
            // Update the Metric
            REAL distance = fabs(Parms_.V[ik] - Parms_.V0[ik]);
            if(distance>max_distance)
                max_distance = distance;

            // Update the Value Function
            Parms_.V0[ik] = Parms_.V[ik];
            
        } // ik: state variable
        
        // Berge Max Theory: V0 e Cb -> T will map V0 into V1 which is Cb
        // T: have to prove is a contraction: Blackwell Suff Conditions
        // Contraction Mapping: will ensure that (V1,V0) cauchy
        // keep iterating what happen at the limit -> continuity might be lost
        // Then: USE supnorm
        
        // Update the Metric
        metric = max_distance;
        
        iter_dV++;
        
        printf("Iteration n. %d\n", iter_dV);
        
    }
    
    printf("Value Function:\n");
    for(int ik=0;ik<NKGRID;ik++){
        printf("%lf ", Parms_.V[ik]);
    }
    printf("\n");
    printf("Policy Functions:\n");
    for(int ik=0;ik<NKGRID;ik++){
        printf("When the index on the capital state is %d I choose index %d\n",ik,Parms_.Gk[ik]);
    }
    
    
    
    /*
    REAL metric = 1000000000;
    
    while(metric>Parms_.TOLL_V){
        
        
        // 1. Value Function Iteration Step
        // V1 = T (V0)
        
        // First For loop over capital state
        //V1[k] = T (V0)
        for(int ik = 0;ik < NKGRID;ik++){
            
            REAL wealth = Parms_.wealth[ik];
            
            for(int ikp = 0;ikp < NKGRID;ikp++){
                
                REAL kprime = Parms_.kgrid[ikp];
                
                // Objective Function
                // 1. Return Function
                REAL cons = wealth - kprime;
                // CRRA utility
                pow(cons,);
                
                
                //  Non negativity constraint here
                
                // 2. Continuation Value
                
                
                
                
            }
            
            // Second For Loop: Peak Finding algorithm: Find the maximum
            
            
        }
        
            // Second For Loop: Peak Finding algorithm: Find the maximum
            
        
        
        // Update Metric:
        // metric = rho(V1,V0);
        
        
    }
    
    */
    
    
    
    // Free the memory (otherwise LEAKS error)
    free(Parms_.kgrid);
    free(Parms_.wealth);
    free(Parms_.V);
    free(Parms_.V0);
    free(Parms_.Gk);
    
    return 1;
    
}

