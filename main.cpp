#include <iostream>
#include "./fft/FFTReal.h"
#define SIZE 8

/*
 *  main.cpp
 *  Sean Breen R00070693 16/04/2015
 *  Nimbus Researcher
 *
 *  This program is to compute the fast fourier transform on
 *  an array of real numbers, then compute the inverse transform
 *  on the transformed array.
 *
 *  The new array should be identical to the original array after
 *  performing the inverse transform.
 *
 *  It makes use of Laurent de Soras' FFTReal program.
 *
 *  FFTReal is distributed under the terms of the Do
 *  What The Fuck You Want To Public License.
 *
 */

using std::cout;
using std::endl;
using namespace ffft;

/*
 * TODO: go to lunch
 *
 * */

void computeFFT(float destinationArray[], float sourceArray[]);
void displayResults(float results[]);
ffft::FFTReal<float> fftReal ((long)8);     //create FFTReal object

int main() {

    float x[SIZE] = {0.70154f, -2.0518f, -0.35385f, -0.82359f, -1.5771f, 0.50797f, 0.28198f, 0.03348f};   //array of real values (time domain)

    cout << "Original array: " << endl;
    displayResults(x);

    ffft::FFTReal<float> fftReal ((long)8);     //create FFTReal object

    float fft_ans[SIZE];                        //array to hold values post-fft
    computeFFT(fft_ans, x);                    //compute fft, put new values in our array

    cout << "After fft: " << endl;              //display results (frequency domain)
    displayResults(fft_ans);

    float ifft_ans[SIZE];                       //create array to hold values after inverse fft
    fftReal.do_ifft(fft_ans, ifft_ans);        //compute inverse fft
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

void computeFFT(float destinationArray[], float sourceArray[]){

    fftReal.do_fft(destinationArray, sourceArray);

}

void displayResults(float results[]){           //display values from float array

    for(int i =0; i < SIZE; i++){
        cout << results[i] << " ";
    }
    cout << endl << endl;

}