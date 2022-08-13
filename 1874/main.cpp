#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n,0);
    vector<char> op_v;
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }

    int current_index = 0;
    int i = 1;
    stack<int> stk;
    while(current_index < n)
    {
        int current_num = v[current_index];
        //cout << "current_num: " << current_num << "\n";
        if(!stk.empty())
        {
            if(stk.top() == current_num)
            {
                stk.pop();
                op_v.push_back('-');
                current_index++;
                continue;
            }
            else
            {
                if(i > current_num)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }

        while(current_num >= i)
        {
            stk.push(i);
            op_v.push_back('+');
            i++;
        }
    }

    int op_v_size = op_v.size();
    for(int i =0; i<op_v_size; i++)
    {
        cout << op_v[i] << "\n";
    }

    return 0;
}