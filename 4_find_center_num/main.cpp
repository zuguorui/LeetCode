#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = (nums1.size() + nums2.size());
        int leftLength = totalLength / 2;
        int rightLength = totalLength - leftLength;
        double result = 0;

        if(nums1.size() == 0)
        {
            if(leftLength != rightLength)
            {
                result = nums2[leftLength];
            }else{
                result = (nums2[leftLength - 1] + nums2[leftLength]) * 0.5;
            }
        }else if(nums2.size() == 0)
        {
            if (leftLength != rightLength)
            {
                result = nums1[leftLength];
            }
            else
            {
                result = (nums1[leftLength - 1] + nums1[leftLength]) * 0.5;
            }
        }else{

            vector<int> smallArray, bigArray;
            
            if(nums1.size() <= nums2.size())
            {
                smallArray = nums1;
                bigArray = nums2;
            }else{
                smallArray = nums2;
                bigArray = nums1;
            }

            int leftCount1 = smallArray.size() / 2;
            int rightCount1 = smallArray.size() - leftCount1;

            int leftCount2;
            int rightCount2;

            int minIndex = 0;
            int maxIndex = 0;

            
            while (true)
            {
                leftCount2 = leftLength - leftCount1;
                rightCount2 = bigArray.size() - leftCount2;
                int leftMax, rightMin;
                if(leftCount1 == 0)
                {
                    leftMax = bigArray[leftCount2 - 1];
                    maxIndex = 1;
                }else if(leftCount2 == 0)
                {
                    leftMax = smallArray[leftCount1 - 1];
                    maxIndex = 0;
                }else{
                    int vol1 = smallArray[leftCount1 - 1];
                    int vol2 = bigArray[leftCount2 - 1];
                    leftMax = vol1 >= vol2 ? vol1 : vol2;
                    maxIndex = vol1 >= vol2 ? 0 : 1;
                }

                if(rightCount1 == 0)
                {
                    rightMin = bigArray[leftCount2];
                    minIndex = 1;
                }else if(rightCount2 == 0){
                    rightMin = smallArray[leftCount1];
                    minIndex = 0;
                }else{
                    int vol1 = smallArray[leftCount1];
                    int vol2 = bigArray[leftCount2];
                    rightMin = vol1 >= vol2 ? vol2 : vol1;
                    minIndex = vol1 >= vol2 ? 1 : 0;
                }

                if(rightMin < leftMax)
                {
                    if(minIndex == 0)
                    {
                        if (rightCount1 / 2 == 0)
                        {
                            leftCount1++;
                        }else{
                            leftCount1 = leftCount1 + rightCount1 / 2;
                        }
                            
                        rightCount1 = smallArray.size() - leftCount1;
                    }else{
                        if (leftCount1 / 2 == 0)
                        {
                            rightCount1++;
                        }else{
                            rightCount1 = rightCount1 + leftCount1 / 2;
                        }
                            
                        leftCount1 = smallArray.size() - rightCount1;
                    }
                }else{
                    if(leftLength == rightLength)
                    {
                        result = (leftMax + rightMin) * 0.5;
                    }else{
                        result = rightMin * 1.0;
                    }
                    break;
                }

            }
        }

        return result;
        
        
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    b.push_back(5);
    // b.push_back(4);
    double result = s->findMedianSortedArrays(a, b);
    cout << result << endl;
    getchar();
    return 0;
}