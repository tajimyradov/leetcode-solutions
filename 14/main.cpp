#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,min_i=0;
        string res ="";
        for(i=0;i<strs.size();i++)
            if (strs[i].length()<strs[min_i].length())
                min_i=i;

        for(i=0;i<strs[min_i].length();i++){
            for (int j = 0; j <strs.size() ; j++) {
                if (strs[min_i][i]!=strs[j][i]){
                    return res;
                }
            }
            res+=strs[min_i][i];
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<string> ss;
    ss.push_back("dog");
    ss.push_back("racecar");
    ss.push_back("car");
    cout<<s.longestCommonPrefix(ss);
}