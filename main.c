#include <stdio.h>
// typedef: is a directive to the precompiler (like #include)
// typedef: create a user defined type
// Syntax is:
// typedef DESCRIBETHETYPE TYPEIDENFITIFER
typedef double REAL;

// Definition of a type
typedef struct {
    // Fields of the structure
    double sigma; //risk aversion
    double alpha; // share to labor
    double delta; // depreciation
} Parmstype;
// Definition of a type does not create any variable!!!!


int main(){
    
    printf("Let us learn TYPEDEF, Structure and Loops\n");
    
    REAL d;
    d= 1.5;
    printf("The value in d is %f\n",d);
    
    
    
    // Create variable of type Parmstype (create house with the design Parmstype)
    Parmstype R_;
    
    // Initialization of R
    // how do we access the fields of R_?
    R_.sigma = 2.; // initialization of sigma
    R_.delta = 0.1; // initialization of delta
    R_.alpha = 0.7; // initializtion of share of output to labor
    
    REAL kgrid[6];
    kgrid[0] = 1.5;
    kgrid[2] = 2.5;
    printf("The value in k[%d] is %lf\n",0,kgrid[0]);
    int i = 2;
    // int i;
    // i=2;
    // in short int i=2;
    printf("The value in k[%d] is %lf\n",i,kgrid[i]);
    // kgrid[6] does not exist
    
    
    // There are Two Loops
    // syntax of the loop
    /*
     for (initialize first value of index; boolean expression; update index){
        SCOPE
        stuff that has to be done in each iteration of the loop
        }
    */
    int j; // index j
    // Infinite loop
    /*
    for(j=0;1;j=j+1){
        printf("Infinite loop yeah!");
    }
    */
    printf("\nFor Loop initialization of kgrid: ");
    for(j=0;j<6;j=j+1){
        kgrid[j] = j
                   +1;
        printf("%lf ",kgrid[j]);
    }
    printf("\n");
    
    
    // Address of elements of capital grid
    i = 0;
    printf("\nThe address of position %d of the capital grid is %p\n",i,&kgrid[i]);
    i = 1;
    printf("\nThe address of position %d of the capital grid is %p\n",i,&kgrid[i]);
    i = 2;
    printf("\nThe address of position %d of the capital grid is %p\n",i,&kgrid[i]);
    
    // While Loop
    printf("\n\n");
    //for(j=0;j<6;j=j+1)
    j=0;
    printf("\nWhile Loop initialization of kgrid: ");
    while(j<6){
        
        kgrid[j] = j
                   +2;
        printf("%lf ",kgrid[j]);
        
        j=j+1; // j++;
    }
    printf("\n");
    
    return 1;
    
}

