#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
#define MAX_N 200004
int visited[MAX_N];
int _prev[MAX_N];
vector<int> v;

void bfs(int N, int K)
{
    
    visited[N] = 1;
    queue<int> q;
    q.push(N);
    while(q.size())
    {
        int X = q.front();
        q.pop();

        for(int i = 0; i<3; i++)
        {
            int Y;
            if(i == 0)
            {
                Y = X - 1;
            }
            else if ( i == 1)
            {
                Y = X + 1;
            }
            else
            {
                Y = X * 2;
            }

            if(Y < 0 || Y >= MAX_N)
            {
                continue;
            }

            if(!visited[Y])
            {
                visited[Y] = visited[X] + 1;
                _prev[Y] = X;
                q.push(Y);
                if(Y == K)
                {
                    break;
                }

            }
        }
    }

    for(int i = K; i != N; i = _prev[i])
    {
        v.push_back(i);
    }
    v.push_back(N);
    cout << visited[K] - 1 << "\n";
    reverse(v.begin(), v.end());
    for(int i : v)
    {
        cout << i << " ";
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    if(N == K)
    {
        cout << "0\n" << N << "\n";
    }
    else
    {
        bfs(N, K);
    }


    return 0;
}