#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sperateInteger(int x, vector<int>& a, int& isPositive)
{
    int loopCount = 0;
    
    int mMod = 0;
    int mDevide = 0;
    isPositive = x >= 0 ? 1 : -1;
    do
    {
        mDevide = x / pow(10, loopCount);
        mMod = mDevide % 10;
        if (mDevide != 0)
        {
            a.push_back(mMod * isPositive);
        }

        loopCount++;
    } while (mDevide != 0 && loopCount <= 9);
}

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }
        vector<int> nums;
        int isPositive = 1;
        sperateInteger(x, nums, isPositive);
        int downPos = 0;
        int upPos = nums.size() - 1;
        bool result = true;
        while(downPos < upPos)
        {
            if(nums[downPos] != nums[upPos])
            {
                result = false;
                break;
            }
            downPos++;
            upPos--;
        }
        return result;

    }
};

int main()
{
    // int a = INT32_MAX;
    // int b = 1;
    // vector<int> c;
    // sperateInteger(a, c, b);
    // cout << "num = " << a << endl;
    // cout  << b << endl;
    // for(int i = 0; i < c.size(); i++)
    // {
    //     cout << i << ": " << c[i] << endl;
    // }

    // int a = pow(10, 4);
    // cout << a << endl;

    Solution *s = new Solution();
    int num = -2772;
    bool result = s->isPalindrome(num);
    cout << result << endl;
    getchar();
    return 0;
}