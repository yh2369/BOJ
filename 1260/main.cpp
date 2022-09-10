#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>


using namespace std;

void dfs(int here, vector<bool>& visited, vector<set<int>>& adj);
void bfs(int here, vector<int>& visited, vector<set<int>>& adj);

void dfs(int here, vector<bool>& visited, vector<set<int>>& adj)
{
    cout << here << " ";
    visited[here] = true;
    for(auto it = adj[here].begin(); it != adj[here].end(); it++)
    {
        int there = *it;
        if(!visited[there])
        {
            dfs(there, visited, adj);
        }
    }
}

void bfs(int here, vector<int>& visited, vector<set<int>>& adj)
{
    queue<int> q;
    q.push(here);
    visited[here] = 1;
    while(q.size())
    {
        int front = q.front();        
        cout << front << " ";

        for(auto it = adj[front].begin(); it != adj[front].end(); it++)
        {
            int there = *it;
            if(!visited[there])
            {
                q.push(there);
                visited[there] = visited[here] + 1;
            }
            
        }
        q.pop();
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M, V;
    cin >> N >> M >> V;
    vector<set<int>> adj(1001, set<int>());
    vector<bool> dfs_visited(1001, false);
    vector<int> bfs_visited(1001, 0);
    for(int i =0; i<M; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        adj[v1].insert(v2);
        adj[v2].insert(v1);
    }
    
    dfs(V, dfs_visited, adj);
    cout << "\n";
    bfs(V, bfs_visited, adj);
    cout << "\n";
    return 0;
}