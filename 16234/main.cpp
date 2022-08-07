#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>


using namespace std;

int N, L, R;
int grid[54][54];
int prev_grid[54][54];
bool visited[54][54];

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0, -1, 0, 1};
void printGrid();
void init_visited();
void dfs(int x, int y, stack<pair<int,int>>& stk);
bool same_grid();
void copy_grid();

void printGrid()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void init_visited()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y, stack<pair<int,int>>& stk)
{
    visited[x][y] = true;
    for(int i = 0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(visited[nx][ny]) continue;
        int delta = abs(grid[nx][ny] - grid[x][y]);
        if(L > delta || delta > R) continue;

        stk.push({nx, ny});
        dfs(nx, ny ,stk);
    }

}

bool same_grid()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(prev_grid[i][j] != grid[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void copy_grid()
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            prev_grid[i][j] = grid[i][j];
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L >> R;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin >> grid[i][j];
        }
    }

    //printGrid();
    int answer = 0;
    while(true)
    {

        copy_grid();
        init_visited();
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(!visited[i][j])
                {
                    stack<pair<int,int>> stk;
                    stk.push({i,j});
                    dfs(i,j,stk);
                    if(stk.size() > 1)
                    {
                        stack<pair<int,int>> stk_cpy = stk;
                        int n = stk.size();
                        int sum = 0;
                        while(stk_cpy.size())
                        {
                            auto top = stk_cpy.top();
                            int x = top.first;
                            int y = top.second;
                            sum += grid[x][y];
                            stk_cpy.pop();
                        }
                        //cout << "sum: " << sum << " n: " << n << "\n";

                        int population = sum/n;

                        while(stk.size())
                        {
                            auto top = stk.top();
                            int x = top.first;
                            int y = top.second;
                            grid[x][y] = population;
                            stk.pop();
                        }
                        //printGrid();
                    }
                }
            }
        }

        if(same_grid())
        {
            break;
        }
        answer++;
        //cout << "answer: " << answer << "\n";
    }
    cout << answer << "\n";



    return 0;
}