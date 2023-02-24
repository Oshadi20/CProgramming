// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <math.h>
// user-defined header files
#include "mypcm.h"


// function prototypes
void run(asignal * inputsignal);


int main()
{
    asignal * inputsignal = (asignal *) malloc(sizeof(asignal));
    run(inputsignal);
    
    //call any other function here

    free(inputsignal);
	return 0;
}

void run(asignal * inputsignal) 
{
	//read inputs
	int A, omega, sigma, duration, interval, encoderbits;
	scanf("%d %d %d %d %d %d", &A, &omega, &sigma, &duration, &interval, &encoderbits);
	
	inputsignal->A = A;
	inputsignal->omega = omega;
	inputsignal->sigma = sigma;
	inputsignal->duration = duration;
	
	int countVal = (duration / interval) + 1;
	 
	//store A and duration
	int pcmpulses[countVal+2];
	pcmpulses[0] = inputsignal->A;
	pcmpulses[1] = inputsignal->duration;
	
	int levels = pow(2,encoderbits);
	
	int lengthOfBitStream = countVal * encoderbits;
	int dsignal[lengthOfBitStream];
	
	float samples[countVal];
	sampler(samples, interval, *inputsignal);
	quantizer(samples, pcmpulses, levels);
	encoder(pcmpulses, dsignal, encoderbits);
	
	int i;
	for(i=0; i<lengthOfBitStream; i++){
		printf("%d",dsignal[i]);
	}
}


