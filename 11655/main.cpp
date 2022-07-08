#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos)
    {
        token=input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

string ROT13(string word)
{
    int n = word.length();
    string ret(n,' ');
    for(int i=0; i<n;i++)
    {
        char c = word[i];
        if('a' <= c && c <='z')
        {
            ret[i] = 'a' + ((c - 'a' + 13) % 26);
        }
        else if('A' <=c && c <= 'Z')
        {
            ret[i] = 'A' + ((c-'A' + 13) % 26);
        }
        else
        {
            ret[i] = c;
        }
    }
    return ret;
}

int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    auto ret = split(s, " ");
    string answer = "";
    for(int i=0; i<ret.size() - 1; i++)
    {
        answer += ROT13(ret[i]);
        answer += " ";
    }
    answer += ROT13(ret[ret.size() - 1]);
    cout << answer << endl;
    return 0;
}