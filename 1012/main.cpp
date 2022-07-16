#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i=0;i<N; i++)
    {
        for(int j= 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
   
}

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int N, int M)
{
    visited[x][y] = 1;
    for(int i= 0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if(visited[nx][ny] == 0 && grid[nx][ny] == 1)
        {
            dfs(grid, visited, nx, ny, N, M);
        }
    }

} 

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        int M,N;
        cin >> M >> N;
        vector<vector<int>> grid(N, vector<int>(M, 0));
        vector<vector<int>> visited(N, vector<int>(M, 0));
        int K;
        cin >> K;
        for(int j = 0; j<K; j++)
        {
            int X, Y;
            cin >> Y >> X;
            grid[X][Y] = 1;
        }

        //print2DV(grid, N, M);
        int cnt = 0;

        for(int a = 0; a< N; a++)
        {
            for(int b = 0; b< M; b++)
            {
                if(grid[a][b] == 1 && visited[a][b] == 0)
                {
                    dfs(grid, visited, a, b, N, M);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
        

    }
    return 0;
}