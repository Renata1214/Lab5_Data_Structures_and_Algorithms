#include <iostream>
#include <cmath>
#include <stack>
#include <cctype>
#include <string>
#include "translate.h"

using namespace std;

/*Your program must be able to handle the following operations: +,-,*,/,%
 BNF (Backus–Naur form)1 of the infix expression grammar is:
expr ::= term | expr op1 term
op1 ::= + | -
term ::= number | term op2 number
op2 ::= * | / | %
*/
//Function to translate code infix into postfix
string translate::translation (string infix1){

    string line; //postfix line
    char charac;
    int iterator=0;
    int number;
    stack mystack;

    while (iterator!= infix1.size()){
       charac=infix[iterator];
        if (isdigit(charac)){
            line.append(charac);
        }
        else {
            if(charac=='*' || charac == '/' || charac == '%'){
                bool check=true;
                while (check){
                    if (mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'){
                        line.append(mystack.top());
                        mystack.pop;
                        }
                    else {
                        mystack.push(charac);
                        check = false;
                    }
                }
            }
            if(charac=='+' || charac == '-'){
                bool check2=true;
                    while (check2){
                        if (mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'|| mystack.top()=='+'|| mystack.top()=='-'){
                            line.append(mystack.top());
                            mystack.pop;
                            }
                        else {
                            mystack.push(charac);
                            check2 = false;
                        }
                    }
            }
                    
        }
    }
    return line;
}

void translate::translate_evaluate () {
    string infix_expression;
    cout << "Write down the infix expression" << endl;
    while (getline(cin, infix_expression)){
       int result= evaluate_postfix ( translation (infix_expression));
        cout << "Your line was " << infix_expression<< endl;
        cout << "Your result is " << result << endl;
        cout << "Press end of character to stop inputting expressions" << endl;
    }
}