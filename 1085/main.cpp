#include <iostream>
#include <algorithm>

using namespace std;


int x,y,w,h;
int main()
{
    cin >> x >> y >> w>> h;
    int dx = abs(x-w);
    int dy = abs(y-h);
    int a = min(dx, x);
    int b = min(dy, y);
    cout << min(a,b) << "\n";
    return 0;
}