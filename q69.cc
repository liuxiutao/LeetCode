#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int mySqrt(int x) {
    if(x == 0)
        return 0;
    int a = 1, b = x;
    while(true)
    {
        int m = (a + b)/2;
        
        if(x/m > m)
        {
            b = m - 1;
        }
        else if(m <= x/m && m+1 > x/(m+1))
            return m;
        else if(m+1 <= x/(m+1))
        {
            a = m + 1;
        }
        
    }
}
int newton(int x)
{
    long res = x;
    while(res * res > x)
    {
        res = (res + x / res)/2;
    }
    return res;
}
int main(int argc, char * argv[])
{
    int num = atoi(argv[1]);
    cout << mySqrt(num) << endl;
    return 0;
}