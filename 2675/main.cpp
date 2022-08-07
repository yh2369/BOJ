#include <iostream>
#include <string>

using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        int R;
        cin >>R;
        string s;
        cin >> s;
        int n = s.length();
        string ans = "";
        for(int j = 0; j<n; j++)
        {
            for(int k = 0; k<R; k++)
            {
                ans += s[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}