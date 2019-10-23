#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

// map<int64_t, bool> note;

// bool dp(string &text, int textIndex, string &pattern, int patternIndex)
// {
//     int64_t index = textIndex << 32 | patternIndex;
//     if(note[index] != NULL)
//     {
//         return note[index];
//     }
//     if(patternIndex == pattern.size())
//     {
//         return textIndex == text.size();
//     }
//     bool currentMatch = (textIndex < text.size())
//         && ((pattern.at(patternIndex) == '.') || (pattern.at(patternIndex) == text.at(textIndex)));
//     bool ans = false;
//     if(pattern.size() - patternIndex >= 2 && pattern.at(patternIndex + 1) == '*')
//     {
//         ans = dp(text, textIndex, pattern, patternIndex + 2) || (currentMatch && dp(text, textIndex + 1, pattern, patternIndex));
//     }else{
//         ans = currentMatch && dp(text, textIndex + 1, pattern, patternIndex + 1);
//     }
//     note[index] = ans;
//     return ans;
// }

// bool isMatch(string text, string pattern)
// {
//     note.clear();
//     return dp(text, 0, pattern, 0);
// }

// class Solution
// {
// public:
//     bool isMatch(string s, string p)
//     {
//         int lens = s.length(), lenp = p.length();
//         bool **dp = new bool *[lens + 2];
//         for (int i = 0; i < lens + 2; i++)
//             dp[i] = new bool[lenp + 2];

//         for (int i = 0; i < lens + 2; i++)
//             for (int j = 0; j < lenp + 2; j++)
//                 dp[i][j] = false;
//         dp[0][0] = true;

//         for (int i = 1; i < lenp; i++)
//             if (p[i] == '*' && dp[0][i - 1])
//                 dp[0][i + 1] = true;

//         for (int i = 0; i < lens; i++)
//             for (int j = 0; j < lenp; j++)
//             {
//                 if (s[i] == p[j] || p[j] == '.')
//                     dp[i + 1][j + 1] = dp[i][j];
//                 else if (p[j] == '*')
//                 {
//                     if (p[j - 1] != s[i] && p[j - 1] != '.')
//                         dp[i + 1][j + 1] = dp[i + 1][j - 1];
//                     else
//                         dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
//                 }
//             }

//         return dp[lens][lenp];
//     }
// };

bool isMatch(string s, string p)
{
    int lens = s.size();
    int lenp = p.size();

    bool dp[lens + 1][lenp + 1];
    for(int i = 0; i < lens + 1; i++)
    {
        for(int j = 0; j < lenp + 1; j++)
        {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true; // for this case, both s and p are empty

    for(int i = 0; i < lens; i++)
    {
        for(int j = 0; j < lenp; j++)
        {
            if(p[j] == s[i] || p[j] == '.')
            {

            }
        }
    }


}

int main()
{
    string s;
    string p;

    // cin >> s;
    // cin >> p;
    s = "aaa";
    p = "aaaa";

    cout << isMatch(s, p) << endl;
    return 0;
}