#include <iostream>

using namespace std;

long long solution(long long n)
{
    long long ret = 1;
    long long m = 1;
    while(true)
    {
        if(m % n == 0)
        {
            return ret;
        }
        m = m*10 + 1;
        m = m%n;
        ret++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n ;
    while(cin >> n)
    {
        cout << solution(n) << endl;
    }
    return 0;
}