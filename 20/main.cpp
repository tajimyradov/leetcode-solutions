#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<int> v;
        int i;
        for(i=0;i<s.length();i++){
            if (s[i]=='('){
                v.push_back(1);
                continue;
            }
            if(s[i]=='[') {
                v.push_back(2);
                continue;
            }
            if (s[i]=='{') {
                v.push_back(3);
                continue;
            }
            if ((s[i]==')' || s[i]=='}' || s[i] ==']' ) && v.size()<1)
                return false;
            if (s[i]==')' && v[v.size()-1]==1)
                v.pop_back();
            else{
                if (s[i]==']' && v[v.size()-1]==2)
                    v.pop_back();
                else{
                    if (s[i]=='}' && v[v.size()-1]==3)
                        v.pop_back();
                    else{
                        return false;
                    }
                }
            }
        }
        if (v.size()!=0)
            return false;
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isValid("([)]");
};
