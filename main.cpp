#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main() {
    // Armadillo testing
    cout << "Armadillo:" << endl;

    // // Matrix mul:
    // mat A(4, 5, fill::randu);
    // mat B(4, 5, fill::randu);
    // cout << A << "*" << endl << B.t() << "=" << endl;
    // cout << A*B.t() << endl;

    // // Vec
    // cx_rowvec x(10, fill::ones);
    // cx_rowvec n(10, fill::randu);
    // cout << x << "+" << endl << n << "=" << endl << x+n << endl;

    // Complex symbols
    vec data_re = sign(randn(16))/sqrt(2);
    vec data_im = sign(randn(16))/sqrt(2);
    cx_vec data(data_re, data_im);
    cout << data << endl;

    // Indices and elements
    imat RA(8, 7, fill::zeros);
    cx_mat RE(8, 7, fill::zeros);
    RA(span(2, 5), span(0, 2)).fill(1);    
    RA(span(2, 5), span(3, 6)).fill(2);    
    cout << RA << endl;
    uvec idx_cc = find(RA == 1);
    RE.elem(idx_cc).fill(cx_double(1.0, 1.0)/sqrt(2.0));
    uvec idx_dc = find(RA == 2);
    RE.elem(idx_dc) = data;
    cout << idx_dc << endl << RE << endl;

    // IFFT and FFT
    // TODO: ifftshift and fftshift?!
    cx_vec TD = ifft(RE.col(0), 8);
    cout << TD << endl;
    cx_vec FD = fft(TD, 8);
    cout << FD << endl;

    cx_vec RE_sh = shift(RE.col(0), 4); // This is not ifftshift?!
    cout << RE_sh << endl;

    // ...
    return 0;
}
