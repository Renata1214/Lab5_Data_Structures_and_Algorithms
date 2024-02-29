#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <cctype>
#include "polish.h"

using namespace std;

//Function to evaluate postfix expressions
int evaluate_postfix (string expression){
    char c;
    int number;
    int operand1;
    int operand2;
    int sizeString=0;
    stack <int> mystack;

    while (sizeString!= expression.size()){
        c=expression[sizeString];
        //cout << "Alright" << endl;
        if (isdigit(c)){
            number = c - '0';
            mystack.push(number);
        }
        else if (c=='*'||c=='/'||c=='+'||c=='-'||c=='%'||c=='^'){
            operand1=mystack.top();
            mystack.pop();
            operand2=mystack.top();
            mystack.pop();
            switch (c) {
                case '^':
                    number= pow(operand2, operand1);
                    mystack.push(number);
                    break;
                case '*' :
                    number= operand1*operand2;
                    mystack.push(number);
                    break;
                case '/':
                    number= operand2/operand1;
                    mystack.push(number);
                    cout << "enters /" << number << endl;
                    break;
                case '%':
                    number=operand2%operand1;
                   mystack.push(number);
                    break;
                case '+':
                    number=operand2+operand1;
                    mystack.push(number);
                    break;
                case '-':
                    number=operand2-operand1;
                    mystack.push(number);
                    break;
                default:
                    break;
            }
        }
        sizeString++;
    }
    return mystack.top();
}