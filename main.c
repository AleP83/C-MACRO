#include <stdio.h>

typedef double REAL;
typedef double distribution[15];
typedef struct{
    double V[25];
    double gk[25];
    int a;
} agents;


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
    
    
    
    
    return 1;
    
}
