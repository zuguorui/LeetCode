#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if(nums.size() == 0)
    {
        return 0;
    }
    // vector<int>::iterator it = nums.end() - 1;
    // while(it > nums.begin())
    // {
    //     if(*it == *(it - 1))
    //     {
    //         it = nums.erase(it);
    //     }
    //     it--;
    // }
    // return nums.size();

    int len = nums.size();
    int sIndex = 0;
    int eIndex = sIndex + 1;
    while(eIndex < len)
    {
        if((nums[sIndex] != nums[eIndex]))
        {
            nums[sIndex + 1] = nums[eIndex];
            sIndex++;
        }
        eIndex++;
    }
    return sIndex + 1;
}

int main()
{
    int k[] = {0,0,1,1,1,2,2,3,3,4};
    int kLen = 10;
    vector<int> input;
    for(int i = 0; i < kLen; i++)
    {
        input.push_back(k[i]);
    }
    int newLen = removeDuplicates(input);
    cout << "newLen = " << newLen << endl;
    for(int i = 0; i < newLen; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}

