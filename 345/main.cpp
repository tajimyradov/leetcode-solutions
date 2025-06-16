#include<iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string vowels = "aeiouAEIOU";
        
        while (left < right) {
            while (left < right && vowels.find(s[left]) == string::npos) {
                left++;
            }
            while (left < right && vowels.find(s[right]) == string::npos) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};



int main() {
    Solution solution;
    string s = "hello";
    cout << solution.reverseVowels(s) << endl; 
    return 0;
}