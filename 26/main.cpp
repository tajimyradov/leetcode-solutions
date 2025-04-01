#include<iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 1)return 1;
        int k = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > last) {
                last = nums[i];
                swap(nums[i],nums[k]);
                k++;
            }
        }

        return k;

    }
};

int main() {
    Solution s;
    vector<int> p = {1, 2, 2, 2, 3, 3, 3, 4, 5, 6};
    int res = s.removeDuplicates(p);
    cout << res<<endl;

    for (int i = 0; i < p.size(); i++)
        cout<<p[i]<<" ";
}