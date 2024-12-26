#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; 
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) { 
                return {m[complement], i};
            }
            m[nums[i]] = i; 
        }
        return {}; 
    }
};

int main() {
    Solution solution;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        cout << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}
