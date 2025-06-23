#include <iostream>

using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int r, d, n = senate.length()-1;
        queue<int> tr, td;
        for (int i = 0; i < senate.length(); i++)
            if (senate[i] == 'R')
                tr.push(1 + i);
            else
                td.push(i + 1);
        while (!tr.empty() && !td.empty())
        {
            if (tr.front() < td.front())
            {
                td.pop();
                r = ++n;
                tr.pop();
                tr.push(r);
            }
            else
            {
                tr.pop();
                d = ++n;
                td.pop();
                td.push(d);
            }
        }
        if (td.empty())
        {
            return "Radiant";
        }
        return "Dire";
    }
};

int main()
{
    Solution s;
    cout << s.predictPartyVictory("DRRDRDRDRDDRDRDR");
}