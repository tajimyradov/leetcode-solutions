#include <iostream>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sumLeft = 0;
        int sum = 0;
        for (int n : nums)
            sum += n;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i>0)
            sumLeft += nums[i - 1];
            if (sum - sumLeft - nums[i] == sumLeft)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2,1,-1};
    cout << s.pivotIndex(nums);
}
