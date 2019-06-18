#include<iostream>
#include<unordered_set>

using namespace std;

bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1)
        {
            cout << n << " ";
            if(st.count(n) == 1)
                return true;
            st.insert(n);
            int tmp = 0;
            while(n != 0)
            {
                int a = n % 10;
                tmp += (a * a);
                n = n / 10;
            }
            n = tmp;
        }
        return true;
    }

int main()
{
    isHappy(4);
    return 0;
}