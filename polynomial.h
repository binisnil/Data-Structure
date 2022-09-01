#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <fstream>
#include <cstring>

using namespace std;

class polynomial {
private:
    int a;
    int coef[1000];
    int exp[1000];
public:
    void LoadPolynomial(string& filename) {
        ifstream fin(filename);
        fin >> a;
        for (int i = 0; i < a; i++) {
            fin >> coef[i] >> exp[i];
        }
    }
    void PrintPolynomial() {
        int i=0;
        while ( i < a - 1) {
            for (int j = i + 1; j < a; j++) {

                if (exp[i] < exp[j]) {
                    int swt1 = exp[i];
                    exp[i] = exp[j];
                    exp[j] = swt1;
                    int swt2 = coef[i];
                    coef[i] = coef[j];
                    coef[j] = swt2;
                }

            }
            i++;
        }
        for (int i = 0; i < a; i++) {
            cout << coef[i] << " " << exp[i] << endl;
        }
    }
};
#endif
