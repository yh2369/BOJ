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

const int dx[4] = {-1, 0 , 1, 0 };
const int dy[4] = {0, -1, 0, 1};

int R,C, K;

void go(vector<vector<char>>& grid, vector<vector<int>>& visited, stack<pair<int,int>>& stk, int R, int C, int K, int x, int y, int& cnt)
{
    if(x == 0 && y == C-1)
    {
        if(visited[x][y] == K)
        {
            cnt++;
        }
        auto top = stk.top();
        visited[top.first][top.second] = 0;
        return;
    }

    for(int i = 0; i< 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(grid[nx][ny] == 'T') continue;
        if(visited[nx][ny] != 0) continue;

        visited[nx][ny] = visited[x][y] + 1;
        stk.push({nx, ny});
        go(grid, visited,stk, R,C,K, nx, ny, cnt);    
    }
    visited[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R>>C>>K;
    vector<vector<char>> grid(R, vector<char>(C, '.'));
    vector<vector<int>> visited(R, vector<int>(C, 0));
    stack<pair<int,int>> stk;

    for(int i =0;i<R ; i++)
    {
        for(int j = 0; j<C ;j++)
        {
            cin >> grid[i][j];
        }
    }
    /*
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j< C; j++)
        {
            cout << grid[i][j] <<" ";
        }
        cout << '\n';
    }
    */
    int cnt = 0;
    visited[R-1][0] = 1;
    go(grid, visited, stk, R, C , K, R-1, 0, cnt);
    cout << cnt << '\n';
    

    return 0;
}