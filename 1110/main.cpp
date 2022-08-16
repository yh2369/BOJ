#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    int a,b;
    int c = N;
    while(true)
    {
        a = c/10;
        b = c %10;
        c = b * 10 + ((a+b) % 10);
        cnt++;
        if(c == N)
        {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}