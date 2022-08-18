#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   
} 
int N, K;

vector<int> visited(100004, 0);
vector<int> visited2(100004, 0);

void bfs(int X, int K)
{
    queue<int> q;
    q.push(X);

    while(q.size())
    {
        int front  = q.front();
        q.pop();
        int X = front;
        for(int i = 0; i<3; i++)
        {
            int next_X;
            if(i == 0)
            {
                next_X = X - 1;
            }
            else if( i == 1)
            {
                next_X = X + 1;
            }
            else
            {
                next_X = X * 2;
            }

            if(next_X < 0 || next_X > 100000) continue;

            if (visited[next_X] == 0)
            {
                visited[next_X] = visited[X] + 1;
                q.push(next_X);
            }
            if(next_X == K)
            {
                return;
            }
        }
    }
}

int bfs2(int X, int K, int min_time)
{
    int ret = 0;
    queue<int> q;
    q.push(X);
    while(q.size())
    {
        
        auto X = q.front();
        //cout << "X: " << X << "\n";
        q.pop();
        if (visited2[X] == min_time)
        {
            continue;
        }

        for(int i = 0; i< 3; i++)
        {
            int next_X = -1;
            if( i == 0)
            {
                next_X = X - 1;
            }
            else if( i == 1)
            {
                next_X = X + 1;
            }
            else if( i == 2)
            {
                next_X = X * 2;
            }
            if(next_X < 0 || next_X > 100000)
            {
                continue;
            }
            
            if(visited2[X] + 1 == min_time && next_X == K)
            {
                ret++;
            }

            if(visited2[next_X]) continue;

            visited2[next_X] = visited2[X] + 1;
            //cout << "visited2[next_X]: " << visited2[next_X] << "\n";
        
            q.push(next_X);
        }

    }
    return ret;

}


int main()
{
    fastIO();
    cin >> N >> K;
    if(N == K)
    {
        cout << "0\n0\n";
        return 0;
    }
    bfs(N, K);
    int min_time = visited[K];
    
    int cnt = bfs2(N, K, min_time);
    cout << min_time << "\n" << cnt << "\n";

    
    return 0;
}