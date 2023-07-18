#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

bool is_par(char check)
{
    return (check == '(');
}

bool is_curly(char check)
{
    return (check == '{');
}

bool is_box(char check)
{
    return (check == '[');
}

bool are_pair(char a, char b)
{
    if (( a == '(') && (b == ')'))
    {
        return true;
    }
    else if (( a == '{') && (b == '}'))
    {
        return true;
    }
    else if (( a == '[') && (b == ']'))
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool Check_Balanced(string input)
{
    stack<char> S;
    for (int i=0; input[i]!='\0'; i++)
    {  
        char in = input[i];
        if (is_par(in) || is_curly(in) || is_box(in))
        {
            S.push(in);
        }
        else if ((in == '}') || (in == ')') || (in == ']'))
        {
            if (are_pair(S.top(), in))
            {
                S.pop();
            }
            else
            {
                return false;
            }

        }
    }

    if (S.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main ()
{
    string inp;
    cout<<"Enter a sequence of brackets: '{}' or '[]' or '()' "<< endl;
    cin>> inp;
    bool output = Check_Balanced(inp);
    cout<< output;
    // cout<<inp[1];



}