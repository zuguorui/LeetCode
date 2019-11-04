#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>

using namespace std;

vector<string> sortStrings(vector<string> s)
{
    vector<string> result;
    if (s.size() == 0)
    {
        return result;
    }
    if (s.size() == 1)
    {
        result.push_back(s[0]);
        return result;
    }

    string head;
    vector<string> remain;
    for (int i = 0; i < s.size(); i++)
    {
        head = s[i];
        remain.clear();
        for (int j = 0; j < s.size(); j++)
        {
            if (j != i)
            {
                remain.push_back(s[j]);
            }
        }
        vector<string> lowResult = sortStrings(remain);
        for (int j = 0; j < lowResult.size(); j++)
        {
            string temp = head + lowResult[j];
            result.push_back(temp);
        }
    }
    return result;
}

vector<int> findSubStrInner(string source, string target)
{
    // cout << "source = " << source << endl;
    // cout << "target = " << target << endl;
    vector<int> result;
    int k = source.size() - target.size();
    for (int i = 0; i <= k; i++)
    {
        bool found = true;
        for (int j = 0; j < target.size(); j++)
        {
            if (source[i + j] != target[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            result.push_back(i);
        }
    }

    return result;
}

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    if (words.size() == 0)
    {
        return result;
    }
    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalSLen = s.size();
    if (totalSLen < wordLen * wordCount)
    {
        return result;
    }

    map<string, int> wordModel;
    for (int i = 0; i < words.size(); i++)
    {
        if (wordModel.find(words[i]) == wordModel.end())
        {
            wordModel[words[i]] = 1;
        }
        else
        {
            wordModel[words[i]] += 1;
        }
    }

    cout << "wordModel" << endl;
    for(map<string, int>::iterator it = wordModel.begin(); it != wordModel.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    map<string, int> subStrings;
    list<string> stringQueen;

    for (int startIndex = 0; startIndex < wordLen; startIndex++)
    {
        int index = startIndex;
        subStrings.clear();
        stringQueen.clear();
        for (int i = 0; i < wordCount - 1; i++)
        {
            string temp = s.substr(index + i * wordLen, wordLen);
            if (subStrings.find(temp) == subStrings.end())
            {
                subStrings[temp] = 1;
            }
            else
            {
                subStrings[temp] += 1;
            }
            stringQueen.push_back(temp);
        }

        while (totalSLen >= index + wordCount * wordLen)
        {
            string temp = s.substr(index + (wordCount - 1) * wordLen, wordLen);
            stringQueen.push_back(temp);
            if (subStrings.find(temp) == subStrings.end())
            {
                subStrings[temp] = 1;
            }
            else
            {
                subStrings[temp] += 1;
            }

            cout << "subStrings" << endl;
            for(map<string, int>::iterator it0 = subStrings.begin(); it0 != subStrings.end(); it0++)
            {
                cout << (*it0).first << " " << (*it0).second << endl;
            }

            map<string, int>::iterator it = wordModel.begin();
            bool found = true;
            while (it != wordModel.end())
            {
                string key = (*it).first;
                if (wordModel[key] != subStrings[key])
                {
                    found = false;
                    break;
                }
                it++;
            }
            if (found)
            {
                result.push_back(index);
            }
            string delStr = stringQueen.front();
            stringQueen.pop_front();
            subStrings[delStr] -= 1;
            if (subStrings[delStr] == 0)
            {
                subStrings.erase(delStr);
            }
            index += wordLen;
        }
    }

    return result;
}


int main()
{
    string wordsArray[] = {"a","a","b","b","c"};
    int wordsLen = 5;
    vector<string> words;
    for (int i = 0; i < wordsLen; i++)
    {
        words.push_back(wordsArray[i]);
    }
    string s = "aaabbbc";
    vector<int> result = findSubstring(s, words);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    getchar();
    return 0;
}
