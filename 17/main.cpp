#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if (digits.length()<1)
            return res;
        map<char, vector<char> > s;
        s['2'] = {'a', 'b', 'c'};
        s['3'] = {'d', 'e', 'f'};
        s['4'] = {'g', 'h', 'i'};
        s['5'] = {'j', 'k', 'l'};
        s['6'] = {'m', 'n', 'o'};
        s['7'] = {'p', 'q', 'r', 's'};
        s['8'] = {'t', 'u', 'v'};
        s['9'] = {'w', 'x', 'y', 'z'};

        vector<int> a;
        int i, j;
        for (i = 0; i < digits.length(); i++)
            a.push_back(0);

        string rr;
        while (a[0] <= s[digits[0]].size()) {
            rr="";
            for (j = 0; j < a.size(); j++)
                rr+= s[digits[j]][a[j]];
            res.push_back(rr);
            i = digits.length() - 1;

            a[i]++;

            while (a[i] > s[digits[i]].size()-1) {
                if (a[0]>s[digits[0]].size()-1)
                    return res;
                a[i] = 0;
                i--;


                a[i]++;
            }
        }


        return res;
    }
};

int main() {
    Solution s;

    vector<string> ss;
    ss = s.letterCombinations("");
    for (int i = 0; i < ss.size(); i++)
        cout << ss[i] << endl;
}