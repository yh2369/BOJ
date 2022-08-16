#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    if(x == y && y == z){
        cout << 10000 + x * 1000 << "\n";
    }
    else if(x != y && y!=z && z!=x)
    {
        int m = max(x,y);
        m = max(m,z);
        cout << m * 100 << "\n";
    }
    else
    {
        if(x == y){
            cout << 1000 + x * 100 <<"\n";
        }
        else if(x == z)
        {
            cout << 1000 + x * 100 <<"\n";
        }
        else
        {
            cout << 1000 + y * 100 <<"\n";
        }
    }
    return 0;
}