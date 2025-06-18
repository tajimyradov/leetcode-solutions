#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, bool> m1, m2;
        vector<int> r1;
        vector<int> r2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for (int v : nums1)
            m1[v] = true;
        for (int v : nums2)
        {
            m2[v] = true;
            if (!m1[v] && ( r2.size()==0 || r2[r2.size() - 1] != v))
                r2.push_back(v);
        }

        for (int v : nums1)
        {
            if (!m2[v] && (r1.size()==0 || r1[r1.size() - 1] != v))
                r1.push_back(v);
        }

        vector<vector<int>> res;
        res.push_back(r1);
        res.push_back(r2);
        return res;
    }
};

int main()
{
    Solution s;

    vector<int> nums1{1, 2, 3};
    vector<int> nums2{2, 4, 6};

    vector<vector<int>> res;
    res = s.findDifference(nums1, nums2);
    for (vector<int> r : res)
    {
        for (int v : r)
            cout << v << " ";
        cout << endl;
    }
}