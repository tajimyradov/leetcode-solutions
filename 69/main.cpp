#include<iostream>

using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int left = 1;
        int right = x;
        int mid=-1;
        while (left <= right) {
            mid = left+(right - left) / 2;

            long long square=static_cast<long long>(mid)*mid;
            if (square > x)
                right=mid-1;
            else if (square < x)
                left=mid+1;
            else return mid;
        }
        return static_cast<int>(std::round(right));
    }
};


int main() {
    Solution s;
    cout << s.mySqrt(4);
}