#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        vector<int> a;
        int numCount = 0;
        int result = 0;
        int isPositive = 1;
        int signCount = 0;
        for(int i = 0; i < str.size(); i++)
        {
            char c = str.at(i);
            if(c >= '0' && c <= '9')
            {
                if(c != '0' || a.size() != 0)
                {
                    a.push_back((int)(c & 0x0F) * isPositive);
                }
                numCount++;
                
            }
            else if (numCount == 0)
            {
                if(c == '-' || c == '+')
                {
                    if(c == '-')
                    {
                        isPositive = -1;
                    }else{
                        isPositive = 1;
                    }
                    
                    signCount += 1;
                    if(signCount > 1)
                    {
                        return 0;
                    }
                }else if(c == ' '){
                    if(signCount != 0)
                    {
                        return 0;
                    }else if(numCount != 0)
                    {
                        break;
                    }
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        numCount = a.size();

        if(numCount == 0)
        {
            return 0;
        }
        if(numCount > 10)
        {
            if(isPositive > 0)
            {
                return INT32_MAX;
            }else{
                return INT32_MIN;
            }
        }
        
        for(int i = 0; i < numCount; i++)
        {
            int n = a[i];
            if (i == 0 && abs(n) > 2 && numCount == 10)
            {
                if(n > 0)
                {
                    return INT32_MAX;
                }else{
                    return INT32_MIN;
                }
            }
            int s = powf(10, numCount - 1 - i);
            int v = n * s;

            if (isPositive > 0)
            {
                if (INT32_MAX - v < result)
                {
                    return INT32_MAX;
                }
            }
            else
            {
                if (INT32_MIN - v > result)
                {
                    return INT32_MIN;
                }
            }
            result += v;
        }
        return result;
    }
};

int main()
{
    Solution *s = new Solution();
    int result = s->myAtoi("  0000000000012345678");
    cout << "result = " << result << endl;
    getchar();
    return 0;
}