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
    
    
    
    
    // Free the memory (otherwise LEAKS error)
    free(Parms_.kgrid);
    
    return 1;
    
}

