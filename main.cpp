#include <iostream>
#include "./classes/Function.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Function f("/Users/ravi/Fourier/and2");
    f.Printf();

    f.Transform();
    f.PrintF();
    return 0;
}