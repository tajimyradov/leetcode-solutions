#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);


        for (int i = 1; i < n; i++) 
        {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int suffixProduct = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffixProduct *= nums[i + 1];
            result[i] *= suffixProduct;
        }
        

        return result;
    }
};


/// idea to shift the product of all elements to the right of each element
int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}