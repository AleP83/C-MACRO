#include <stdio.h>
int main(){
    
    printf("Understanding\t Variables!\n");
    // How can we define a variable
    // DEfinition syntax:
    // TYPE name_of_the_variable; (instruction)
    // TYPE: tells you how much memory you want for storing numbers in that variable
    // Variable_name: defines the name of the variable
    
    // ------------- VARIABLE DECLARATION
    // Declaration of a Char (the smallest type)
    char c; // TYPE: char (1Byte), name of the variable: c
    // By writing char c i am creating a variable of size char named c
    // Name of the variable:
        // 1. Cannot be a keyword (char char no) (char main no)
        // 2. Cannot start with a number!!!
        // 3. Case sensitive!!
    char justaname;
    
    // ------------- VARIABLE INITIALIZATION
    c = 'E';
    /* There is something called ASCI codes that translates:
    Symbols: "B"
    into numbers (bits):
    */
    printf("The variable c is initialized with the value: %c\n",c);
    printf("The variable c is initialized with the value: %d\n",c);
    printf("The address of C is: %d\n",&c);
    /*
    printf("Give me a letter: ");
    scanf("%c",&c);
    printf("The variable c is initialized with the value: %c\n",c);
    printf("The variable c is initialized with the value: %d\n",c);
    */
    
    char dollar;
    dollar = 36;
    printf("The variable dollar is initialized with the value: %c\n",dollar);
    
    
    // 2. Integers
    // Why do we like integers:
        // 1. In loops
    
    // Declaration
    int i;
    // Definition by assignment
    i = 12;
    printf("\n\n\n Let us print our first integer %d\n",i);
    i = 12.3;
    printf("Integer representation of float %d\n",i);
    i = 12.7;
    printf("Integer representation of float %d\n",i);
    
    
    
    // 3. Double
        // All the rest!
    double d;
    d= 4.0;
    printf("Double floating point %18.15lf\n",d);
    
    
    // 3. Mix Integer and Doubles
    i = 2;
    
    double result;
    result = i/d;
    printf("Result %lf\n",result);
    
    int iresult;
    iresult = i/d;
    printf("Result %lf will return 0.5\n",iresult);
    printf("Result %d will return 0\n",iresult);
    
    i=2;
    double f2= 1/i;
    // Step 1: 1 is integer, i is integer
    // Step 2: division between integers (integer division) 1/2 = 0 (0.5 but I throw away after comma)
    // Step 3: assign expression to variable f2:
        // Expression is integer 0
        // variable f2 is double
        // So assign 0 followed by .000000000000
    
    printf("Mistake: %lf is not 0.5\n",f2);
    
    double f3 = 1./i;
    printf("Implicit Conversion: %lf equals 0.5\n",f3);
    
    double f4 = 1./((double) i);
    printf("Explicit Conversion: %lf equals 0.5\n",f4);
    
    double f5 = ((double) 1)/i;
    printf("Explicit Conversion: %lf equals 0.5\n",f5);
    
    
    
    /*
    int i2 = 1/i;
    printf("Mistake: %d is not 0.5\n",i2);
    */
    
    
    // 4. Floats
    
    
    
    // DEFINE ASSIGNMENTS OPERATION
    // Assignment operator is: = ;
    // Variable = (Result of the Evaluation of an expression);
    i = (3 == 2);
    printf("Integer representation of expression %d\n",i);
    i = (1 | 0);
    printf("Integer representation of OR operation %d\n",i);
    i = (1 & 0);
    printf("Integer representation of AND operation %d\n",i);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 1;
}

