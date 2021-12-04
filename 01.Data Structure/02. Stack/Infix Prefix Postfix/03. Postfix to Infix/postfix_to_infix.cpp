#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string PostfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]); //postfix[i] takes char makes one copy and puts in op
           //string op = prefix[i]; ----- will give error
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return s.top();
}

int main()
{

    string infix, postfix;
    cout << "Enter a POSTFIX Expression :" << endl;
    cin >> postfix;
    cout << "POSTFIX EXPRESSION: " << postfix << endl;
    infix = PostfixToInfix(postfix);
    cout << endl
         << "INFIX EXPRESSION: " << infix;

    return 0;
}