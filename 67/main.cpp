#include<iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int mn = min(a.length(), b.length());
        string res = "";
        char left = '0';
        int count = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < mn; i++) {
            if (a[i] == '0' and b[i] == '0') {
                res += left;
                left = '0';
            }
            else {
                count=0;
                if (a[i] == '1')count++;
                if (b[i] == '1')count++;
                if (left == '1')count++;
                if (count == 0) {
                    left = '0';
                    res += '0';
                }
                if (count == 1) {
                    left = '0';
                    res += '1';
                }
                if (count == 2 ) {
                    left = '1';
                    res += '0';
                }
                if (count == 3) {
                    left = '1';
                    res += '1';
                }
            }
        }

        if (a.length() == b.length() && left == '1')
            res += '1';
        else {
            string mx = a.length() > b.length() ? a : b;
            for (int i = mn; i < mx.length(); i++) {
                if (mx[i] == '0') {
                    res += left;
                    left = '0';
                }
                else if (mx[i] == '1' && left == '1') {
                    res += '0';
                    left = '1';
                }
                else {
                    res += '1';
                    left = '0';
                };
            }
            if (left=='1')
                res+=left;
        }


        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {

    Solution s;
    cout<<s.addBinary("1010","1011");

}