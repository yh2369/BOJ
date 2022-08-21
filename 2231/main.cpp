#include <iostream>
#include <vector>


using namespace std;

int dsum(int X)
{
    int ret = X;
    
    int q, r;
    while(X > 0)
    {

        q = X / 10;
        r = X % 10;
        ret += r;
        X = q;
    }
    return ret;
}

int N;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++)
    {
        if(dsum(i) == N)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}