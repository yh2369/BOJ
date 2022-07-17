#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool VPS(string& s)
{
    stack<char> stk;
    int n = s.length();
    for(int i = 0; i<n; i++)
    {
        char c = s[i];
        if(c == '(' || c == '[')
        {
            stk.push(c);
        }
        else
        {
            if(c == ')')
            {
                if(stk.empty())
                {
                    return false;
                }
                else
                {
                    if(stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (c == ']')
            {
                if(stk.empty())
                {
                    return false;
                }
                else
                {
                    if(stk.top() == '[')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }

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

    while(true)
    {
        string s;
        getline(cin, s);
        //cout << s << '\n';
        if(s == ".")
        {
            break;
        }

        if(VPS(s))
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