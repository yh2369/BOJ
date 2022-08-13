#include <iostream>

using namespace std;

int N,K;
int main()
{
    cin >> N >> K;
    if (K == 0 || K == N)
    {
        cout << 1 << "\n";
        return 0;
    }

    if(K == 1)
    {
        cout << N << "\n";
        return 0;
    }
    long long product = 1;
    for(long long i = N-K+1; i <= N; i++)
    {
        product = product *i;
    }   
    long long product2 = 1;
    for(long long j = 1; j<=K; j++)
    {
        product2 = product2 * j;
    }
    cout << product  / product2 << "\n";
    return 0;
}