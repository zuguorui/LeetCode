#include <iostream>
#include <stdlib.h>

using namespace std;

int longestValidParentheses(string s)
{
    int resultPairs = 0, tempPairs = 0;
    int left = 0;
    int sLen = s.size();
    char tempChar;
    bool canContinue = true;
    int tempSum = 0;
    for (int i = 0; i < sLen; i++)
    {
        tempChar = s.at(i);
        if (tempChar == '(')
        {
            left++;
        }
        else
        {
            if (left >= 1)
            {
                tempPairs++;
                left--;
                if(left == 0)
                {
                    tempSum += tempPairs;
                    tempPairs = 0;
                }
            }
            else
            {
                if (resultPairs < tempSum)
                {
                    resultPairs = tempSum;
                }
                tempSum = 0;
                tempPairs = 0;
                left = 0;
            }
        }
    }
    if(resultPairs < tempSum)
    {
        resultPairs = tempSum;
    }
    if (resultPairs < tempPairs)
    {
        resultPairs = tempPairs;
    }

    return resultPairs * 2;
}

int main()
{
    string s = "(()(((()";
    int result = longestValidParentheses(s);
    cout << result << endl;
    getchar();
}
