#include <iostream>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string result;
        for (char c : s)
        {
            if (c == '*')
                result.pop_back();
            else
                result.push_back(c);
        }
        return result;
    }
};

int main()
{

    Solution s;
    cout << s.removeStars("empty*****");
}