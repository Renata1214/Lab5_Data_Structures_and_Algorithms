#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                case '%':
                    operands.push(operand1 % operand2);
                    break;
                default:
                    cerr << "Invalid operator: " << c << endl;
                    return 1;
            }
        }
    }

    return operands.top();
}


int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard the '('
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// int main() {
//     string expression;
//     while (getline(cin, expression)) {
//         cout << infixToPostfix(expression) << endl;
//     }

//     return 0;
// }


int main() {
    string expression;
    while (getline(cin, expression)) {
        string result = infixToPostfix(expression);
        cout << result << endl;
        cout << evaluatePostfix(result) << endl;
    }

    return 0;
}
