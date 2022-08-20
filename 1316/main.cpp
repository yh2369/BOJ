#include <iostream>
#include <string>
#include <set>

using namespace std;

int N;

bool is_group_word(string& s)
{
    set<char> seen;
    int len = s.length();
    if(len <= 1)
    {
        return true;
    }
    
    char prev_c = s[0];
    seen.insert(s[0]);
    for(int i = 1; i<len; i++)
    {
        char c = s[i];
        if(c != prev_c)
        {
            auto it = seen.find(c);
            if(it == seen.end())
            {
                seen.insert(c);
            }
            else
            {
                return false;
            }
        }
        prev_c = c;

    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    string word;
    int cnt = 0;
    for(int i = 0; i<N; i++)
    {
        cin >> word;
        if(is_group_word(word))
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}