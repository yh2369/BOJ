#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int min3(int a, int b, int c);
void print2DV(vector<vector<int>>& v, int N, int M);

int min3(int a, int b, int c)
{
    int ret = a;
    if( ret > b)
    {
        ret = b;
    }
    if(ret > c)
    {
        ret = c;
    }
    return ret;
}

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<vector<int>> grid(10, vector<int>(10, 0));
    vector<vector<int>> dp(10, vector<int>(10, 0));
    vector<vector<bool>> checking_v(10, vector<bool>(10, false));
    bool all_zero = true;
    for(int i = 0; i< 10; i++)
    {
        for(int j =0; j< 10; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] != 0)
            {
                all_zero = false;
            }
        }
    }
    if(all_zero)
    {
        cout << 0 << '\n';
        return 0;
    }

    for(int j = 0; j<10; j++)
    {
        dp[0][j] = grid[0][j];
    }

    for(int i = 1; i<10; i++)
    {
        dp[i][0] = grid[i][0];
    }
    
    
    for(int i = 1; i<10; i++)
    {
        for(int j= 1; j<10; j++)
        {
            if(grid[i][j] == 1)
            {
                dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) % 5 + 1;
            }
        }
    }

    //print2DV(dp, 10, 10);
    int cnt = 0;

    vector<int> left_v(6, 5);
    for(int i = 9; i>=0; i--)
    {
        for(int j = 9; j>=0; j--)
        {
            if(checking_v[i][j] == true)
            {
                continue;
            }

            int len  = dp[i][j];
            int k; bool f = false;
            for(k = len; k>0; k--)
            {
                for(int a = 0; a<k; a++)
                {
                    for(int b = 0; b<k; b++)
                    {
                        if(checking_v[i-a][j-b] == true)
                        {
                            f = true;
                            break;
                        }
                    }
                    if(f == true)
                    {
                        break;
                    }
                }
            }
            len = k;

            bool flag = false;
            for(int k = len; k>0; k--)
            {
                if(left_v[k] > 0)
                {
                    left_v[k]--;
                    for(int a = 0; a<k; a++)
                    {
                        for(int b = 0; b<k; b++)
                        {
                            checking_v[i-a][j-b] = true;
                        } 
                    }
                    cnt++;
                    break;    
                }
                else
                {
                    flag = true;
                }
            }

            if(flag)
            {
                cout << -1 << '\n';
                return 0;
            }
            
        }
    }



    cout << cnt << '\n';
    return 0;
}