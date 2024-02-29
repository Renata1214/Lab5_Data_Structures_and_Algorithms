#include <iostream>
#include <cmath>
#include <stack>
#include <cctype>
#include <string>
#include "translate.h"

using namespace std;

string translation (string infix1){

    string line; //postfix line
    char charac;
    int iterator=0;
    int number;
    stack <char> mystack;

    while (iterator!= infix1.size()){
       charac=infix1[iterator];
        if (isdigit(charac)){
            line+=charac;
        }
        else {
            if(charac=='(' || charac==')'){
                if(charac=='('){
                    mystack.push(charac);
                }
                else{
                    while (mystack.top()!='(') {
                    line += mystack.top();
                     mystack.pop();
                    }
                    mystack.pop();   
                }
            }

            if(charac=='^'){
                bool check=true;
                while (check){
                    if (!mystack.empty() && mystack.top()=='^'){
                        line += mystack.top();
                        mystack.pop();
                    }
                    else {
                        mystack.push(charac);
                        check = false;
                    }
                }
            }

            if(charac=='*' || charac == '/' || charac == '%'){
                bool check=true;
                while (check){
                    if (!mystack.empty()&&(mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'|| mystack.top()=='^')){
                        line += mystack.top();
                        mystack.pop();
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
                    if (!mystack.empty()&&(mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'|| mystack.top()=='+'|| mystack.top()=='-'|| mystack.top()=='^')){
                             line += mystack.top();
                            mystack.pop();
                    }
                    else {
                            mystack.push(charac);
                            check2 = false;
                    }
                    }
            }          
        }
        iterator ++;
    }

    while (!mystack.empty()) {
        line += mystack.top();
        mystack.pop();
    }
    return line;
}


void translate_evaluate () {
    string infix_expression;
    cout << "Write down the infix expression" << endl;
    while (cin >> infix_expression && infix_expression != "end") {
        string postfix_expression = translation(infix_expression);
        int result = evaluate_postfix(postfix_expression);

        cout << "Your line was: " << infix_expression << endl;
        cout << "Postfix expression is: " << postfix_expression << endl;
        cout << "Your result is: " << result << endl;
        cout << "Enter another infix expression or type 'end' to stop: ";
    }

    cout << "End of input. Exiting the loop." << endl;
}
