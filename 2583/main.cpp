#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void printV(vector<int>& v)
{
    for(int i= 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i =0; i<N; i++)
    {
        for(int j= 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}

void dfs(vector<vector<int>>& paper, vector<vector<int>>& visited, int& area, int x, int y, int N, int M)
{
    visited[x][y] = 1;
    area++;
    for(int i =0 ; i< 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny <0 || ny >=M) continue;

        if(visited[nx][ny] == 0 && paper[nx][ny] == 1)
        {
            dfs(paper, visited, area, nx, ny, N, M);
        }
    }

}

int main()
{
    int N, M, K;
    cin >> M >> N >> K;

    vector<vector<int>> paper(N, vector<int>(M, 1));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for(int a = 0; a <K; a++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<x2; i++)
        {
            for(int j= y1; j<y2; j++)
            {
                paper[i][j] = 0;
            }
        }
        
    }

    //print2DV(paper, N, M);
    vector<int> area_v;
    int cnt = 0;
    for(int i =0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(paper[i][j] == 1 && visited[i][j] == 0)
            {
                int area = 0;
                dfs(paper, visited, area, i, j , N, M);
                area_v.push_back(area);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    sort(area_v.begin(), area_v.end());
    printV(area_v);

    return 0;
}