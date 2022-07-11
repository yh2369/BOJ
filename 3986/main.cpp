#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

bool isGoodInput(string& input)
{
    int n = input.size();
    stack<char> stk;
    for(int i = 0; i<n; i++)
    {
        char c = input[i];
        if(stk.empty())
        {
            stk.push(c);
        }
        else
        {
            char top = stk.top();
            if(top == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
            
        }
    }
    return stk.empty();
}


int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    for(int i =0; i<N; i++)
    {
        string input;
        cin >> input;
        if(isGoodInput(input))
        {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}