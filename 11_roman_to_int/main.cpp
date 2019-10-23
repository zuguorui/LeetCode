#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

char romanArray[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int intArray[] = {1, 5, 10, 50, 100, 500, 1000};
map<char, int> rMap;

int romanToInt(string s)
{
    for(int i = 0; i < 7; i++)
    {
        rMap[romanArray[i]] = intArray[i];
    }

    int temp = 0;
    int last = 0;
    int current = 0;
    for(int i = 0; i < s.size(); i++)
    {
        current = rMap[s.at(i)];
        if(current > last)
        {
            if(last == 0)
            {
                last = current;
                continue;
            }else{
                temp += current - last;
                last = 0;
                continue;
            }
        }else{
            temp += last;
            last = current;
            continue;
        }
    }

    temp += last;
    return temp;

}

int main()
{
    string s;
    while(true)
    {
        cin >> s;
        cout << romanToInt(s) << endl;
    }
    
}