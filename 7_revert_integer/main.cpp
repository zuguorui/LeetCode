#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int isPositive = x >= 0 ? 1 : 0;
        vector<int> nums;
        int loopCount = 0;
        int mMod = 0;
        int mDevide = 0;
        do{
            mDevide = x / (int)(powf(10, loopCount));
            mMod = mDevide % 10;
            if (mDevide != 0)
            {
                cout << "pos " << loopCount << " value = " << mMod << endl;
                nums.push_back(mMod);
                
            }
            
            loopCount++;
        } while (mDevide != 0 && loopCount <= 9);

        int result = 0;
        int len = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int y = (int)powf(10, len - 1 - i);
            if(x >= 0)
            {
                if(INT32_MAX / y < x)
                {
                    return 0;
                }
            }else{
                if(INT32_MIN / y > x)
                {
                    return 0;
                }
            }
            int v = nums[i] * (int)powf(10, len - 1 - i);
            
            if(isPositive == 1)
            {
                if(INT32_MAX - v <= result)
                {
                    return 0;
                }
            }else{
                if(INT32_MIN - v >= result)
                {
                    return 0;
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
    int a = s->reverse(-2147483648);
    cout << "result = " << a << endl;
    getchar();
    return 0;
}