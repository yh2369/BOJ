#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool cmp_str(string s1, string s2);

bool cmp_str(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1 < len2)
    {
        return true; 
    }
    else if(len1 == len2)
    {
        for(int i =0; i<len1; i++)
        {
            if(s1[i] < s2[i])
            {
                return true;
            }
            else if(s1[i] == s2[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int N;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    set<string> str_set;
    for(int i = 0; i<N; i++)
    {
        string s;
        cin >> s;
        str_set.insert(s);
    }

    vector<string> v;
    for(auto it = str_set.begin(); it != str_set.end(); it++)
    {
        string s = *it;
        v.push_back(s);
    }


    sort(v.begin(), v.end(), cmp_str);

    int v_size = v.size();
    for(int i =0; i<v_size; i++)
    {
        cout << v[i] << "\n";
    }

    return 0;

}