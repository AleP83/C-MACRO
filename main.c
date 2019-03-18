#include <stdio.h>
#include "usr_decl.h"

typedef double REAL;

int main(){
    
    // Declare Parameter STructure
    Parms_type Parms_;
    /*
    Parms_.beta  = 0.96;
    Parms_.alpha = 0.3;
    Parms_.delta = 0.1;
    Parms_.r     = 0.04;
    Parms_.gamma = 2;
    */
    InitializationParms(&Parms_);
    printf("\n");
    PrintParms(&Parms_);
    
    // Initialization of Capital Grid
    REAL K[NK];
    InitializationK(&K[0]);
    // Initialization of Value Function
    
    // Initialization of Wealth Vector
    
    
    
    
    return 1;
    
}
