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
vector<int> cnt(100004, 0);

void bfs(int X, int K)
{
    queue<int> q;
    q.push(X);

    while(q.size())
    {
        int X  = q.front();
        q.pop();
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
                cnt[next_X] += cnt[X];
                q.push(next_X);
            }
            else if(visited[next_X] == visited[X] + 1)
            {
                cnt[next_X] += cnt[X];
            }
        }
    }
}



int main()
{
    fastIO();
    cin >> N >> K;
    cnt[N] = 1;
    if(N == K)
    {
        cout << "0\n1\n";
        return 0;
    }
    bfs(N, K);
    cout << visited[K] << "\n" << cnt[K] << "\n";

    
    return 0;
}