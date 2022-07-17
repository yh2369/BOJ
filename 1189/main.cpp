#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int R,C, K;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R>>C>>K;
    vector<vector<char>> grid(R, vector<char>(C, '.'));


    for(int i =0;i<R ; i++)
    {
        for(int j = 0; j<C ;j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j< C; j++)
        {
            cout << grid[i][j] <<" ";
        }
        cout << '\n';
    }

    return 0;
}