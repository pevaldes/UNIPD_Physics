#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void random_s(){
	time_t t;
	srand((unsigned) time(&t));
}


//int **random_state(int L, int d){
    /* 
    L = lenght of the space
    d = dimension
    N = L^d, the number of spins
    *//*
   int **state;
   int N = pow(L,d);
   int i, j;
   for(i=0;i<L;i++){
    for(j=0;j<L;j++){
        double num = (rand() % 1000000)/1000000.;
        if(num >= 0.5){
            state[i][j] = 1;
        }
        else{
            state[i][j] = -1;
        }
    }
   }
   return state;
}
*/
double main(int argn, char **argc){
    
    int L = 10;
    int d = 2;
    int row, columns;
    // int initialState[L][L];
    
   int state[L][L];
   int N = pow(L,d);
   int i, j;
   for(i=0;i<L;i++){
    for(j=0;j<L;j++){
        double num = (rand() % 1000000)/1000000.;
        if(num >= 0.5){
            state[i][j] = 1;
        }
        else{
            state[i][j] = -1;
        }
    }
   }

    for(row=0;row<L;row++){
        for(columns=0;columns<L;columns++){
            printf("%d   ", state[row][columns]);
        }
        printf("\n");
    }
}