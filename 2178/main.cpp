#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {-1, 0,1, 0};
const int dy[4] = {0, -1, 0, 1};

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int N, int M, int ix, int iy)
{
    visited[ix][iy] = 1;
    queue<pair<int, int>> q;
    q.push({ix, iy});
    while(!q.empty())
    {
        int x, y;
        auto e = q.front();
        x = e.first;
        y = e.second;
        //cout << "x: " << x << " y: " << y << endl;
        q.pop();
        if(x == N-1 && y == M-1)
        {
            break;
        }
        for(int i =0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //cout << "nx: " << nx << " ny: " << ny << endl;
            if(nx < 0 || nx >= N || ny <0 || ny >=M) continue;

            if(grid[nx][ny] == 1 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    const int default_value = 0;

    vector<vector<int>> grid(N, vector<int>(M, default_value));
    vector<vector<int>> visited(N, vector<int>(M, default_value));


    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<M; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    //print2DV(grid, N, M);

    
    bfs(grid, visited, N, M, 0, 0);

    //cout << endl;
    //print2DV(visited, N, M);

    cout << visited[N-1][M-1] << endl;
    return 0;
}