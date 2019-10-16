#include <iostream>
#include <stdlib.h>

using namespace std;

bool matchRegex(string s, string p)
{
    
    int matchMode = 0;//0: match exactly. 1: match *
    int codeMode = 0;//0: match exactly char. 1: match anything
    int step = 0;

    bool sHasChar = s.size() != 0;
    bool pHasChar = p.size() != 0;

    if(!sHasChar && !pHasChar)
    {
        return true;
    }else if(sHasChar && !pHasChar)
    {
        return false;
    }

    char p1 = p.at(0);
    int pOffset = 1;
    if(p1 == '.')
    {
        codeMode = 1;
    }else{
        codeMode = 0;
    }
    if(p.size() > 1 || p.at(1) == '*')
    {
        matchMode = 1;
        pOffset = 2;
    }else
    {
        matchMode = 0;
    }

    if(codeMode == 0)
    {
        int sOffset = 0;
        
        if(matchMode == 0)
        {
            while(s.at(sOffset) == p1 && sOffset < s.size())
            {
                sOffset++;
            }

            if(sOffset == 0)
            {
                return false;
            }else{
                return matchRegex(s.substr(sOffset, s.size() - sOffset), p.substr(pOffset, p.size() - pOffset));
            }
            
        }else{
            while(s.at(sOffset) == p1 && sOffset < s.size())
            {
                sOffset++;
            }
            return matchRegex(s.substr(sOffset, s.size() - sOffset), p.substr(pOffset, p.size() - pOffset));
        }
    }else{
        char matchTarget = s.at(0);
        int sOffset = 0;
        if(matchMode == 0)
        {
            sOffset = 1;
            return matchRegex(s.substr(sOffset, s.size() - sOffset), p.substr(pOffset, p.size() - pOffset));
        }else{
            while(s.at(sOffset) == matchTarget && sOffset < s.size())
            {
                sOffset++;
            }
            return matchRegex(s.substr(sOffset, s.size() - sOffset), p.substr(pOffset, p.size() - pOffset));
        }
    }

}

int main()
{
    string s = "aa";
    string p = "a";
    
    return matchRegex(s, p);
}