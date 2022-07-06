#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> h(9,0);
    int psum[10] ={0,};
    for(int i= 0; i<9; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    int sum = 0;
    for(int i = 0; i<9; i++)
    {
        sum+=h[i];
    }
    for(int i=0; i<9; i++)
    {
        for(int j=i+1; j<9; j++)
        {
            if(sum -100 == h[i] + h[j])
            {
                for(int k =0; k<9; k++)
                {
                    if( k !=i && k !=j)
                    {
                        cout << h[k] << endl;
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}