#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const long long r = 31;
const long long M = 1234567891;
int L;
string s;
long long dp[54];


long long power(long long r, long long i)
{
    dp[0] = 1;
    dp[1] = r;
    dp[2] = r * r;
    for(int j = 3; j<=i; j++)
    {
        dp[j] = (dp[j-1] * r) % M;
    }
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> L >> s;
    long long H = 0LL;
    for(long long i= 0; i<L; i++)
    {
        long long term = (s[i] - 'a' + 1) *power(r,i);
        term = term % M;
        H = (H + term) % M;
    }
    cout << H << "\n";
    return 0;
}