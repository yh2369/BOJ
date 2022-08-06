#include <iostream>
#include <vector>
#include <queue>
#include <cstring>


using namespace std;

const int dx[4] = {-1, 0 ,1, 0};
const int dy[4] = {0, -1, 0, 1};
char grid[54][54];
int visited[54][54];
int N, M;
int mx = 0;

void bfs(int x, int y);


void bfs(int x, int y)
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            visited[i][j] = 0;
        }
    }

    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x,y});
    while(q.size())
    {
        auto front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();
        for(int i = 0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny >= M) continue;

            if(visited[nx][ny]) continue;
            if(grid[nx][ny] == 'W') continue;
            visited[nx][ny]  = visited[x][y] + 1;
            q.push({nx,ny});
            mx = max(mx, visited[nx][ny]);
        }
    }
    return;

    


}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(grid[i][j] == 'L')
            {
                bfs(i,j);
            }
        }
    }
    cout << mx - 1 << "\n";




    return 0;
}