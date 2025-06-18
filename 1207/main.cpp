#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> m;
        for (int v : arr)
            m[v]++;

        map<int, bool> s;

        for (pair<int, int> c : m)
        {
            if (s[c.second] == true)
            {
                return false;
            }
            s[c.second] = true;
        }

        return true;
    }
};

int main()
{
    vector<int> nums{1, 2, 2, 1, 1, 3};
    Solution s;
    cout << s.uniqueOccurrences(nums);
}