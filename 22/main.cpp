#include <iostream>
using namespace std;



class Solution {
public:
    void generate(int n, int open, int close, string s , vector<string> &res){
        if ( n==open && open==close){
            res.push_back(s);
        }

        if (open<n){
            generate(n,open+1,close,s+"(",res);
        }

        if (close<open)
            generate(n,open,close+1,s+")",res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        generate(n,0,0,"",res);

        return res;
    }
};


int main(){
    Solution s;
    vector<string> res;
    res=s.generateParenthesis(3);
    for(auto v : res){
        cout<<v<<endl;
    }
 }