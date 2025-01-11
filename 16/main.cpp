#include<iostream>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int  diff = 0;

        if (nums.size() >= 3)
            diff = nums[0] + nums[1] + nums[2];

        if (nums.size() == 2)
            diff = nums[0] + nums[1];

        if (nums.size() == 1)
            diff = nums[0];


        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, p = nums.size() - 1;
            while (j < p) {
                int sum = nums[i] + nums[j] + nums[p];
                if (abs(sum - target) < abs(diff - target)) {
                    diff = sum;
                }
                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --p;
                } else {
                    return sum;
                }
            }
        }


        return diff;
    }
};


int main() {
    Solution s;
    vector<int> ss = {1, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
                      14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
                      14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
                      14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
                      14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
                      14, 14, 14, 15, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
                      19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
                      19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
                      19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
                      19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
                      19, 19, 19, 19, 19, 19, 19, 19, 29};
//    ss.push_back(-1);
//    ss.push_back(0);
//    ss.push_back(1);

//    ss.push_back(-1);
//
//    ss.push_back(1);
//    ss.push_back(2);
//
//    ss.push_back(-4);

//    ss.push_back(0);
//    ss.push_back(1);
//    ss.push_back(2);

//    ss.push_back(0);
//    ss.push_back(0);
//    ss.push_back(0);


//    ss.push_back(1);
//    ss.push_back(3);
//    ss.push_back(4);
//    ss.push_back(7);
//    ss.push_back(8);
//    ss.push_back(9);

//ss.push_back(2);
//ss.push_back(5);
//ss.push_back(6);
//ss.push_back(7);

    int res;
    res = s.threeSumClosest(ss, 45);
    cout << res;

}
