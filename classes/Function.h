//
// Created by Ravi on 10/31/16.
//

#ifndef FEI_FUNCTION_H
#define FEI_FUNCTION_H
#include <string>
#include <vector>
using namespace std;

class Function {
public:
    Function(string inFile);
    void Transform();
    void Printf() const;
    void PrintF() const;
private:
    void transform(int i);

    vector<double> f_;
    vector<double> F_;
    int dSize_;
    int vSize_;
};


#endif //FEI_FUNCTION_H
