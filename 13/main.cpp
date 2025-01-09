#include<iostream>

using namespace std;

class Solution {
public:
    int convert(char c) {
        switch (c) {
            case 'I':
                return 1;

            case 'V':
                return 5;

            case 'X':
                return 10;

            case 'L':
                return 50;

            case 'C':
                return 100;

            case 'D':
                return 500;

            case 'M':
                return 1000;

        }
        return 0;
    }

    int romanToInt(string s) {
        s+=" ";
        int res = 0;
        for (int i = 0; i < s.length()-1; i++) {
            if (convert(s[i])>= convert(s[i+1]))
                res+= convert(s[i]);
            else{
                res+= convert(s[i+1])- convert(s[i]);
                i++;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("MCMXCIV");
}