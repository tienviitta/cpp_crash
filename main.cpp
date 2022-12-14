#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main() {

    cout << "Armadillo:" << endl;

    mat A(4, 5, fill::randu);
    mat B(4, 5, fill::randu);

    cout << A << "*" << endl << B.t() << "=" << endl;

    cout << A*B.t() << endl;

    return 0;
}
