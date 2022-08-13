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

    for(int i = 2; i*i <= n ; i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i<N; i++)
    {
        int num;
        cin >> num;
        if(is_prime(num))
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}