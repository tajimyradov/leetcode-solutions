#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, long long int target) {
        if (nums.size() < 4)
            return vector<vector<int>>{};

        sort(nums.begin(), nums.end());
        int r, rr;
        int l, ll;
        long long int sum, num1, num2, num3, num4;

        vector<vector<int>> res;
        set<vector<int> > s;
        for (r = 0; r < nums.size() - 3; r++) {
            for (l = r + 3; l < nums.size(); l++) {
                rr = r + 1;
                ll = l - 1;

                while (rr < ll) {
                    num1 = nums[r];
                    num2 = nums[l];
                    num3 = nums[rr];
                    num4 = nums[ll];
                    sum = num1 + num2 + num3 + num4;
                    if (sum == target) {
                        s.insert({nums[r], nums[l], nums[rr], nums[ll]});
                        rr++;
                        ll--;
                    } else {
                        if (sum > target)ll--;
                        else rr++;
                    }
                }
            }
        }
        for (auto v: s)
            res.push_back(v);
        return res;
    }
};

int main() {

    vector<int> v = {1000000000, 1000000000, 1000000000, 1000000000};
    Solution s;
    vector<vector<int>> res;
    res = s.fourSum(v, 0);
    for (auto &re: res) {
        for (int j: re)
            cout << j << " ";
        cout << endl;
    }

}