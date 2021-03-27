//
// Created by Eduardo_Ribeiro on 24/04/2020.
//

#include "PolishReverseCalculator.h"

PolishReverseCalculator::PolishReverseCalculator()
{
    operators.insert(make_pair("+", [](int a, int b) { return a+b; }));
    operators.insert(make_pair("-", [](int a, int b) { return a-b; }));
    operators.insert(make_pair("*", [](int a, int b) { return a*b; }));
    operators.insert(make_pair("/", [](int a, int b) { return a/b; }));
}

PolishReverseCalculator::~PolishReverseCalculator() = default;

int PolishReverseCalculator::calc(const string &input) const
{
    stack<int> stack;
    istringstream iss(input);
    string::size_type stype;
    vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        if (isOperator(*it)) {
            auto operation = getOperation(*it);

            auto b = stack.top();
            stack.pop();

            auto a = stack.top();
            stack.pop();

            int result = operation(a, b);
            stack.push(result);
        } else {
            stack.push(stoi(*it, &stype));
        }
    }

    return stack.top();
}

bool PolishReverseCalculator::isOperator(const string& item) const {
    return operators.find(item) != operators.end();
}

function<int(int, int)> PolishReverseCalculator::getOperation(const string &item) const {
    return operators.find(item)->second;
}
