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

string translation (string infix1){

    string line; //postfix line
    char charac;
    int iterator=0;
    int number;
    stack <char> mystack;

    while (iterator!= infix1.size()){
       charac=infix1[iterator];

        if (isdigit(charac)){
            line.append(1, charac);
        }
        else {
            if(charac=='*' || charac == '/' || charac == '%'){
                bool check=true;
                while (check){
                    //cout << "while loop" << endl;
                    if(mystack.empty()){
                        mystack.push(charac);
                        check = false;
                    }
                    else if (mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'){
                        //cout << "It is entering here" << endl;
                        char tostring = mystack.top(); 
                        string charString(1, tostring); 
                        line.append(charString);
                        //cout << line << "okay" << endl;
                        mystack.pop();
                        }
                    else {
                        //cout << "Enter" << endl;
                        mystack.push(charac);
                        check = false;
                    }
                }
            }
            if(charac=='+' || charac == '-'){
                bool check2=true;
                    while (check2){
                    if(mystack.empty()){
                        mystack.push(charac);
                        check2 = false;
                    }
                        else if (mystack.top()=='/'|| mystack.top()=='%'|| mystack.top()=='*'|| mystack.top()=='+'|| mystack.top()=='-'){
                            char tostring = mystack.top(); 
                            string charString(1, tostring); 
                            line.append(charString);
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

    // do
    // {
    //     cout << "Write down the infix expression" << endl;
    //     cin>>infix_expression;
    //     //cout << "error" << endl;
    //     string something = translation (infix_expression);
    //     //cout << something << endl;
    //    // cout << "error" << endl;
    //     //int result = evaluate_postfix(infix_expression);
    //     int result= evaluate_postfix (something);
    //     cout << "Your line was " << infix_expression<< endl;
    //     cout << "Your result is " << result << endl;
    //     cout << "Press end of character to stop inputting expressions" << endl;
    // }while(infix_expression!=eof());
}
