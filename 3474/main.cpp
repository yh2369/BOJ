#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i =0 ;i<N; i++)
    {
        long long num;
        cin >> num;
        long long zeros = 0;
        long long divisor = 5;
        while(true)
        {
            long long q = num / divisor;
            if(q == 0)
            {
                break;
            }
            zeros += q;
            divisor = divisor * 5;
        }
        cout << zeros << '\n';

    }
    return 0;
}