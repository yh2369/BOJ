#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c)
{
    if(b == 1)
    {
        return a % c;
    }
    if(b == 2)
    {
        return(a*a)%c;
    }


    long long x = power(a,b/2, c);
    if(b & 1)
    {
        return (((x * x) % c) * a) % c;
    }
    else
    {
        return (x*x) % c;

    }
}

int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    cout << power(a,b,c) << endl;
    return 0;
}