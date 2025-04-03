#include<iostream>

using namespace std;;

class Solution {
public:
    int lengthOfLastWord(string s) {
        s+=" ";
        string c;
        string last="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
                c+=s[i];
            else if (c!="") { last = c;c=""; }
        }
        return last.length();
    }
};

int main(){
    Solution s;
    cout<<s.lengthOfLastWord(" sdkl fjslkd fklsjdfh klsjdhf skjdh f");
}