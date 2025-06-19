#include <set>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }

        map<char, int> m1, m2;

        set<char> s1, s2;

        for (char c : word1)
        {
            m1[c]++;
            s1.insert(c);
        }
        for (char c : word2)
        {
            m2[c]++;
            s2.insert(c);
        }

        if (s1 != s2)
            return false;

        vector<int> v1, v2;
        for (pair<char, int> c : m1)
            v1.push_back(c.second);

        for (pair<char, int> c : m2)
            v2.push_back(c.second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1 != v2)
        {

            return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.closeStrings("asdf", "fdsa");
}