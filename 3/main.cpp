#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==1)
            return 1;
        int i;
        int mx=0;
        unordered_map<char, bool> m;
        for (i = 0; i < s.length(); i++) {
            m.clear();
            int j = i;
            bool w = false;

            while (!w && j<=s.length()) {
                if (m[s[j]] || j>s.length()-1){
                    w = true;
                    mx=max(mx,j-i);
                }
                m[s[j]]=true;
                j++;
            }
        }

        return mx;
    }
};

int main() {
    Solution ss;
    cout << ss.lengthOfLongestSubstring(" ");
}