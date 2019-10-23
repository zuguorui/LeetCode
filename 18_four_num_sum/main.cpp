#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

// Sort on nums itself, use iterator

// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
        
//         vector<vector<int>> result;
//         if(nums.size() < 4)
//         {
//             return result;
//         }

//         stackSort(nums);

//         // sort(nums.begin(), nums.end());
        

//         for (vector<int>::iterator p1 = nums.begin(); p1 < nums.end() - 3; p1++)
//         {
//             int p1Value = *p1;
//             for (vector<int>::iterator p2 = p1 + 1; p2 < nums.end() - 2; p2++)
//             {
//                 int p2Value = *p2;
//                 for (vector<int>::iterator p3 = p2 + 1; p3 < nums.end() - 1; p3++)
//                 {
//                     int p3Value = *p3;
//                     int remain = target - p1Value - p2Value - p3Value;
//                     vector<int>::iterator startIndex = p3 + 1;
//                     if (*startIndex > remain)
//                     {
//                         break;
//                     }
//                     int p4 = fastFind(nums, distance(nums.begin(), startIndex), distance(startIndex, nums.end()), remain);
//                     if (p4 != -1)
//                     {
//                         vector<int> aResult;
//                         aResult.push_back(*p1);
//                         aResult.push_back(*p2);
//                         aResult.push_back(*p3);
//                         aResult.push_back(remain);
//                         result.push_back(aResult);
//                     }
//                     while (*(p3 + 1) == p3Value && p3 + 1 < nums.end() - 1)
//                     {
//                         p3++;
//                     }
                    
//                 }
//                 while (*(p2 + 1) == p2Value && p2 + 1 < nums.end() - 2)
//                 {
//                     p2++;
//                 }
                
//             }
//             while (*(p1 + 1) == p1Value && p1 + 1 < nums.end() - 3)
//             {
//                 p1++;
//             }
            
//         }

        
//         return result;
//     }

    
//     int fastFind(vector<int> sortedNums, int offset, int len, int target)
//     {
//         vector<int>::iterator startIt = sortedNums.begin() + offset;
//         vector<int>::iterator endIt = startIt + len;
//         vector<int>::iterator p = startIt;
//         vector<int>::iterator oldP = p + 1;
//         while (p != oldP)
//         {
//             oldP = p;
//             p = startIt + distance(startIt, endIt) / 2;
//             if (*p == target)
//             {
//                 return distance(sortedNums.begin(), p);
//             }
//             else if (*p < target)
//             {
//                 startIt = p;
//             }
//             else
//             {
//                 endIt = p;
//             }
//         }
//         return -1;
//     }

    
//     void stackSort(vector<int> &nums)
//     {
//         typedef struct _TreeNode
//         {
//             int content;
//             int repeatCount;
//             struct _TreeNode *left;
//             struct _TreeNode *right;
//         } TreeNode;

//         //insert nums to a tree
//         TreeNode *rootNode = (TreeNode *)calloc(1, sizeof(TreeNode));
//         vector<int>::iterator it = nums.begin();
//         rootNode->content = *it;
//         rootNode->repeatCount = 1;
//         it++;
//         while (it != nums.end())
//         {
//             TreeNode *pNode = rootNode;
//             while (true)
//             {
//                 if (*it == pNode->content)
//                 {
//                     pNode->repeatCount++;
//                     break;
//                 }
//                 else if (*it < pNode->content)
//                 {
//                     if (pNode->left == NULL)
//                     {
//                         pNode->left = (TreeNode *)calloc(1, sizeof(TreeNode));
//                         pNode->left->content = *it;
//                         pNode->left->repeatCount = 1;
//                         break;
//                     }
//                     else
//                     {
//                         pNode = pNode->left;
//                         continue;
//                     }
//                 }
//                 else
//                 {
//                     if (pNode->right == NULL)
//                     {
//                         pNode->right = (TreeNode *)calloc(1, sizeof(TreeNode));
//                         pNode->right->content = *it;
//                         pNode->right->repeatCount = 1;
//                         break;
//                     }
//                     else
//                     {
//                         pNode = pNode->right;
//                         continue;
//                     }
//                 }
//             }
//             it++;
//         }

//         //load this tree
//         it = nums.begin();
        
//         stack<TreeNode *> nodes;

//         // cout << "debug:" << endl;
//         TreeNode *pNode = rootNode;
//         while (pNode != NULL || nodes.size() != 0)
//         {
//             while (pNode != NULL)
//             {
//                 nodes.push(pNode);
//                 pNode = pNode->left;
//             }
//             if (nodes.size() != 0)
//             {
//                 TreeNode *nNode = nodes.top();
//                 for (int i = 0; i < nNode->repeatCount; i++)
//                 {
//                     *it = nNode->content;
//                     it++;
//                     // cout << nNode->content << endl;
//                 }
//                 nodes.pop();

//                 pNode = nNode->right;
//                 free(nNode);
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        
        vector<vector<int>> result;
        if(nums.size() < 4)
        {
            return result;
        }

        int *sortedNums = stackSort(nums);

        // sort(nums.begin(), nums.end());
        // int *sortedNums = (int*)calloc(nums.size(), sizeof(int));

        // vector<int>::reverse_iterator it = nums.rbegin();
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     sortedNums[i] = *it;
        //     it++;
        // }

        for (int p1 = 0; p1 < nums.size() - 3; p1++)
        {
            int p1Value = sortedNums[p1];
            for (int p2 = p1 + 1; p2 < nums.size() - 2; p2++)
            {
                int p2Value = sortedNums[p2];
                for (int p3 = p2 + 1; p3 < nums.size() - 1; p3++)
                {
                    int p3Value = sortedNums[p3];
                    int remain = target - p1Value - p2Value - p3Value;
                    int startIndex = p3 + 1;
                    if (sortedNums[startIndex] > remain)
                    {
                        break;
                    }
                    int p4 = fastFind(sortedNums, startIndex, nums.size() - startIndex, remain);
                    if (p4 != -1)
                    {
                        vector<int> aResult;
                        aResult.push_back(sortedNums[p1]);
                        aResult.push_back(sortedNums[p2]);
                        aResult.push_back(sortedNums[p3]);
                        aResult.push_back(remain);
                        result.push_back(aResult);
                    }
                    while (sortedNums[p3 + 1] == p3Value && p3 + 1 < nums.size() - 1)
                    {
                        p3++;
                    }
                    
                }
                while (sortedNums[p2 + 1] == p2Value && p2  + 1 < nums.size() - 2)
                {
                    p2++;
                }
                
            }
            while (sortedNums[p1 + 1] == p1Value && p1 + 1 < nums.size() - 3)
            {
                p1++;
            }
            
        }

        free(sortedNums);
        return result;
    }

    int fastFind(int *sortedNums, int offset, int len, int target)
    {
        int startIndex = offset;
        int endIndex = offset + len;
        int p = -0;
        int oldP = -1;
        while (p != oldP)
        {
            oldP = p;
            p = (startIndex + endIndex) / 2;
            if (sortedNums[p] == target)
            {
                return p;
            }
            else if (sortedNums[p] < target)
            {
                startIndex = p;
            }
            else
            {
                endIndex = p;
            }
        }
        return -1;
    }

    int *stackSort(vector<int> &nums)
    {
        typedef struct _TreeNode
        {
            int content;
            int repeatCount;
            struct _TreeNode *left;
            struct _TreeNode *right;
        } TreeNode;

        //insert nums to a tree
        TreeNode *rootNode = (TreeNode *)calloc(1, sizeof(TreeNode));
        vector<int>::iterator it = nums.begin();
        rootNode->content = *it;
        rootNode->repeatCount = 1;
        it++;
        while (it != nums.end())
        {
            TreeNode *pNode = rootNode;
            while (true)
            {
                if (*it == pNode->content)
                {
                    pNode->repeatCount++;
                    break;
                }
                else if (*it < pNode->content)
                {
                    if (pNode->left == NULL)
                    {
                        pNode->left = (TreeNode *)calloc(1, sizeof(TreeNode));
                        pNode->left->content = *it;
                        pNode->left->repeatCount = 1;
                        break;
                    }
                    else
                    {
                        pNode = pNode->left;
                        continue;
                    }
                }
                else
                {
                    if (pNode->right == NULL)
                    {
                        pNode->right = (TreeNode *)calloc(1, sizeof(TreeNode));
                        pNode->right->content = *it;
                        pNode->right->repeatCount = 1;
                        break;
                    }
                    else
                    {
                        pNode = pNode->right;
                        continue;
                    }
                }
            }
            it++;
        }

        //load this tree
        int *result = (int *)calloc(nums.size(), sizeof(int));
        int resultPtr = 0;
        stack<TreeNode *> nodes;

        // cout << "debug:" << endl;
        TreeNode *pNode = rootNode;
        while (pNode != NULL || nodes.size() != 0)
        {
            while (pNode != NULL)
            {
                nodes.push(pNode);
                pNode = pNode->left;
            }
            if (nodes.size() != 0)
            {
                TreeNode *nNode = nodes.top();
                for (int i = 0; i < nNode->repeatCount; i++)
                {
                    result[resultPtr++] = nNode->content;
                    // cout << nNode->content << endl;
                }
                nodes.pop();

                pNode = nNode->right;
                free(nNode);
            }
        }
        return result;
    }
};

int main()
{

    int k[] = {-3, -2, -1, 0, 0, 1, 2, 3};
    int kLen = 8;
    // vector<int> a;
    // cout << "input: " << endl;
    // for (int i = 0; i < 10; i++)
    // {

    //     cout << k[i] << endl;
    //     a.push_back(k[i]);
    // }

    Solution *solution = new Solution();
    // int *result = solution->stackSort(a);

    // cout << "result: " << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << result[i] << " ";
    // }

    // cout << "fast find" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "to find " << k[i] << ", position is " << solution->fastFind(result, 0, 5, k[i]) << endl;
    // }
    // free(result);


    vector<int> input;
    for(int i = 0; i < kLen; i++)
    {
        input.push_back(k[i]);
    }
    vector<vector<int>> result = solution->fourSum(input, 0);
    vector<vector<int>>::iterator it1 = result.begin();
    while(it1 != result.end())
    {
        vector<int> aResult = *it1;
        vector<int>::iterator it2 = aResult.begin();
        while(it2 != aResult.end())
        {
            cout << *it2 << ", ";
            it2++;
        }
        cout << endl;
        it1++;
    }
    cout << endl;
}