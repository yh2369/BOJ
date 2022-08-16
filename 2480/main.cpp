#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int A,B,C;
    cin >> A >> B>> C;
    int total_minute = A * 60 + B + C;
    int h = (total_minute / 60) % 24;
    int m = total_minute %60;
    cout << h <<" " <<  m << "\n";

    return 0;
}