#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if(strs.size() == 0)
    {
        return "";
    }
    int ptr = 0;
    bool reverse = false;

    bool finish = false;
    while (!finish)
    {
        char c = NULL;
        vector<string>::iterator it = strs.begin();
        while (it != strs.end())
        {
            if(ptr == (*it).size())
            {
                finish = true;
                break;
            }
            if (c == NULL)
            {
                c = (*it).at(ptr);
            }
            else
            {
                if ((*it).at(ptr) != c)
                {
                    finish = true;
                    break;
                }
            }
            it++;
        }
        ptr++;
    }

    ptr--;
    if (ptr < 0)
    {
        return "";
    }
    else
    {
        return (*(strs.begin())).substr(0, ptr);
    }
}

int main()
{
    vector<string> v;
    // for(int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cin >> s;
    //     v.push_back(s);
    // }
    cout << longestCommonPrefix(v) << endl;
}
