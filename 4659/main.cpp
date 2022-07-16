#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c =='i' || c =='o' || c =='u');
}

bool isAcceptable(string& s)
{
    int n = s.size();

    bool containingVowel = false;
    for(int i = 0; i<n; i++)
    {
        char c = s[i];
        if(isVowel(c))
        {
            containingVowel = true;
            break;
        }
    }
    if(containingVowel == false)
    {
        return false;
    }

    if(n == 1)
    {
        return true;
    }

    if(n == 2)
    {
        if(s[0] == s[1])
        {
            if(s[0] == 'e' || s[0] == 'o')
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        else
        {
            return true;
        }
    }

    for(int i = 2; i<n; i++)
    {
        if(isVowel(s[i]) && isVowel(s[i-1]) && isVowel(s[i-2]))
        {
            return false;
        }        
        if (!isVowel(s[i]) && !isVowel(s[i-1]) && !isVowel(s[i-2]))
        {
            return false;
        }
    }

    for(int i = 1; i<n; i++)
    {
        if(s[i] == s[i-1])
        {
            if(s[i] == 'e' || s[i-1] == 'o')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;

}

int main()
{
    string s;
    while(true)
    {
        cin >> s;
        if(s == "end")
        {
            break;
        }

        if(isAcceptable(s))
        {
            cout << "<" << s << "> is acceptable." << endl; 
        }
        else
        {
            cout << "<" << s << "> is not acceptable." << endl; 
        }
        



    }
    return 0;
}