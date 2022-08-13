#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<int> stk;
    for(int i = 0; i<N; i++)
    {
        string s;
        cin >> s;
        if(s == "push")
        {
            int num;
            cin >> num;
            stk.push(num);
        }
        else if(s == "pop")
        {
            if(stk.empty())
            {
                cout << "-1\n";
            }
            else
            {   cout << stk.top() << "\n";    
                stk.pop();
            }
        }
        else if(s == "top")
        {
            if(stk.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << stk.top() << "\n";    
            }
        }
        else if(s=="size")
        {
            cout << stk.size() << "\n";
        }
        else if(s == "empty")
        {
            if(!stk.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << "1\n";
            }
        }
        else
        {
            //invalid input
        }
    }


    return 0;
}