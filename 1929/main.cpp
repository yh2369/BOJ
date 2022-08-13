#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if(n == 1)
    {
        return false;
    }
    if(n == 2 || n == 3)
    {
        return true;
    }

    for(int i = 2; i*i <=n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int M, N;
    cin >> M >> N;
    for(int i =M; i<=N; i++)
    {
        if(is_prime(i))
        {
            cout << i << "\n";
        }
    }
    return 0;
}