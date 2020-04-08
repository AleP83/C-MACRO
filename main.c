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
    
    
    FILE *fp; // Pointer to a File! Store address to FILE in your HD
    
    fp = fopen("/Users/alessandroperi/GoogleDrive/BOULDER/Teaching/Macroeconomics-1-Phd/C-Programming/C-MACRO/C-MACRO/README.txt","r"); // Getting the Address
    // fopen(Address of the File,'Mode of Opening') define in stdio
    // Mode of Opening: read(r) write (w), append(a)
    if(fp==NULL){
        printf("Imbecil you made a mistake!");
        exit(-1);
    }
    
    double a;
    fscanf(fp,"%lf",&a);
    
    printf("What is the number: %lf\n",a);
    
    fprintf(stdout,"What is the number print it on screen: %lf\n",a);
    
    
    fclose(fp);
    return 1;
}

