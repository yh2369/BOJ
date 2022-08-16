#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*
    6
    8 4
    13 19
    8 10
    18 18
    8 25
    13 16
    
    1780000
    620000
    1140000
    420000
    820000
    620000
    */
    int T;
    cin >> T;
    for(int i =0; i<T; i++)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if( a == 0)
        {
            ans += 0;
        }
        else if(a <= 1)
        {
            ans += 5000000;
        }
        else if( a <= 3)
        {
            ans += 3000000;
        }
        else if(a <=6)
        {
            ans+=2000000;
        }
        else if(a <=10)
        {
            ans += 500000;
        }
        else if( a<=15)
        {
            ans +=300000;
        }
        else if( a<= 21)
        {
            ans+=100000;
        }
        
        if(b == 0)
        {
            ans += 0;
        }
        else if(b <= 1)
        {
            ans += 5120000;
        }
        else if( b <= 3)
        {
            ans += 2560000;
        }
        else if( b <=7)
        {
            ans +=1280000;
        }
        else if( b<=15)
        {
            ans += 640000;
        }
        else if(b <= 31)
        {
            ans += 320000;
        }
        cout << ans << "\n";
    }
    return 0;
}