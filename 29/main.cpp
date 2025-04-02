#include <iostream>


using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor==1)
            return dividend;
        if (dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if (dividend==INT_MAX && divisor==-1)
            return -INT_MAX;

        bool sign;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            sign = false;
        else
            sign = true;

        dividend *= dividend > 0 ? -1 : 1;
        divisor *= divisor > 0 ? -1 : 1;

        int c = 0;
        while (dividend <= divisor) {
            c--;
            dividend -= divisor;
        }

        if (!sign && c<=-INT_MAX)
            return INT_MAX;
        else
            return (sign?1:-1)*c;
    }
};

int main() {

    Solution s;
//    int res = s.divide(INT_MIN,-1);
//    int res = s.divide(7,-3);
//    int res = s.divide(10,3);
//    int res = s.divide(INT_MIN,1);
    int res = s.divide(INT_MAX,-1);
//    int res = s.divide(1000000000,1);
    cout << res;
}