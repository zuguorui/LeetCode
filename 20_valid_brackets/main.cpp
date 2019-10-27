#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

bool isValid(string s) {
    stack<char> sf;

    for(int i = 0; i < s.length(); i++)
    {
        char a = s.at(i);
        if(a == '{' || a == '(' || a == '[')
        {
            sf.push(a);
        }else if(a == '}' || a == ')' || a == ']'){
            if(sf.empty())
            {
                return false;
            }
            char b = sf.top();
            sf.pop();
            if((b == '(' && a == ')') || (b == '{' && a == '}') || (b == '[' && a == ']'))
            {
                continue;
            }else{
                return false;
            }
        }
    }

    return sf.empty();
}

int main()
{
    string s = "()";
    bool result = isValid(s);
    cout << result << endl;
    return 0;
    
}