#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;
int N;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> seq(N+1, 0);
    for(int i=1; i<= N ; i++)
    {
        cin >> seq[i];
    }


    stack<pair<int, int>> stk;
    vector<int> answer(N+1, -1);
    for(int i = 1; i<=N; i++)
    {
        int num = seq[i];
        if(stk.empty())
        {
            stk.push({num, i});
        }
        else
        {
            while(true)
            {
                auto t = stk.top();
                if(t.first < seq[i])
                {
                    stk.pop();
                    answer[t.second] = seq[i];
                }
                else
                {
                    break;
                }
                if(stk.empty())
                {
                    break;
                }
            }
            stk.push({seq[i], i});
        }
    }

    for(int i =1;i <=N; i++)
    {
        cout << answer[i] << " ";
    }
    cout << '\n';

    return 0;
}
