#include <stdio.h>
#include <stdlib.h> // Malloc
#include <math.h>
//typedef double REAL;

int main(){
    
    int i= 1;
    
    if(1){
        i=2;
        printf("What is i inside the brackets: %d\n",i);
    }
    
    printf("What is i outside the brackets: %d\n",i);
    
    if(1){
        int i=3;
        printf("What is i inside the second brackets: %d\n",i);
    }
    
    printf("What is i after the second bracket: %d\n",i);
    
    
    
    return 1;
}

