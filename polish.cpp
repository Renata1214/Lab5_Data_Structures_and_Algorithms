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
            cout << "Enters stack" << endl;
            //sizeString++;
        }
        else if (c=='*'||c=='/'||c=='+'||c=='-'||c=='%'){
             cout << "Enters stack loop" << endl;
            operand1=mystack.top();
            mystack.pop();
            operand2=mystack.top();
            mystack.pop();
            //cout  << "recognized" << endl;
            switch (c) {
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
                cout << "enter -" << endl;
                cout << operand2 << " " << operand1 << endl;
                    number=operand2-operand1;
                    cout << "the number " << number ;
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