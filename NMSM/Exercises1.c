/*
List of exercises No.1
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void random_s(){
	time_t t;
	srand((unsigned) time(&t));
}

double rectangle(int a, int b, int c, int d, int N){
	// Rectangle with dimensions [a,b]x[c,d] and N "throws"	
	
	int i = 0;
	double A1, A2; // Random numbers
	double x, y; 
	int n = 0; // Hits
	double I; // Approximation integral
	
	FILE* file = fopen("rectangle.txt", "w");
	fprintf(file, "X(%i,%i); Y(%i,%i)\n", a,b,c,d);
	while(i<N){
		A1 = (rand() % 1000000)/1000000.;
		A2 = (rand() % 1000000)/1000000.;
		x = (a+(b-a)*A1);
		y = (d-c)*A2;
		fprintf(file, "%lf; %lf\n", x, y);

		if((y+c) <= d && (y+c) >= c){ // Condition function
			n++;
		}
		i++;		
	}
	fclose(file);
	I = n*(b-a)*(d-c)/N;
	printf("Rectangle area = %lf, n = %i\n",I,i);
}

double disk(double r, int N){
	// Disk with radius r centered at (0,0) and N "throws"
	
	int i = 0;
	double A1, A2; // Random numbers
	double x, y; 
	int n = 0; // Hits
	double I; // Approximation integral
	
	FILE* file = fopen("disk_numbers.txt", "w");
	fprintf(file, "X; Y\n");
	while(i<N){
		A1 = (rand() % 1000000)/1000000.;
		A2 = (rand() % 1000000)/1000000.;
		x = r*A1;
		y = r*A2;
		fprintf(file, "%lf; %lf\n", x, y);

		if(pow(x,2) + pow(y,2) <= r){ // Condition function
			n++;
		}
		i++;
	}
	fclose(file);

	I = 4*n*r*r/N;
	printf("Unit radius disk area = %lf, n = %i\n", I,n);
}

double* power_law_dist_inversion(int n, int a, int N){
	// Random numbers accoording to the power law probability distribution
	
	/* 
	n = power
	a = upper limit
	*/
	int i;
	double dist[N];
	double xi, x; 

	for(i = 0; i < N; i++){
		xi = (rand() % 1000000)/1000000.;
		double prod = pow(a,n+1)*xi;
		double power = 1.0/(n+1);
		x = pow(prod,power);
		dist[i] = x;
	}
	/*int loop;
	for(loop = 0; loop < N; loop++){
		printf("%lf ", dist[loop]);
		printf("\n");
	}*/
	
		
	
	FILE* file = fopen("distribution.txt","w");
	int loop;
	for(loop = 0; loop < N; loop++){
		fprintf(file, "%lf;", dist[loop]);
	}
	fclose(file);
}


double main(int argn, char **argc){
	int N = 100000;
	
	/* Sampling random points within D-dimensional domains by hit and miss */
	rectangle(2,4,2,4,N);
	disk(1,N);
	
	/* Sampling random numbers from a given distribution (Inversion method) */
	
	//power_law_dist_inversion(2,2,N);
}