#include <iostream>
#include "./classes/Function.h"
using namespace std;

typedef vector<bool> BVec;

double majority(const BVec &v) {
    int numPos = 0;
    for (const auto &t:v)
        numPos += (t)? 1:0;

    if (numPos >= v.size()/2.0)
        return -1;

    return 1;
}

int main() {
    cout << "Hello, World!" << endl;
//    Function f("/Users/ravi/Fourier/and2");

    clock_t startTime = clock();
    Function f((function<double (const BVec&)>) majority, 25);
//    f.Printf();
    clock_t genTime = clock();
    cout << "genTime = " << (genTime - startTime)/CLOCKS_PER_SEC << endl << flush;

    f.Transform();
    clock_t transTime = clock();
    cout << "transTime = " << (transTime - genTime)/CLOCKS_PER_SEC << endl << flush;

//    f.PrintF();
    return 0;
}