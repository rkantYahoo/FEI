//
// Created by Ravi on 10/31/16.
//

#include <fstream>
#include <iostream>
#include "Function.h"
using namespace std;

typedef vector<bool> BVec;

Function::Function(string inFile) {
    ifstream inStream(inFile);
    if (! inStream.is_open())
        return;

    dSize_ = 0;
    vSize_ = 0;

    double val;
    while (inStream >> val) {
        f_.push_back(val);
        F_.push_back(val);
        dSize_++;
    }
    float currSize = dSize_;
    int size = 1;
    while (currSize > 1) {
        vSize_++;
        currSize /= 2;
        size = size * 2;
    }
    for (int i = dSize_; i < size; ++i) {
        f_.push_back(0);
        F_.push_back(0);
    }

    dSize_ = size;

}

template<typename T>
void printVec(const vector<T> &v, const string &tag, const string &delim = " ", ostream &oH = cout) {
    oH << tag;
    for (const auto &t:v)
        oH << delim << t;

    oH << endl << flush;
}

bool nextInput(BVec *vec) {
    BVec &v = *vec;
    int index = v.size() - 1;
    while ((index >= 0) && (v[index])) {
        v[index] = false;
        --index;
    }

    if (index >= 0) {
        v[index] = true;
        return true;
    }

    return false;
}

Function::Function(function<double (const BVec&)> f, int numVar){
    vSize_ = numVar;
    BVec currInput(numVar, false);
    f_.push_back(f(currInput));
    F_.push_back(f(currInput));
    dSize_ = 1;
    while (nextInput(&currInput)) {
        f_.push_back(f(currInput));
        F_.push_back(f(currInput));
        dSize_++;
    }
}

void Function::PrintF() const {
//    cout << vSize_ << "\t" << dSize_ << endl << flush;
    for (const auto &t:F_)
        cout << t << "\t";
    cout << endl << flush;
}

void Function::Printf() const {
    cout << vSize_ << "\t" << dSize_ << endl << flush;
    for (const auto &t:f_)
        cout << t << "\t";
    cout << endl << flush;
}

void Function::transform(int chunkSize) {
    for (int i = 0; i < dSize_; i += 2*chunkSize) {
        for (int j = i; j < i + chunkSize; ++j)
            F_[j] += F_[j + chunkSize];

        for (int j = i + chunkSize; j < i + 2*chunkSize; ++j)
            F_[j] = F_[j - chunkSize] - 2*F_[j];
    }
}

void Function::Transform() {
    for (int i = 1; i < dSize_; i = 2*i) {
        transform(i);
        // PrintF();
    }

    for (int i = 0; i < dSize_; ++i)
        F_[i] = F_[i]/dSize_;
}