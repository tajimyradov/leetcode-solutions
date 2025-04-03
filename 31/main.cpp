#include<iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        for (auto v: nums) {
            cout << v << " ";
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    s.nextPermutation(v);
}