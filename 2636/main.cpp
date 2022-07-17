#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int dx[4] = {-1, 0 , 1 , 0};
const int dy[4] = {0, -1, 0, 1};

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i = 0; i< N ; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int N, int M, int x, int y)
{
    visited[x][y] = 1;
    
    for(int i = 0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny <0 || ny >= M) continue;

        if(visited[nx][ny] == 0 && grid[nx][ny] == 0)
        {
            dfs(grid, visited, N, M, nx, ny);
        }
    }
}

void remove_cheese(vector<vector<int>>& grid, vector<vector<int>>& visited, int N, int M)
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k <4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if( nx<0 || nx >= N || ny < 0 || ny >=M) continue;

                    if(visited[nx][ny] == 1)
                    {
                        grid[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int count_cheese(vector<vector<int>>& grid, int N, int M)
{
    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    
    for(int i =0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> grid[i][j];
        }
    }
    int hour = 0;
    int cnt = 0;
    int prev_cnt = 0;
    while(true)
    {
        vector<vector<int>> visited(N, vector<int>(M, 0));
        dfs(grid, visited, N, M, 0, 0);

        //print2DV(grid, N, M);
        //cout << '\n';

        prev_cnt = count_cheese(grid,N, M);
        if(prev_cnt == 0)
        {
            break;
        }
        
        remove_cheese(grid, visited, N, M);
        hour++;
        cnt = count_cheese(grid, N, M);
        if(cnt == 0)
        {
            break;
        }

    }
    cout << hour << '\n';
    cout << prev_cnt << '\n';

    return 0;
}

