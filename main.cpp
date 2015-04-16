#include <iostream>
#include "./fft/FFTReal.h"
#define SIZE 8

//class to compute FFT using generic programming

using std::cout;
using std::endl;
using namespace ffft;

void do_fft();

int main() {

    float x[SIZE] = {2.3f, 4.5f, 0.546f, 2.3415f, 1.21312314f, 0.0f};

    cout << "Original array: " << endl;

    for(int i =0; i < SIZE; i++){
        cout << x[i] << " ";
    }
    cout << endl;


    ffft::FFTReal<float> fftReal ((long)8);
    float fft_ans[SIZE];
    fftReal.do_fft(fft_ans, x);
    fftReal.rescale(fft_ans);

    cout << "After fft: " << endl;
    for(int i =0; i < SIZE; i++){
        cout << fft_ans[i] << " ";
    }
    cout << endl;

    float ifft_ans[SIZE];
    fftReal.do_ifft(fft_ans, ifft_ans);
    fftReal.rescale(ifft_ans);

    cout << "After ifft: " << endl;
    for(int i =0; i < SIZE; i++){
        cout << ifft_ans[i] << " ";
    }
    cout << endl;

    return 0;
}