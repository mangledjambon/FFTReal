#include <iostream>
#include "./fft/FFTReal.h"
#define SIZE 8
#define SCALE 0.1

/*
 *  main.cpp
 *  Sean Breen R00070693 16/04/2015
 *  Nimbus
 *
 *  This program is to compute the fast fourier transform on
 *  an array of real numbers, then compute the inverse transform
 *  on the transformed array.
 *
 *  The original array should be identical to the array after performing
 *  the inverse transform.
 */

using std::cout;
using std::endl;
using namespace ffft;

void computeFFT(float destinationArray[]);
void computeIFFT(float destinationArray[]);
void displayResults(float results[]);

int main() {

    float x[SIZE] = {0.70154f, -2.0518f, -0.35385f, -0.82359f, -1.5771f, 0.50797f, 0.28198f, 0.03348f};   //array of real values (time domain)

    cout << "Original array: " << endl;
    displayResults(x);

    ffft::FFTReal<float> fftReal ((long)8);     //create FFTReal object

    float fft_ans[SIZE];                        //array to hold values post-fft
    fftReal.do_fft(fft_ans, x);                 //compute fft, put new values in our array
    //fftReal.rescale(fft_ans);                   //rescale data (not needed after fft)

    cout << "After fft: " << endl;              //display results in frequency domain
    displayResults(fft_ans);

    float ifft_ans[SIZE];                       //cretae array to hold values after inverse fft
    fftReal.do_ifft(fft_ans, ifft_ans);         //compute inverse fft
    fftReal.rescale(ifft_ans);

    /*
     * This data may need post-scaling to retrieve
     *  the correct results. After performing inverse fft,
     *  data should be the same as our original array of values
     */

    cout << "After ifft: " << endl;             //display results in time domain
    displayResults(ifft_ans);

    return 0;
}

void displayResults(float results[]){           //display values from float array

    for(int i =0; i < SIZE; i++){
        cout << results[i] << " ";
    }
    cout << endl;

}