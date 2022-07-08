#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n ;
    cin >> n;
    vector<string> names(n,"");
    for(int i=0;i<n;i++)
    {
        cin >> names[i];
    }
    int counter[26] = {0,};
    for(int i= 0; i<n; i++)
    {
        char c = names[i][0];
        counter[c-'a']++;
    }
    vector<char> firstCharArr;
    bool predaja = true;
    for(int i =0; i<26; i++)
    {
        if(counter[i] >= 5)
        {
            predaja = false;
            firstCharArr.push_back('a' + i);
        }
    }
    if(predaja)
    {
        cout << "PREDAJA" << endl;
    }
    else
    {
        for(int i =0; i< firstCharArr.size(); i++)
        {
            cout << firstCharArr[i];
        }
        cout << endl;
    }
    return 0; 
}