#include<iostream>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int res = 0;
        while (s[i] == ' ')
            i++;
        if (!(s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')))
            return res;


        bool sign = false;
        if (s[i] == '-') {
            sign = true;
            i++;
        }
        if (s[i] == '+' && !sign) {
            sign = false;
            i++;
        }
        int rev = 214748364, count = 0, cur = 0;

        while (s[i] == '0')
            i++;

        while ((s[i] >= '0' && s[i] <= '9')) {
            switch (s[i]) {
                case '0':
                    cur = 0;
                    break;
                case '1':
                    cur = 1;
                    break;
                case '2':
                    cur = 2;
                    break;
                case '3':
                    cur = 3;
                    break;
                case '4':
                    cur = 4;
                    break;
                case '5':
                    cur = 5;
                    break;
                case '6':
                    cur = 6;
                    break;
                case '7':
                    cur = 7;
                    break;
                case '8':
                    cur = 8;
                    break;
                case '9':
                    cur = 9;
                    break;
            }


            if (res > rev) {
                if (sign)
                    return -2147483648;
                else
                    return 2147483647;
            }

            if (res == rev && sign && cur >= 8) {
//                    cout<<"1asdfasdfas";
                return -2147483648;
            }

            if (res == rev && !sign && cur >= 7) {
//                                    cout<<"2asdfsad";
                return 2147483647;
            }


            res = res * 10 + cur;
            i++;
            count++;
        }

        if (sign)
            return -res;
        else
            return res;
    }
};

int main() {

    Solution s;
    cout << s.myAtoi("-2147483648");
}