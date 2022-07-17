#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

void combi(int n, int k, int start, vector<int>& b, vector<vector<int>> &dst)
{
    if(k == b.size())
    {
        dst.push_back(b);
        return;
    }
    
    for(int i = start+1; i<n; i++)
    {
        b.push_back(i);
        combi(n,k, i, b, dst);
        b.pop_back();
    }
}

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i =0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

void spread_virus(vector<vector<int>>& grid, int N, int M, int x, int y)
{
    for(int i =0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny <0 || ny >=M)
        {
            continue;
        }
        if(grid[nx][ny] == 0)
        {
            grid[nx][ny] = 2;
            spread_virus(grid, N, M, nx, ny);
        } 
    }

}

int safe_area(vector<vector<int>>& grid, int N, int M)
{
    int area = 0;
    for(int i =0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(grid[i][j] == 0)
            {
                area++;
            }
        }
    }
    return area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, int>> zeros;

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(grid[i][j] == 0)
            {
                zeros.push_back({i,j});
            }
        }
    }

    int max_a = 0;
    int n = zeros.size();
    vector<int> b;
    vector<vector<int>> dst;
    combi(n, 3, -1, b, dst);

    for(int i=0; i<dst.size(); i++)
    {  
        for(int j = 0; j<3; j++)
        {
            auto pos_index = dst[i][j];
            auto pos = zeros[pos_index];
            int x = pos.first;
            int y = pos.second;
            grid[x][y] = 1;
        }

        // calculate safe area
        auto grid_cpy = grid;
        for(int x = 0; x< N; x++)
        {
            for(int y = 0; y< M; y++)
            {
                if(grid_cpy[x][y] == 2)
                {
                    spread_virus(grid_cpy, N, M, x ,y);
                }
            }
        }
        int a = safe_area(grid_cpy, N, M);
        //cout << "safe area: " << a << "\n";
        if(max_a < a)
        {
            max_a = a;
        }



        for(int j = 0; j<3; j++)
        {
            auto pos_index = dst[i][j];
            auto pos = zeros[pos_index];
            int x = pos.first;
            int y = pos.second;
            grid[x][y] = 0;
        }

    }
    cout << max_a << '\n';
 

    return 0;
}
