//
// Created by Eduardo_Ribeiro on 24/04/2020.
//

#ifndef POLISHREVERSECALCULATOR_POLISHREVERSECALCULATOR_H
#define POLISHREVERSECALCULATOR_POLISHREVERSECALCULATOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <iterator>
#include <map>
#include <functional>
#include <stack>

using namespace std;

class PolishReverseCalculator
{
public:
    PolishReverseCalculator();
    ~PolishReverseCalculator();

    int calc(const string& input) const;

private:
    bool isOperator(const string& item) const;
    map<string, function<int(int, int)>> operators;
    function<int(int, int)> getOperation(const string& item) const;
};

#endif //POLISHREVERSECALCULATOR_POLISHREVERSECALCULATOR_H
