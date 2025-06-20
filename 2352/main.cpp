#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int count = 0;

        vector<string> rows;
        vector<string> cols;

        for (int i = 0; i < grid.size(); i++)
        {
            string r, c;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (r!="")
                {
                    r+=".";
                }
                if(c!="")
                {
                    c+=".";
                }
                
                r += to_string(grid[i][j]);
                c += to_string(grid[j][i]);
            }

            rows.push_back(r);
            cols.push_back(c);
        }

        int i = 0, j = 0;
        for (string m1 : rows)
        {
            for (string m2 : cols)
            {
                if (m1 == m2)
                {
                    count++;
                }
                j++;
            }
            i++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    // vector<int> row1{3, 1, 2, 2};
    // vector<int> row2{1, 4, 4, 5};
    // vector<int> row3{2, 4, 2, 2};
    // vector<int> row4{2, 4, 2, 2};
    //
    // vector<vector<int>> r;
    //
    // r.push_back(row1);
    // r.push_back(row2);
    // r.push_back(row3);
    // r.push_back(row4);

    // vector<int> row1{3, 2, 1};
    // vector<int> row2{1, 7, 6};
    // vector<int> row3{2, 7, 7};
    // vector<vector<int>> r;
    // r.push_back(row1);
    // r.push_back(row2);
    // r.push_back(row3);

    vector<int> row1{11,1};
    vector<int> row2{1,11};
    vector<vector<int>> r;
    r.push_back(row1);
    r.push_back(row2);

    cout << s.equalPairs(r);
}
