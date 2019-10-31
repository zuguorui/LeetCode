#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory.h>

using namespace std;

// vector<string> generateParenthesis(int n)
// {

//     vector<string> result;
//     if (n == 0)
//     {
//         return result;
//     }
//     if (n == 1)
//     {
//         result.push_back("()");
//         return result;
//     }

//     int remainLen = n - 1;

//     char *remainArray = (char *)malloc(2 * remainLen * sizeof(char));

//     int *nIndex = (int *)alloca(remainLen * sizeof(int));
//     for (int i = 0; i < remainLen; i++)
//     {
//         nIndex[i] = i;
//     }

//     while (true)
//     {
//         string temp = "(";
//         memset(remainArray, ')', 2 * remainLen);
//         for (int i = 0; i < remainLen; i++)
//         {
//             remainArray[nIndex[i]] = '(';
//         }
//         for (int i = 0; i < 2 * remainLen; i++)
//         {
//             temp += remainArray[i];
//         }
//         temp += ')';

//         cout << "indices = ";
//         for (int i = 0; i < remainLen; i++)
//         {
//             cout << nIndex[i] << " ";
//         }
//         cout << endl;
//         cout << "randomStr = ";
//         for (int i = 0; i < 2 * remainLen; i++)
//         {
//             cout << remainArray[i];
//         }
//         cout << endl
//              << endl;

//         result.push_back(temp);
//         nIndex[remainLen - 1] += 1;
//         if (nIndex[remainLen - 1] >= 2 * remainLen)
//         {
//             int index = remainLen - 2;
//             while (index >= 0)
//             {
//                 nIndex[index] += 1;
//                 if (nIndex[index] <= remainLen + index)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     index--;
//                 }
//             }
//             if (index < 0)
//             {
//                 break;
//             }
//             else
//             {
//                 for (int i = index + 1; i < remainLen; i++)
//                 {
//                     nIndex[i] = nIndex[i - 1] + 1;
//                 }
//             }
//             int bigCount = 0;
//             for (int i = 0; i < remainLen; i++)
//             {
//                 if (nIndex[i] > remainLen)
//                 {
//                     bigCount++;
//                 }
//             }
//             if (bigCount > remainLen / 2)
//             {
//                 break;
//             }
//         }
//     }

//     cout << "finding " << n << endl;
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << endl;
//     }
//     cout << "find " << n << " finish" << endl;
//     return result;
// }

vector<string> generateParenthesis(int n)
{
    vector<vector<string>> resultList;

    vector<string> zeroList;
    zeroList.push_back("");
    resultList.push_back(zeroList);
    
    vector<string> oneList;
    oneList.push_back("()");
    resultList.push_back(oneList);
    for(int i = 2; i <= n; i++)
    {
        vector<string> totalList;
        for(int a = 0; a <= i - 1; a++)
        {
            int b = i - 1 - a;
            vector<string> aList = resultList[a];
            vector<string> bList = resultList[b];
            for(int c = 0; c < aList.size(); c++)
            {
                for(int d = 0; d < bList.size(); d++)
                {
                    string temp = "(" + aList[c] + ")" + bList[d];
                    totalList.push_back(temp);
                }
            }
        }
        resultList.push_back(totalList);
    }
    return resultList[n];
}

int main()
{
    vector<string> result = generateParenthesis(4);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    for (int i = 0; i < result.size(); i++)
    {
        string t = result[i];
        for (int j = 0; j < result.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (t == result[j])
            {
                cout << "Error: " << i << " and " << j << " is equal, they are" << t << endl;
            }
        }
    }
    return 0;
}