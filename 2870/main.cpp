#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

bool cmp(string s1, string s2)
{
    if(s1.length() < s2.length())
    {
        return true;
    }
    else if(s1.length() > s2.length())
    {
        return false;
    }
    else
    {
        int n = s1.length();
        for(int i =0; i<n; i++)
        {
            if(s1[i] < s2[i])
            {
                return true;
            }
            else if(s1[i] > s2[i])
            {
                return false;
            }
        }
    }
    return true;
    
}

void solution(string& s, vector<string>& a)
{
    string num ="";
    bool flag = false;
    for(int i = 0; i<s.length(); i++)
    {
        char c = s[i];
        if( 'a' <= c && c <= 'z')
        {
            if(flag)
            {
                a.push_back(num);
                num = "";
                flag = false;
            }
        }
        else
        {
            flag = true;
            if(num == "0")
            {
                num = string(1,c);
            }
            else
            {
                num = num + string(1, c);
            }
             
        }
    }
    if(flag)
    {
        a.push_back(num);
    }

}

int main()
{
    int N;
    cin >> N;

    vector<string> a;
    for(int i= 0; i<N; i++)
    {
        string s;
        cin >> s;
        solution(s,a);
    }
    sort(a.begin(), a.end(), cmp);
    for(int i =0; i<a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}