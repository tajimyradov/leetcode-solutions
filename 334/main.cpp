#include<iostream>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num; 
            } else {
                return true; 
            }
        }

        return false; 
    }
};


int main(){
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    bool result = solution.increasingTriplet(nums);
    
    cout << (result ? "true" : "false") << endl;

    return 0;
}