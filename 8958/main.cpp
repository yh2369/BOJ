#include <iostream>
#include <vector>
#include <string>

using namespace std;
int T;
int solution(string& s)
{
    int score = 0;
    int d = 1;
    int n = s.length();
    for(int i = 0; i< n; i++)
    {
        char c = s[i];
        if(c == 'O')
        {
            score += d;
            d++;
        }
        else
        {
            d = 1;
        }
    }
    return score;
}
int main()
{
    cin >> T;
    for(int i = 0; i< T; i++)
    {
        string s;
        cin >> s;
        int score = solution(s);
        cout << score <<"\n";
    }
    return 0;
}