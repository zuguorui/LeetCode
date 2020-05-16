#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

// int longestValidParentheses(string s)
// {
//     int resultPairs = 0, tempPairs = 0;
//     int left = 0;
//     int sLen = s.size();
//     char tempChar;
//     bool canContinue = true;
//     int tempSum = 0;
//     for (int i = 0; i < sLen; i++)
//     {
//         tempChar = s.at(i);
//         if (tempChar == '(')
//         {
//             left++;
//         }
//         else
//         {
//             if (left >= 1)
//             {
//                 tempPairs++;
//                 left--;
//                 if(left == 0)
//                 {
//                     tempSum += tempPairs;
//                     tempPairs = 0;
//                 }
//             }
//             else
//             {
//                 if (resultPairs < tempSum)
//                 {
//                     resultPairs = tempSum;
//                 }
//                 tempSum = 0;
//                 tempPairs = 0;
//                 left = 0;
//             }
//         }
//     }
//     if(resultPairs < tempSum)
//     {
//         resultPairs = tempSum;
//     }
//     if (resultPairs < tempPairs)
//     {
//         resultPairs = tempPairs;
//     }

//     return resultPairs * 2;
// }

int longestValidParentheses(string s)
{
    
    int dp[s.size()];

    const char *chars = s.c_str();
    for(int i = 0; i < s.size(); i++)
    {
        if(chars[i] == '(')
        {
            dp[i] = 0;
        }
        else
        {
            if(i <= 0)
            {
                dp[i] = 0;
            }
            else if(chars[i - 1] == '(')
            {
                if(i - 2 < 0)
                {
                    dp[i] = 2;
                }
                else
                {
                    dp[i] = dp[i - 2] + 2;
                }
                
            }
            else // chars[i - 1] == ')'
            {
                int x = i - dp[i - 1] - 1;
                if(x < 0 || chars[x] == ')')
                {
                    dp[i] = 0;
                }
                else
                {
                    int y = i - dp[i - 1] - 2;
                    if(y < 0)
                    {
                        dp[i] = dp[i - 1] + 2;
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + dp[y] + 2;
                    }
                    
                    
                }
                
            }
            
        }

        
        
    }

    int maxCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (maxCount < dp[i])
        {
            maxCount = dp[i];
        }
    }
    return maxCount;
}

int main()
{
    string s = ")()())";
    int result = longestValidParentheses(s);
    cout << result << endl;
    getchar();
}
