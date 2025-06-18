#include <iostream>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int first = 0;
        int count = 0;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count++;
            while (count > k)
            {

                if (nums[first] == 0)
                    count--;
                first++;
            }
            if (mx < i - first+1)
            {
                mx = i - first+1;
            }
        }
        return mx;
    }
};

int main()
{
    Solution s;
    int k = 3;
    vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << s.longestOnes(nums, k);
}