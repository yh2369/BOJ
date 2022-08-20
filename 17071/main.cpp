#include <iostream>
#include <queue>
using namespace std;

#define MAX_MAP 500000

int visited[2][MAX_MAP + 4], a, b, ok, turn = 1;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b;
    if(a == b) {cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1;
    q.push(a);
    while(q.size())
    {
        b += turn;
        if(b > MAX_MAP) break;
        if(visited[turn % 2 ][b])
        {
            ok = true;
            break;
        }
        int q_size =q.size();
        for(int i = 0;i<q_size; i++)
        {
            int x = q.front(); q.pop();
            for(int nx : {x+1, x-1, x *2})
            {
                if(nx <0 || nx >MAX_MAP || visited[turn%2][nx]) continue;
                visited[turn %2][nx] = visited[(turn+1) % 2][x] + 1;
                if(nx == b)
                {
                    ok = 1; break;
                }
                q.push(nx);
            }
            if(ok) break;
            
        }
        if(ok) break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}