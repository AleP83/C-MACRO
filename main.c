#include <stdio.h>
#include "usr_decl.h"

int main(){
    
    // Declare Parameter STructure
    Parms_type Parms_;
    Agents_type Ri_;
    Grids_type Grids_;
    
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
    InitializationK(&Grids_.K[0],&Parms_);
    // Initialization of Wealth Function
    InitializationW(&Ri_.W[0],&Grids_.K[0],&Parms_);
    InitializationV(&Ri_.V0[0],&Ri_.W[0],&Parms_);
    
    // Initialization of Value Function
    int check = Equilibrium(&Ri_,&Grids_,&Parms_);
    
    printf("\nCheck: %d",check);
    return 0;
    
}
