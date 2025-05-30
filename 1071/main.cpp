#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       
        if (str1 + str2 != str2 + str1) {
            return "";
        }


        int gcdLength = gcd(str1.length(), str2.length());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution;
    string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    string str2 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
    string result = solution.gcdOfStrings(str1, str2);
    cout << result << endl; 
}
