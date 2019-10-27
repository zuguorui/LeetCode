#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (vector<int>::iterator fIt = nums.begin(); fIt != nums.end() - 1; fIt++)
    {
        for(vector<int>::iterator sIt = fIt + 1; sIt != nums.end(); sIt++)
        {
            if(*fIt + *sIt == target)
            {
                result.push_back(distance(nums.begin(), fIt));
                result.push_back(distance(nums.begin(), sIt));
                return result;
            }
        }
    }
    return result;
}

int main()
{
    int k[] = {2, 7, 11, 15};
    int kLen = 4;
    vector<int> input;
    for(int i = 0; i < kLen; i++)
    {
        input.push_back(k[i]);
    }

    vector<int> result = twoSum(input, 9);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}