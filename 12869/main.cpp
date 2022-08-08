#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int N;
int dp[64][64][64];
int hp[3];

int min6(int x0, int x1, int x2, int x3, int x4,int x5)
{
    int y0 = min(x0,x1);
    int y1 = min(y0, x2);
    int y2 = min(y1, x3);
    int y3= min(y2, x4);
    int y4 = min(y3, x5);
    return y4;
} 

int main()
{
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> hp[i];
    }

    for(int i = 0; i< 64; i++)
    {
        for(int j = 0; j< 64; j++)
        {
            for(int k = 0; k< 64; k++)
            {
                dp[i][j][k]= 0;
            }
        }
    }

    for(int i = 0; i<= 9; i++)
    {
        for(int j = 0; j<= 9; j++)
        {
            for(int k = 0; k<= 9; k++)
            {
                if(i == 0 && j ==0 & k == 0) continue;

                if(i <= 9 && j <=3 && k <=1)
                {
                    dp[i][j][k] = 1;
                }
                if(i <= 9 && j <=1 && k <=3)
                {
                    dp[i][j][k] = 1;
                }
                if(i <= 3 && j <=9 && k <=1)
                {
                    dp[i][j][k] = 1;
                }
                if(i <=1 && j <=9 && k <=3)
                {
                    dp[i][j][k] = 1;
                }
                if(i <=3 && j <=1 && k <=9)
                {
                    dp[i][j][k] = 1;
                }
                if(i <= 1 && j <=3 && k <=9)
                {
                    dp[i][j][k] = 1;
                }
            }
        }
    }

    int x = hp[0];
    int y = hp[1];
    int z = hp[2];
    for(int i = 0; i<= x ; i++)
    {
        for(int j = 0; j<= y; j++)
        {
            for(int k = 0; k<= z; k++)
            {
                if(i == 0 && j == 0 && k == 0) continue;

                if(dp[i][j][k] == 0)
                {
                    int x0 = (i-9) >= 0 ? (i-9) : 0; 
                    int y0 = (j-3) >= 0 ? (j-3) : 0;
                    int z0 = (k-1) >= 0 ? (k-1) : 0;

                    int x1 = (i-9) >= 0 ? (i-9) : 0; 
                    int y1 = (j-1) >= 0 ? (j-1) : 0;
                    int z1 = (k-3) >= 0 ? (k-3) : 0;

                    int x2 = (i-3) >= 0 ? (i-3) : 0; 
                    int y2 = (j-9) >= 0 ? (j-9) : 0;
                    int z2 = (k-1) >= 0 ? (k-1) : 0;

                    int x3 = (i-1) >= 0 ? (i-1) : 0; 
                    int y3 = (j-9) >= 0 ? (j-9) : 0;
                    int z3 = (k-3) >= 0 ? (k-3) : 0;

                    int x4 = (i-3) >= 0 ? (i-3) : 0; 
                    int y4 = (j-1) >= 0 ? (j-1) : 0;
                    int z4 = (k-9) >= 0 ? (k-9) : 0;

                    int x5 = (i-1) >= 0 ? (i-1) : 0; 
                    int y5 = (j-3) >= 0 ? (j-3) : 0;
                    int z5 = (k-9) >= 0 ? (k-9) : 0;

                    dp[i][j][k] = 1+ min6(dp[x0][y0][z0],dp[x1][y1][z1],dp[x2][y2][z2],dp[x3][y3][z3],dp[x4][y4][z4],dp[x5][y5][z5]);
                }
            }
        }
    }


    int ans = dp[hp[0]][hp[1]][hp[2]];
    cout << ans << "\n";

    return 0;
}