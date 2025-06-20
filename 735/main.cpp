#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> stack;
        for (int asteroid : asteroids)
        {
            if (asteroid > 0 || stack.empty() || stack.back() < 0)
            {
                stack.push_back(asteroid);
            }
            else
            {
                while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroid)
                {
                    stack.pop_back();
                }
                if (!stack.empty() && stack.back() == -asteroid)
                {
                    stack.pop_back();
                }
                else if (stack.empty() || stack.back() < 0)
                {
                    stack.push_back(asteroid);
                }
            }
        }
        return stack;
    }
};

int main()
{
    vector<int> v{-2, -2, 1, -2};
    Solution s;
    v = s.asteroidCollision(v);

    for (int w : v)
        cout << w << " ";
}