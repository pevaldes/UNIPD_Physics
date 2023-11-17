#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void random_s(){
	time_t t;
	srand((unsigned) time(&t));
}

double direct_samplig(int N){
    // Sampling points in the unitary disk considering r = xi1 and theta = 2.pi.xi2
    // With xi1, xi2 random numbers in [0,1]

    /*
    Function parameters:
        N: number of iterations
    */ 
    double xi1, xi2;
    double r, theta;
    double x,y;
    int i = 0;
    double pi = 4*atanf(1.);

    FILE* file = fopen("direct_sampling_disk.txt", "w");
    fprintf(file,"r;theta;x;y\n");
    while(i<N){
        xi1 = (rand() % 1000000)/1000000.;
        xi2 = (rand() % 1000000)/1000000.;

        r = xi1;
        theta = 2*pi*xi2;
        x = r*cos(theta);
        y = r*sin(theta);

        fprintf(file,"%lf;%lf;%lf;%lf\n", r, theta, x,y);
        i++;
    }

    fclose(file);
    printf("Pi value = %lf\n", pi);
}


double transform_coord(double r, int N){
    double x, y;
    double xi1, xi2;
    double dr, theta;
    int i = 0;
    double pi = 4*atanf(1.);

    FILE* file = fopen("transform_sampling.txt", "w");
    fprintf(file, "r;theta;x;y\n");
    while(i<N){
        xi1 = (rand() % 1000000)/1000000.;
        xi2 = (rand() % 1000000)/1000000.;

        dr = sqrt(xi1);
        theta = 2*pi*r*xi2;
        x = dr*cos(theta);
        y = dr*sin(theta);

        fprintf(file, "%lf;%lf;%lf;%lf\n", dr, theta,x,y);
        i++;
    }
    fclose(file);
    printf("Completed");
    
}

double main(int argn, char **argc){
	int N = 1000;
	
	direct_samplig(N);
    transform_coord(1,N);
}