#include <iostream>
using namespace std;

int a[15][15];
int T, k, n;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int j = 0; j< 15; j++)
    {
        a[0][j] = j;
    }
    for(int i = 1; i< 15; i++)
    {
        for(int j = 0; j< 15; j++)
        {
            a[i][j] = 0;
            for(int k = 0; k<=j; k++)
            {
                a[i][j] += a[i-1][k];
            }
        }
    }
    for(int i = 0; i< T; i++)
    {
        cin >> k >> n;
        cout << a[k][n] <<"\n";

    }
    return 0;
}