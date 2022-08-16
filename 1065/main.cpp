#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_han(int n);
bool is_han(int n)
{
    if(n < 100)
    {
        return true;
    }
    
    int N = n;
    int q = N / 10;
    int r = N % 10;
    int delta = (q % 10) - r;
    int prev_delta = (q % 10)- r;
    N = q;
    while(N >= 10)
    {
        int q = N / 10;
        int r = N % 10;
        delta = (q % 10) - r;
        //cout << "delta: " << delta << "\n";
        //cout << "prev_delta: " << prev_delta << "\n";
        if(delta != prev_delta)
        {
            return false;
        }
        N = q;
        prev_delta = delta;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i= 1;i<=n; i++)
    {
        if(is_han(i))
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}