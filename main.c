#include <stdio.h>

#define NK 1000
const int NN =50;

typedef double REAL;
typedef double distribution[15];
typedef struct{
    double V[NK];
    double gk[NK];
    int a;
} agents;

int G;
int main(){
    
    // Declare variable
    int a;
    // Output:
    // Address of the variable: &a
    // Allocate a memory of dimension int
    
    // Assignment: Var = Evalute(Expression)
    a = 5;
    printf("%d\n",a);
    //printf("Gimme a number dude:\n");
    //scanf("%d",&a);
    //printf("%c\n",a);
    a=(a<3);
    printf("%d\n",a);
    a=a+1;
    printf("%d\n",a);
    
    // built-in types
    /*
    char c;
    float f;
    double d;
    int i;
    */
    // User-defined types
    REAL df=5.5;
    printf("%lf\n",df);
    
    distribution Gamma;
    Gamma[0]=1.;
    printf("%lf\n",Gamma[0]);
    //printf("%d\n",&Gamma[0]);
    
    int A[10];
    char B[10];
    char F[10];
    
    agents Firms_;
    Firms_.a=3;
    Firms_.gk[3]=5.4;
    
    printf("%lf\n",Firms_.gk[25]);
    
    int A2[10][5];
    A2[0][1]= 4;
    printf("%d\n",A2[0][1]);
    
    // Checking the scope
    int c = 2;
    //for(;;)
    {
        int c;
        c= 25;
        
    }
    printf("%d",c);
    
    //SYNTAX for(initialization;expression;increment)
    // i=i+1 <-> i++
    //
    printf("\nInitializing Array A:\n");
    for(int i=0;i<10;i++)
    {
        A[i] = i;
        printf("%d ",A[i]);
    }
    printf("\n");
    
    // While loop
    printf("\nInitializing Array A with while:\n");
    int i=0; //initialization
    while(i<10)// expression
    {
        A[i] = A[i]+i;
        printf("%d ",A[i]);
        // Increment
        i++;
    }
    
    for(int i=0;5;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    
    return 1;
    
}
