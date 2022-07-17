#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <cstring>
using namespace std;
int N, M;
vector<int> adj[10004];
int visited[10001] ={0,};
int dp[10001] ={0,};

int dfs(int here)
{
    visited[here] = 1;
    int ret = 1;
    if(adj[here].size() == 0)
    {
        return 1;
    }
    for(auto there : adj[here])
    {
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

void print_adj(int N)
{
    for(int i = 1; i<=N; i++)
    {
        cout << "[" << i << "]: ";
        for(int j = 0; j< adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    cin >> N >> M;
    for(int i =0; i<M; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[B].push_back(A);
    }

    set<int> answer;
    vector<int> nums(N+1,  0);
    int max_num = -1;
    for(int i = 1; i<=N; i++)
    {
        memset(visited, 0, sizeof(int) * (N+1));
        dp[i] = dfs(i);
        //cout << "dp[i]: " << dp[i] << endl;
        max_num = max(dp[i], max_num);
    }


    for(int i =1; i<=N;i++)
    {
        if(dp[i] == max_num)
        {
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}