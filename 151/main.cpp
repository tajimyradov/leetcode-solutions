#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int start = 0, end = 0;


        reverse(s.begin(), s.end());


        while (end < n)
        {
            while (end < n && s[end] != ' ')
            {
                end++;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = ++end;
        }


        string result;
        for (int i = 0; i < n; i++)
        {
            if (!(s[i] == ' ' && (i == 0 || s[i - 1] == ' ')))
            {
                result += s[i];
            }
        }
    
        result.erase(result.find_last_not_of(' ') + 1); 

        return result.empty() ? "" : result;
    }
};

int main()
{
    Solution solution;
    string s = "the sky is blue";
    cout << solution.reverseWords(s) << endl; 
    return 0;
}