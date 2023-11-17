#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void random_s(){
	time_t t;
	srand((unsigned) time(&t));
}

double rejection(double p, int N){
    double pi = 4*atan(1.);
    int i = 0;
    double rho, g;
    double ratio;
    double A;
    double xi, c;
    double x,y;
    double distg[N], distfx[N], distfy[N];

    A = 2*p/(2*pow(p,2) + 1);
    
    for(i = 0; i < N; i++){
        xi = (rand() % 1000000)/1000000.;
        c = (rand() % 1000000)/1000000.;
        x = sqrt( -log( (-2*p/A) * exp(-pow(p,2)) * (xi-A*p-A/(2*p)) ) ); // Random number according to g
        rho = sqrt(2/pi)*exp(-pow(x,2)); // f
        if(x>p){
            g = (A/p)*x*exp(pow(p,2) - pow(x,2));
        }
        else{
            g = A;
        }
        ratio = rho/g;
        if(xi>ratio){
            distg[i] = x; // Accept values according to the rejection method
        }
        y = xi*g;
        if(y<rho){ // Accept the points y<rho to sample values according to rho
            distfx[i] = x;
            distfy[i] = y;
        }
    }

    FILE* file = fopen("rejection_sampling_p1", "w");
    fprintf(file,"x;y\n");
    int loop;
    for(loop = 0; loop < N; loop++){
        fprintf(file, "%lf;%lf\n", distfx[loop], distfy[loop]);
    }
    fclose(file);
}

double main(int argn, char **argc){
	int N = 100000;
	
	rejection(1,N);
}