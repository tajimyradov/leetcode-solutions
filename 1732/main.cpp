#include <iostream>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int sum = 0, mx = 0;
        for (auto g : gain)
        {
            sum += g;
            mx = max(sum, mx);
        }
        return mx;
    }
};

int main()
{
    Solution s;
    vector<int> gain {-4,-3,-2,-1,4,3,2};

    cout<<s.largestAltitude(gain);
}