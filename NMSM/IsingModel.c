#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define parameters used in the simulation
#define SIZE 25 // lattice size
#define TEMP 3.4 // Temperature
#define J_INTERACTION 1 // interaction constant
#define STEPS 10000 // Total steps for the simulation


void random_s(){
	time_t t;
	srand((unsigned) time(&t));
}


void random_state(int *state, int N){
    /*
    Initialize the spin lattice

    state: array with spins
    N = L^d: total number of spins
    */
   for(int i = 0; i < N; i++){
    if(rand() % 2 == 0){
        state[i] = 1;
    }
    else{
        state[i] = -1;
    }
   }
}

int d_energy(int *state, int i, int j, int L, int J_){
    /*
    Compute the energy change when performed a flip

    state: array with spins
    i,j: coordinates of the lattice site where the spin flip is done
    L: size of the lattice
    J_: interaction
    */
   int left = (j-1 + L) % L; // Mod L for boundary conditions
   int right = (j+1) % L;
   int up = (i-1 + L) % L;
   int down = (i+1) % L;

   int nn_sum = state[up*L + j] + state[down*L + j] + state[i*L + left] + state[i*L + right]; // Nearest neighbors constibution
   return 2*state[i*L + j]*J_ * nn_sum;
}

void glauber_flip(int *state, int i, int j, int L, int J_, double T){
    /*
    Single spin flip according to Glauber dynamics

    state: array with spins
    i,j: coordinates of the lattice site where the spin flip is done
    L: size of the lattice
    J_: interaction
    T: temperature of the system
    */
    double beta = 1.0/T;
    int deltaE = d_energy(state, i, j, L, J_);
    double criteria = exp(-beta*deltaE);
    if (deltaE < 0 || ((double)rand() / RAND_MAX) < criteria){
        state[i*L + j] *= -1;
    }
}

void MC_Ising(int *state, int L, double T, int J_, int steps){
    /*
    Run the simulation 

    state: array with spins
    L: lattice size
    T: temperature
    J_ interaction
    steps: total steps of the simulation
    */
    FILE* file = fopen("ising_model_simultaion.txt", "w");
    for(int step = 0; step < steps; step++){
        int i = rand() % L;
        int j = rand() % L;

        if(step % 100 == 0){ // Save cofiguration every 100 steps
            fprintf(file, "step: %i \n", step);
            for(int ii = 0; ii < L; ii++){
                for(int jj = 0; jj < L; jj++){
                    fprintf(file, "%d ", state[ii*L + jj]);
                }
                fprintf(file, "\n");
            }
        }

        glauber_flip(state, i, j, L, J_, T);
    }
    fclose(file);
}

void print_actual_state(int *state, int L){
    /*
    Print state for debugging

    state: array with spins
    L: lattice size
    file: file where the configuration will be saved
    */
    for(int i = 0; i < L; i++){
        for(int j = 0; j < L; j++){
            printf("%d ", state[i*L + j]);
        }
        printf("\n");
    }
}

int main(){
    int lattice[SIZE][SIZE]; // 2D lattice
    int *state = &lattice[0][0]; // pointer to start the lattice

    random_state(state, pow(SIZE,2));
    MC_Ising(state, SIZE, TEMP, J_INTERACTION, STEPS);

    //save_actual_state(state, SIZE);
    return 0;
}
