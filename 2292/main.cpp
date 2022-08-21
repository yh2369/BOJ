#include <iostream>

using namespace std;

long long N;


long long solution(long long N)
{
    if(N == 1)
    {
        return 1;
    }

    long long lower_bound = 2;
    long long d = 1;
    while(true)
    {
        if(lower_bound <= N && N < lower_bound + 6*d)
        {
            return d + 1;
        }
        lower_bound = lower_bound + 6*d;
        d++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    long long ans = solution(N);
    cout << ans << "\n";

    return 0;
}