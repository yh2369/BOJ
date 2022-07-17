#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool VPS(string& s)
{
    stack<char> stk;
    int n = s.length();
    for(int i =0; i<n; i++)
    {
        char c = s[i];
        if(c == '(')
        {
            stk.push(c);
        }
        else
        {
            if(stk.empty())
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
    }
    return stk.empty();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        if(VPS(s))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}