#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long X;
    cin >> X;
    int N;
    cin >> N;
    long long sum = 0;
    for(int i= 0; i<N; i++)
    {
        long long a, b;
        cin >> a >> b;
        sum += a * b;
    }
    if(sum == X)
    {
        cout <<"Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}