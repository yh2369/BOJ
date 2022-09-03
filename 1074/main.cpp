#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int num = 0;

int recur(int r, int c, int N)
{
    if(N == 1)
    {
        if( r == 0 && c == 0)
        {
            return 0;
        }
        else if(r == 0 && c == 1)
        {
            return 1;
        }
        else if(r == 1 && c == 0)
        {
            return 2;
        }
        else if( r==1 && c==1)
        {
            return 3;
        }

    }

    int p = pow(2,N);
    int q = p/2;

    int ret = 0;
    if((0 <= r && r< q) && (0 <=c && c <q))
    {
        ret += recur(r, c, N-1);    
    }
    else if((0 <= r && r< q) && (q <=c && c <p))
    {
        ret += q*q;
        ret += recur(r, c-q, N-1);
    }
    else if((q <= r && r<p) && (0 <=c && c <q))
    {
        ret += q*q*2;
        ret += recur(r-q, c, N-1);
    }
    else if((q <= r && r<p) && (q<=c && c <p))
    {
        ret += q*q*3;
        ret += recur(r-q, c -q , N-1);
    }
    return ret;
    

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, c;
    cin >> N >> r >> c;
    cout << recur(r,c,N) << "\n";
    return 0;
}