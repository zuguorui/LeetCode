#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include<algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    bool found = true;
    int numLen = nums.size();
    if(numLen <= 1)
    {
        return;
    }

    vector<int>::iterator rightIt = nums.end() - 1, leftIt = rightIt - 1;

    
    while((*leftIt >= *rightIt) && (leftIt - nums.begin() > 0))
    {
        leftIt--;
        rightIt--;
    }

    if(*leftIt >= *rightIt)
    {
        sort(nums.begin(), nums.end());
        return;
    }else{
        sort(rightIt, nums.end());
        vector<int>::iterator tempIt = rightIt;
        while(*tempIt <= *leftIt && tempIt != nums.end())
        {
            tempIt++;
        }
        int temp = *leftIt;
        *leftIt = *tempIt;
        *tempIt = temp;
    }
    return;


}

int main()
{
    int kArray[] = {3,2,1};
    int kLen = 3;
    vector<int> input;
    for(int i = 0; i < kLen; i++)
    {
        input.push_back(kArray[i]);
    }

    nextPermutation(input);
    for(int i = 0; i < input.size(); i++)
    {
        cout << input[i] << ", ";
    }
    cout << endl;
    getchar();
    return 0;
}