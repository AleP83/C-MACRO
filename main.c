#include <stdio.h>
#include "usr_decl.h"

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
#ifdef SHOWPARAMETERS
    PrintParms(&Parms_);
#endif
    // Initialization of Capital Grid
    REAL K[NK],W[NK];
    InitializationK(&K[0],&Parms_);
    // Initialization of Wealth Function
    InitializationW(&W[0],&K[0],&Parms_);
    
    // Initialization of Value Function
    
    
    
    
    
    
    return 1;
    
}
