#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// int search(vector<int>& nums, int target) {
//     int len = nums.size();
//     if(len == 0)
//     {
//         return -1;
//     }
//     int startIndex = -1, endIndex = len;
//     for(int i = 0; i < len - 1; i++)
//     {
//         int a = nums[i], b = nums[i + 1];
//         if(a == target)
//         {
//             return i;
//         }
//         if(a > b)
//         {
//             startIndex = i + 1;
//         }
//     }
//     if(nums[len - 1] == target)
//     {
//         return len - 1;
//     }

//     if(startIndex == -1)
//     {
//         startIndex = 0;
//     }

//     int p = startIndex, oldP = endIndex;
//     while(p != oldP)
//     {
//         oldP = p;
//         p = (startIndex + endIndex) / 2;
//         int a = nums[p];
//         if(a == target)
//         {
//             return p;
//         }else if(a < target)
//         {
//             startIndex = p;
//         }else{
//             endIndex = p;
//         }
//     }
//     return -1;
// }

int search(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 0)
    {
        return -1;
    }
    int startIndex = 0, endIndex = len - 1;
    int p = startIndex, oldP = endIndex;
    int startValue = nums[startIndex], endValue = nums[endIndex];
    while (startIndex <= endIndex)
    {
        oldP = p;
        p = (startIndex + endIndex) / 2;
        int l = nums[startIndex], mid = nums[p], r = nums[endIndex];
        if (mid == target)
        {
            return p;
        }
        else if(target == l)
        {
            return startIndex;
        }
        else if(target == r)
        {
            return endIndex;
        }
        else if (mid > target) //find a smaller
        {
            if(target > l)//can only search in bigger part
            {
                endIndex = p - 1;
            }else{//can only search in smaller part
                // if(l > r)
                // {
                //     startIndex++;
                // }else{
                //     endIndex = p - 1;
                // }
                if(mid > r)
                {
                    startIndex = p + 1;
                }else{
                    endIndex = p - 1;
                }
            }
        }
        else//find a bigger
        {
            if(target < r)
            {
                startIndex = p + 1;
            }else{
                // if(l > r)
                // {
                //     endIndex--;
                // }else{
                //     startIndex = p + 1;
                // }
                if(mid < l)
                {
                    endIndex = p - 1;
                }else{
                    startIndex = p + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int k[] = {4, 5, 6, 7, 0, 1, 2};
    int kLen = 7;
    vector<int> input;
    for (int i = 0; i < kLen; i++)
    {
        input.push_back(k[i]);
    }
    int result = 0;
    for(int i = 0; i < kLen; i++)
    {
        result = search(input, k[i]);
        cout << "search " << k[i] << ", index is " << result << endl;
    }

    result = search(input, -10);
    cout << "search " << 10 << ", index is " << result << endl;
    
    return 0;
}