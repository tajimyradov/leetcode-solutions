#include <iostream>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int count = 0, mx = INT_MIN;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u')
            {
                count++;
            }

            if (i >= k)
            {
                if (s[i - k] == 'a' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'e' || s[i - k] == 'u')
                {
                    count--;
                }
            }

            if (count>mx)
            {
                mx=count;
            }
            
        }
        return mx;
    }
};

int main()
{
    Solution s;

    cout << s.maxVowels("abciiidef", 3);
}
