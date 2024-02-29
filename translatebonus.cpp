#include <iostream>
#include <cmath>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

//Function to evaluate postfix expressions
int evaluate_postfix (string expression){
    char c;
    int number;
    int operand1;
    int operand2;
    int sizeString=0;
    int numberoperands=0;
    int numberoperations;
    bool negativenumbers=false;
    stack <int> mystack;

    while (sizeString!= expression.size()){
        c=expression[sizeString];
        //cout << "Alright" << endl;
        if (isdigit(c)){
            number = c - '0';
            mystack.push(number);
            numberoperands++;
        }
        else if (c=='*'||c=='/'||c=='+'||c=='-'||c=='%'||c=='^'){
            numberoperations++;
            if (mystack.empty()){
                cout << "You have an error. Your stack is empty, no operands to access" << endl; 
            }
            else{
                 operand1=mystack.top();
                mystack.pop();

                //Handling negative numbers 
                if (mystack.empty()&&c=='-'){
                operand2=mystack.top();
                mystack.pop();
                cout << "You are dealing with a negative number" << endl
            }
            else if (mystack.empty()){
                out << "You have an error. Your stack does not have enough operands to access" << endl; 
            }
            else{
                 operand2=mystack.top();
                 mystack.pop();
            }
            }
           
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

        else if (c!=" "){
             cout << "You entered the following unknown character " << c << endl;
        }

        sizeString++;
    }

    if ((numberoperations==numberoperands-1 || numberoperands<numberoperations) && negativenumbers==false){
        cout << "Your expression has an unbalanced number of operands and operations" << endl;
        throw "The function will give wrong result"
    }

    return mystack.top();
}

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

            else if(charac=='^'){
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

            else if(charac=='*' || charac == '/' || charac == '%'){
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
            else if(charac=='+' || charac == '-'){
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
            else {
                cout << "You entered an invalid character" << endl;
            }       
        }
        iterator ++;
    }

    for (char a :line ){
        if (a=='('){
            cout << "You never closed the parenthesis" << endl;
        }
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
