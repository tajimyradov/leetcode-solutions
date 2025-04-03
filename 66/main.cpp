#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        digits[0]++;
        int size = digits.size();
        int i = 0;
        while (digits[i] > 9) {
            digits[i] = digits[i] - 10;
            if (size == i+1)
                digits.push_back(1);
            else digits[i+1] += (digits[i] +10 )/10;
            i++;

        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> v = {9,9,9};
    v = s.plusOne(v);
    for (auto i: v)
        cout << i << " ";
}