#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R,C;

char grid[1004][1004];
int fire_visited[1004][1004];
int j_visited[1004][1004];
int dx[4] ={-1,0,1,0};
int dy[4] = {0, -1, 0, 1};

void print_fire_visited();
void print_j_visited();
void fire_bfs(queue<pair<int,int>>& q);

void fire_bfs(queue<pair<int,int>>& q)
{
    while(q.size())
    {
        auto front = q.front();
        int x = front.first;
        int y = front.second;
        for(int i = 0; i< 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >=C)
            {
                continue;
            }

            if(grid[nx][ny] == '#')
            {
                continue;
            }

            if(fire_visited[nx][ny])
            {
                continue;
            }

            fire_visited[nx][ny] = fire_visited[x][y] + 1;
            q.push({nx, ny});
        }
        q.pop();
    }
}

void print_fire_visited()
{
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            cout << fire_visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_j_visited()
{
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            cout << j_visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i< R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
        }
    }

    queue<pair<int,int>> q;
    queue<pair<int,int>> jq;
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            if(grid[i][j] == 'F')
            {
                fire_visited[i][j] = 1;
                q.push({i,j});
            }

            if(grid[i][j] == 'J')
            {
                j_visited[i][j]  =1;
                jq.push({i,j});
            }
        }
    }

    fire_bfs(q);
    //print_fire_visited();

    int ans=0;
    while(jq.size())
    {
        auto front = jq.front();
        int x = front.first;
        int y = front.second;
        //cout << "x: " << x << " y: " << y << "\n";
		if(x == R-1 || y == C-1 || x == 0 || y == 0){
            ans = j_visited[x][y];
            break;
		}

        for(int i = 0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >=C)
            {
                continue;
            }

            if(grid[nx][ny] == '#')
            {
                continue;
            }

            if(j_visited[nx][ny])
            {
                continue;
            }

            if(fire_visited[nx][ny] > 0 && (j_visited[x][y] + 1 >= fire_visited[nx][ny]))
            {
                continue;
            }

            j_visited[nx][ny] = j_visited[x][y] + 1;
            jq.push({nx, ny});
        }

        //print_j_visited();
        jq.pop();
    }




    if(ans == 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}