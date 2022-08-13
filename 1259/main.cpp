#include <iostream>
#include <string>

using namespace std;

bool pelindrom(string s)
{
    int len = s.length();
    int half_len = len/2;
    for(int i = 0; i<half_len; i++)
    {
        if(s[i] != s[len-1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(true)
    {
        string s;
        cin >> s;
        if(s.length() == 1 && s[0] == '0')
        {
            break;
        }

        if(pelindrom(s))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }

    }
    
    return 0;
}