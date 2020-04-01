#include <stdio.h>
#include <stdlib.h> // Malloc
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
    
    InitializationV(&Parms_); // Initialization of Value function
    
    
    Parms_.TOLL_V = 1e-10;
    
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
    
    return 1;
    
}

