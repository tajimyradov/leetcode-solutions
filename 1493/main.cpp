#include <iostream>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int first = 0;
        int count = 0;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count++;
            while (count > 1)
            {

                if (nums[first] == 0)
                    count--;
                first++;
            }
            if (mx < i - first )
            {
                mx = i - first ;
            }
        }
        return mx;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 1, 0, 1};
    cout << s.longestSubarray(nums);
}