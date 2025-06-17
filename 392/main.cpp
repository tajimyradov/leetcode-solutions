#include <iostream>



using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
                int sIndex = 0, tIndex = 0;

        while (sIndex < s.size() && tIndex < t.size()) {
            if (s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }

        return sIndex == s.size();        
    }
};


int main() {
    Solution solution;
    string s = "bc";
    string t = "ahbgdc";
    bool result = solution.isSubsequence(s, t);
    
    cout << (result ? "true" : "false") << endl;

    return 0;
}