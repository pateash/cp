//
// Created by ashish on 26/1/18.
//
#ifndef SAMPLE_CALCULATOR_H
#define SAMPLE_CALCULATOR_H

#include "../CommonLibs.h"

// CALCULATOR without support for '(' and ')'

// Helper function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix expression to postfix
vector<string> infixToPostfix(const string &s) {
    stack<char> operators; // this will store current operators which hasn't been moved to postfix yet
    vector<string> postfix; // final postfix
    string numberBuffer; // To handle multi-digit numbers

    for (char c: s) {
        if (isdigit(c)) { // Handle multi-digit numbers
            numberBuffer.push_back(c); // if digit then keep adding to buffer
        } else {
            if (!numberBuffer.empty()) { // add this number to postfix
                postfix.push_back(numberBuffer);
                numberBuffer.clear();
            }
            if (isspace(c)) continue; // Skip spaces
            // if this sign
            // add all operators which have more precedence that this to postfix
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix.push_back(string(1, operators.top()));
                operators.pop();
            }
            // just push this to stack
            operators.push(c);
        }
    }
    // add any remaining number to postfix
    if (!numberBuffer.empty()) {
        postfix.push_back(numberBuffer);
    }
    // add remaining operators
    while (!operators.empty()) {
        postfix.push_back(string(1, operators.top()));
        operators.pop();
    }
    return postfix;
}

// Evaluate postfix expression
int evaluatePostfix(const vector<string> &postfix) {
    stack<int> values;

    // postfix will store string, so while number will be one string
    for (const string &token: postfix) {
        if (isdigit(token[0])) { // Check if the token is a number, push to stack
            values.push(stoi(token)); // Convert string to integer and push onto stack
        } else { // Operator
            // as soon as you find operator, pop 2 and evaluate
            int right = values.top();
            values.pop(); // first value is right
            int left = values.top();
            values.pop();
            switch (token[0]) {
                case '+':
                    values.push(left + right);
                    break;
                case '-':
                    values.push(left - right);
                    break;
                case '*':
                    values.push(left * right);
                    break;
                case '/':
                    values.push(left / right);
                    break;
                default:
                    assert(false); // this should not come, invalid operator
            }
        }
    }
    return values.top();
}

int calculate(string &expression) {
    vector<string> postfix = infixToPostfix(expression);
    return evaluatePostfix(postfix);
}

void testCalculatorUtils() {
    string expression = "1 + 2 * 3 - 4 / 4";
    assert(calculate(expression) == 6);
    expression = "1 + 2 * 3 - 4";
    assert(calculate(expression) == 3);
}

#endif
