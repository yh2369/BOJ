#include <iostream>
#include <queue>
#include <cassert>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    queue<int> q;
    int N;
    cin >> N;
    for(int i = 0; i< N; i++)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(op == "pop")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();  
            }
        }
        else if( op == "size")
        {
            cout << q.size() << "\n";
        }
        else if(op == "empty")
        {
            if(q.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout <<"0\n";
            }
        }
        else if(op == "front")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if(op == "back")
        {
            if(q.empty())
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
        else
        {
            assert(false);
        }
    }

    
    return 0;
}