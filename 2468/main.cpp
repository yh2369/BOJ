#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i= 0; i<N; i++)
    {
        for(int j= 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout <<endl;
    }
}

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int N)
{
    visited[x][y] = 1;
    for(int i= 0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;

        if(visited[nx][ny] == 0 && grid[nx][ny] == 1)
        {
            dfs(grid, visited, nx, ny, N);
        }
    }
}

int main()
{
    int N;
    cin >> N;


    vector<vector<int>> height_map(N, vector<int>(N, 0));
    int max_height = 0;
    for(int i=0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin >> height_map[i][j];
            if(max_height < height_map[i][j])
            {
                max_height = height_map[i][j];
            }
        }
    }

    int max_cnt = 0;
    int n;
    for(n = 0; n<=max_height; n++)
    {
        vector<vector<int>> grid(N, vector<int>(N, 0));
        vector<vector<int>> visited(N, vector<int>(N, 0));
        for(int i=0; i<N; i++)
            {
                for(int j= 0;j<N; j++)
                {
                    if(height_map[i][j] > n)
                    {
                        grid[i][j] = 1;
                    }
                }
            }

            int cnt= 0;
            for(int i =0; i<N; i++)
            {
                for(int j= 0; j<N; j++)
                {
                    if(grid[i][j] == 1 && visited[i][j] ==0)
                    {
                        dfs(grid, visited, i, j, N);
                        cnt++;
                    }
                }
            }
            if(max_cnt < cnt)
            {
                max_cnt = cnt;
            }
            
    }
    cout << max_cnt << endl;

    


    return 0;
}