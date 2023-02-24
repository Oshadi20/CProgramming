// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
//Add any necessary headers here
#include <math.h>
// user-defined header files
#include "mypcm.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
float analog_signal_generator(asignal signal, int t)
{
	//TODO
	//sinusoidal signal
	float analogSignal = signal.A * sin((signal.omega * t) + signal.sigma);
	return analogSignal;
}
void sampler(float *samples, int interval, asignal signal)
{
	//TODO
	int index; //index for samples array positions
	index = 0; //starting index
	int i;
	for(i=0; i<=signal.duration; i+=interval){
		float analogSignal = analog_signal_generator(signal, i);
		samples[index] = analogSignal;  //store the sample
		index += 1; //increment the index
	}
}
void quantizer(float *samples, int *pcmpulses, int levels)
{
	//TODO
	int Amax, Amin, time;
	Amax = pcmpulses[0]; //maximum quantization level
	Amin = -Amax; //minimum quantization level
	time = pcmpulses[1];
	int i;
	for(i=2; i<=time+2; i++){
		double Qlevel;
		Qlevel = ((samples[i-2] - Amin)/(Amax - Amin)) * levels; //Quantization logic
		int Qval = floor(Qlevel); //take the floor value as the Quantized value
		pcmpulses[i] = Qval; //store the output
	}
}
void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
	//TODO
	//produces PCM codes for each pulse as a binary number stream
	int i;
	for(i=2; i<sizeof(pcmpulses); i++){
		int binaryVal[encoderbits];
		int val = pcmpulses[i];
		int j;
		for(j=encoderbits; j>0; j--){
			binaryVal[j-1] = val % 2;
			val = val/2;
		}
		int k;
		for(k=0; k<encoderbits; k++){
			dsignal[(encoderbits*(i-2)) + k] = binaryVal[k]; //store the output
		}
		
	}
}
