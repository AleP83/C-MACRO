//
//  InitializationParams.c
//  C-MACRO
//
//  Created by Alessandro Peri on 18/03/2019.
//  Copyright © 2019 Alessandro Peri. All rights reserved.
//
#include<stdlib.h>
#include <stdio.h>
#include "usr_decl.h"

void InitializationParms(Parms_type *Parms_){
    printf("Check if working!\n");
    
    FILE *fp;
    fp = fopen("/Users/alessandroperi/GoogleDrive/BOULDER/Teaching/Macroeconomics-1-Phd/C-Programming/C-MACRO/C-MACRO/parameters.txt","r");
    if(fp==NULL){
        printf("\nFailure in reading the parameters\n");
        exit(-1);
    }
    else{
        printf("\nSuccess in reading the parameters\n");
    }
    
    double v[N_PARMS];
    /*
    fscanf(fp,"%lf",&v[0]);
    printf("The %d element of the parameters is %lf\n",1,v[0]);
    fscanf(fp,"%lf",&v[1]);
    printf("The %d element of the parameters is %lf\n",2,v[1]);
    rewind(fp);
    fscanf(fp,"%lf",&v[0]);
    printf("The %d element of the parameters is %lf\n",1,v[0]);
    rewind(fp);
    */
    int i=0;
    while(fscanf(fp,"%lf",&v[i]) == 1){
        i=i+1;
    }
    if(i==N_PARMS)
    {
        printf("Bingo: We read all the parameters: Total %d\n",i);
    }
#ifdef SHOWPARAMETERS
    rewind(fp);
    printf("\n");
    for(int i=0;i<N_PARMS;i++)
    {
        printf("v[%d]=%lf\n",i,v[i]);
    }
#endif
    
    // Check there are enough parameters
    i=0;
    
    // ****************************
    Parms_->alpha=v[i];i++;
    Parms_->beta=v[i];i++;
    Parms_->delta=v[i];i++;
    Parms_->gamma=v[i];i++;
    Parms_->r=v[i];i++;
    Parms_->toll_dV=v[i];
    // ****************************
    
    fclose(fp);
    
    
}

void PrintParms(Parms_type *Parms_){
    
printf("alpha: %lf\n",Parms_->alpha);
printf("beta: %lf\n",(*Parms_).beta);
printf("delta: %lf\n",Parms_->delta);
printf("gamma: %lf\n",Parms_->gamma);
printf("r: %lf\n",Parms_->r);
printf("toll_dV: %lf\n",Parms_->toll_dV);
}
