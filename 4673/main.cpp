#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d(int n);
int d(int n)
{
    int ret = n;
    int N = n;
    while(true)
    {
        int a = N / 10;
        int b = N % 10;
        ret += b;
        N = a;
        if(a == 0)
        {
            break;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<bool> dp(10001, false);
    for(int n = 1; n <=10000; n++)
    {
        int dn = d(n);
        if(dp[dn])
        {
            continue;
        }
        else
        {
            dp[dn] = true;
        }
    }

    for(int n = 1; n <=10000; n++)
    {
        if(dp[n] == false)
        {
            cout << n << "\n";
        }
    }
    return 0;
}