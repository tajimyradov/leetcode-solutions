#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string current = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                counts.push(k);
                result.push(current);
                k = 0;
                current = "";
            } else if (ch == ']') {
                int repeat = counts.top(); counts.pop();
                string prev = result.top(); result.pop();
                while (repeat--) {
                    prev += current;
                }
                current = prev;
            } else {
                current += ch;
            }
        }
        return current;
    }
};


int main()
{
    Solution s;
    cout << s.decodeString("3[a2[c]]") << endl; // Expected output: "accaccacc"
}