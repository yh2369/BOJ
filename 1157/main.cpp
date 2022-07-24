#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    int n = s.length();
    for(int i = 0; i< n ; i++)
    {
        int index;
        if('A'<=s[i] && s[i] <='Z')
        {
            index = s[i] - 'A';
        }
        else
        {
            index = s[i] - 'a';
        }
        cnt[index]++;
    }
    
    bool dup = false;

    int max_index = 0;
    int max_cnt = cnt[0];
    for(int i = 1; i< 26; i++)
    {
        if(max_cnt < cnt[i])
        {
            max_cnt = cnt[i];
            max_index = i;
        }
    }

    sort(cnt.begin(), cnt.end());
    if(cnt[25] == cnt[24])
    {
        dup = true;
    }

    if(dup)
    {
        cout << "?\n";
    } 
    else
    {
        cout << (char)(max_index + 'A') << "\n";
    }
    return 0;
}