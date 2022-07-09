#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    string token = "" ;
    long long pos = 0;
    while( (pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;   
}

int main()
{
    string name;
    cin >> name;
    int counter[26] = {0,};
    int n = name.length();
    for(int i =0; i< n; i++)
    {

    }

    return 0;
}