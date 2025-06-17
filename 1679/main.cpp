#include <iostream>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int res=0;
        int first = 0;
        int second = nums.size() - 1;
        while (second > first)
        {
            if (nums[first] + nums[second] == k)
            {
                res++;
                first++;
                second--;
            }
            else
            {
                if (nums[first] + nums[second] > k)
                    second--;
                else
                    first++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    vector<int> nums{1, 2, 3, 4};
    cout << s.maxOperations(nums, 5);
}