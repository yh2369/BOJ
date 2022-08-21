#include <iostream>

using namespace std;

long long A, B, V;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> A >> B >> V;
    if( A >= V)
    {
        cout << "1\n";
        return 0;
    }
    long long delta = A - B;
    long long H = V-A;
    //cout << "H: " << H << "\n";
    long long q = H / delta;
    long long r = H % delta;
    if(r == 0)
    {
        cout << q + 1 << "\n";
    }
    else
    {
        cout << q + 2 << "\n";
    }

    return 0;
}