#include <iostream>
#include <string>
using namespace std;
int main()
{
    int counter[26] = {0,};
    string S;
    cin >> S;
    int n = S.length();
    for(int i=0; i<n; i++)
    {
        char c = S[i];
        counter[c - 'a']++;
    }
    for(int i =0; i<26; i++)
    {
        cout << counter[i] <<" ";
    }
    cout << endl;
    return 0;
}