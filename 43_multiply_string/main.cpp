#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <sstream>
#include <memory.h>

using namespace std;

// string multiply(string num1, string num2)
// {

//     int num1Len = num1.length();
//     int num2Len = num2.length();

//     if((num1Len == 1 && num1.at(0) == '0') || (num2Len == 1 && num2.at(0) == '0'))
//     {
//         return "0";
//     }

//     int *num1Array = (int *)calloc(num1Len, sizeof(int));
//     int *num2Array = (int *)calloc(num2Len, sizeof(int));
//     int **multiMap = (int **)calloc(num2Len, sizeof(int *));
//     for (int i = 0; i < num2Len; i++)
//     {
//         multiMap[i] = (int *)calloc(num2Len + num1Len, sizeof(int));
//     }

//     for (int i = 0; i < num1Len; i++)
//     {
//         num1Array[i] = (int)num1.at(i) - '0';
//     }
//     for (int i = 0; i < num2Len; i++)
//     {
//         num2Array[i] = (int)num2.at(i) - '0';
//     }

//     for (int i = num2Len - 1; i >= 0; i--)
//     {
//         int a0 = 0, a1 = 0;
//         int m = num2Array[i];
//         int j = 0;
//         for (j = num1Len - 1; j >= 0; j--)
//         {
//             int multi = m * num1Array[j] + a1;
//             a0 = multi % 10;
//             a1 = multi / 10;
//             multiMap[i][i + j + 1] = a0;
//         }
//         multiMap[i][i + j + 1] = a1;
//     }

//     // for (int i = 0; i < num2Len; i++)
//     // {
//     //     for (int j = 0; j < num1Len + num2Len; j++)
//     //     {
//     //         cout << multiMap[i][j] << ", ";
//     //     }
//     //     cout << endl;
//     // }

//     int toUpNum = 0, remainNum = 0;
//     int resultLen = num1Len + num2Len + 1;
//     int resultArray[resultLen];
//     int resultPtr = resultLen - 1;
//     for (int i = num1Len + num2Len - 1; i >= 0; i--)
//     {
//         int total = 0;
//         for (int j = num2Len - 1; j >= 0; j--)
//         {
//             total += multiMap[j][i];
//         }
//         total += toUpNum;
//         remainNum = total % 10;
//         toUpNum = total / 10;
//         resultArray[resultPtr--] = remainNum;
//     }
//     resultArray[resultPtr] = toUpNum;

//     resultPtr = 0;
//     while(resultPtr < resultLen)
//     {
//         if(resultArray[resultPtr] != 0)
//         {
//             break;
//         }
//         resultPtr++;
//     }
    
    

//     stringstream ss;

//     while (resultPtr < resultLen)
//     {
//         ss << resultArray[resultPtr++];
//     }

//     string resultStr;
//     ss >> resultStr;
//     free(num1Array);
//     free(num2Array);
//     free(multiMap);
//     return resultStr;
// }

string multiply(string num1, string num2)
{
    int num1Len = num1.length();
    int num2Len = num2.length();

    if((num1Len == 1 && num1.at(0) == '0') || (num2Len == 1 && num2.at(0) == '0'))
    {
        return "0";
    }

    int *num1Array = (int *)calloc(num1Len, sizeof(int));
    int *num2Array = (int *)calloc(num2Len, sizeof(int));


    for (int i = 0; i < num1Len; i++)
    {
        num1Array[i] = (int)num1.at(i) - '0';
    }
    for (int i = 0; i < num2Len; i++)
    {
        num2Array[i] = (int)num2.at(i) - '0';
    }

    int resultLen = num1Len + num2Len;
    int *resultArray = (int*)calloc(resultLen, sizeof(int));
    int toUp = 0, remain = 0;
    for(int i = num2Len - 1; i >= 0; i--)
    {
        toUp = 0;
        remain = 0;
        for(int j = num1Len - 1; j >= 0; j--)
        {
            int total = num2Array[i] * num1Array[j] + resultArray[i + j + 1] + toUp;
            toUp = total / 10;
            remain = total % 10;
            resultArray[i + j + 1] = remain;
        }
        resultArray[i] = toUp;
        for(int k = 0; k < resultLen; k++)
        {
            cout << resultArray[k] << ", ";
        }
        cout << endl;
    }
    resultArray[0] = toUp;
    int resultPtr = 0;
    while(resultPtr < resultLen)
    {
        if(resultArray[resultPtr] != 0)
        {
            break;
        }
        resultPtr++;
    }
    
    

    stringstream ss;

    while (resultPtr < resultLen)
    {
        ss << resultArray[resultPtr++];
    }

    string resultStr;
    ss >> resultStr;
    free(num1Array);
    free(num2Array);
    free(resultArray);
    return resultStr;
}

int main()
{
    string s1 = "19", s2 = "9";
    cin >> s1;
    cin >> s2;
    string result = multiply(s1, s2);
    cout << result << endl;
}