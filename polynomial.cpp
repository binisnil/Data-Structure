#include <iostream>
#include <string>
#include "polynomial.h"

using namespace std;

int main(void) {
    polynomial p;
    
    string filename;
    getline(cin, filename);
    
    p.LoadPolynomial(filename);
    p.PrintPolynomial();
    
    return 0;
}