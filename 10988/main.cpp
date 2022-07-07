#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  string rs(n, ' ');
  for(int i =0; i<n; i++)
  {
      rs[i] = s[n-1 - i];
  }
  for(int i = 0; i< n; i++)
  {
    if(rs[i] != s[i])
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  
  return 0;
}