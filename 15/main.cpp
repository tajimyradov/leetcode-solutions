#include<iostream>
#include<map>
#include<set>

using namespace std;

class Solution {
public:

    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i;
        vector<vector<int> > res;
        set<vector<int> > s;

        for (i = 0; i < nums.size(); i++) {
            if (i>0 && nums[i]==nums[i-1])
                continue;
            int j = i + 1, p = nums.size() - 1;
            int sum;
            while (p > j) {

                sum = nums[i] + nums[j] + nums[p];
                if (sum == 0) {
                    vector<int> ss;
                    ss.push_back(nums[i]);
                    ss.push_back(nums[j]);
                    ss.push_back(nums[p]);
                    s.insert(ss);
                    j++;
                    p--;
                } else if (sum > 0)p--;
                else j++;
            }
        }
        for(auto v:s)
            res.push_back(v);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> ss;
//    ss.push_back(-1);
//    ss.push_back(0);
//    ss.push_back(1);

    ss.push_back(-1);
    ss.push_back(0);
    ss.push_back(1);
    ss.push_back(2);
    ss.push_back(-1);
    ss.push_back(-4);

    vector<vector<int> > res;
    res = s.threeSum(ss);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
