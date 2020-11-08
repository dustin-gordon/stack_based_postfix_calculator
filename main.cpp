/* 
 * Dustin Gordon
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <climits>
#include <stack>
#include "myStack.h"
using namespace std;


int main()
{
    cout << "***************************************************************** " << endl;
    cout << "**                   Postfix Mini Calculator                   ** " << endl;
    cout << "***************************************************************** " << endl;
    cout << endl << "\t\t\t (Enter '?' at any time for verbose help)" << endl;

    myStack<int> stack;  //Declare stack from template
    char input;          //User input
    bool flag = true;    //For looping main
    int numCounter = 0;  //For tracking number of elements in the stack
    int opCounter = 0;

    while(true)
    {
        while(flag)
        {
            cout << endl << "* Enter your input: " << endl;
            cin >> input; //Capture user input

            //Help command:
            if(input == '?')
            {
                cout << endl;
                cout << "*****************************************************************" << endl;
                cout << "*\t \t \t \t \t \t \tWelcome!                            *"        << endl;
                cout << "*****************************************************************" << endl;
                cout << "- This is a calculator for postfix format, wherein the operands "  << endl;
                cout << "  proceed the operators. (ie: '1 2 +' = 3; '2 4 *' = 8; etc...) "  << endl << endl;
                cout << "- Input two numbers you wish to calculate one by one, by typing "  << endl;
                cout << "  a single digit number then pressing Enter."                      << endl << endl;
                cout << "- Next, input the operator you wish to use in the calculation. "   << endl;
                cout << "  Operators:  + (add);  - (subtract);  * (multiply);  / (divide);" << endl << endl;
                cout << "- Type 'c' to calculate result and return answer. "                << endl;
                cout << "- Type 'H' to halt (exit) the program. "                           << endl;
                cout << "*****************************************************************" << endl << endl;
                flag = false;
            }

            //Halt command:
            else if(input == 'H')
            {
                cout << endl;
                cout << "***************************************************************** " << endl;
                cout << "**                     Program Terminated.                     ** " << endl;
                cout << "***************************************************************** " << endl;
                return 0;
            }

            //Calculate command:
            else if(input == 'c')
            {
                if(numCounter == 0)
                {
                    cout << endl << "ERROR! The stack is empty. Please enter your operand inputs before calculating." << endl;
                }
                else
                {
                    cout << endl << "Result = '" << stack.pop() << "'." << endl;

                    //Clear the stack:
                    numCounter--;
                    for(int i = 1; i <= numCounter; i++)
                    {
                        stack.pop();
                    }
                    numCounter = 0;
                }
                flag = false;
            }

            //Skip space characters:
            else if(isspace(input))
            {
                continue;
            }

            //Handle Operator input:
            else if((input == '+') || (input == '/') || (input == '-') || (input == '*'))
            {
                if(numCounter == 0)
                {
                    cout << endl << "ERROR! Please enter your operands (numbers) before entering your operator." << endl;
                }
                else if(opCounter > 1)
                {
                    cout << endl << "ERROR! An operator has already been entered. Type 'c' to calculate answer." << endl;
                }
                else
                {
                    char op = input;
                    //Declare temporary variables outside scope of switch case:
                    int subtrahend1;
                    int subtrahend2;
                    int dividend;
                    int divisor;

                    switch(op)
                    {
                        case '+':   //Add operands
                            stack.push(stack.pop() + stack.pop());
                            cout << endl << "Applied addition operator '+' to the stack." << endl;
                            numCounter--;
                            break;

                        case '-':   //Subtract operands
                            subtrahend2 = stack.pop();
                            subtrahend1 = stack.pop();
                            stack.push(subtrahend1 - subtrahend2);
                            cout << endl << "Applied subtraction operator '-' to the stack." << endl;
                            numCounter--;
                            break;

                        case '*':   //Multiply operands
                            stack.push(stack.pop() * stack.pop());
                            cout << endl << "Applied multiplication operator '*' to the stack." << endl;
                            numCounter--;
                            break;

                        case '/':   //Divide operands
                            divisor = stack.pop();
                            dividend = stack.pop();
                            stack.push(dividend / divisor);
                            cout << endl << "Applied division operator '/' to the stack." << endl;
                            numCounter--;
                            break;
                    }
                }
            }

            //Handle Number input:
            else if((input == '0') || (input == '1') || (input == '2') || (input == '3') || (input == '4') ||
                    (input == '5') || (input == '6') || (input == '7') || (input == '8') || (input == '9'))
            {
                int num = input - '0';
                if((num >= 0) && (num <= 9))
                {
                    stack.push(num);
                    cout << endl << "Added integer '" << num << "' to the stack." << endl;
                    numCounter++;
                }
            }

            //Handle Invalid input:
            else
            {
                cout << endl << "ERROR! Invalid input. Enter '?' for help." << endl;
                //Flush the buffer:
                while ((getchar() != '\n'))
                {
                    stack.pop();
                }

                //Clear the stack:
                if(numCounter > 0)
                {
                    for(int i = 1; i <= numCounter; i++)
                    {
                        stack.pop();
                    }
                    numCounter = 0;
                }
                flag = false;
            }
        }

        flag = true; //Continue looping main method until user halts program.
    }
}

