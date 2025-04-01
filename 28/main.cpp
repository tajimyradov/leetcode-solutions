#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != string::npos)
            return found;

        return -1;
    }
};

int main() {
    Solution s;
    int res = s.strStr("tesdlfk", "dl");
    cout << res;
}