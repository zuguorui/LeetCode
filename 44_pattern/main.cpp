#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
#include <memory.h>

using namespace std;

bool isMatch(string s, string p)
{
    if(s.compare(p) == 0)
    {
        return true;
    }
    int sLen = s.size();
    int pLen = p.size();
    
    
    int8_t dp[pLen + 1][sLen + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= sLen; i++)
    {
        dp[0][i] = 0;
    }
    for(int pCount = 1; pCount <= pLen; pCount++)
    {
        memset(dp[pCount], 0, (sLen + 1)  * sizeof(char));
        for(int sCount = 0; sCount <= sLen; sCount++)
        {
            if(p.at(pCount - 1) == '*')
            {
                char r = 0;
                for(int k = sCount; k >= 0; k--)
                {
                    r = r | dp[pCount - 1][k];
                    if(r == 1)
                    {
                        break;
                    }
                }
                dp[pCount][sCount] = r;
            }
            else
            {
                if(sCount == 0)
                {
                    dp[pCount][sCount] = 0;
                    continue;
                }
                dp[pCount][sCount] = dp[pCount - 1][sCount - 1] & (s.at(sCount - 1) == p.at(pCount - 1) || p.at(pCount - 1) == '?');
            }
            
        }
    }


    return dp[pLen][sLen] == 1;
}

int main()
{
    string s = "ab";
    string p = "?*";
    bool b = isMatch(s, p);
    printf("%d\n", b);
    getchar();
}
