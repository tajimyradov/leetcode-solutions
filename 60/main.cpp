#include<iostream>
#include<sstream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        stringstream ss;

        for(int i=1;i<=n;i++)
            ss<<i;
        string s=ss.str();

        int i=1;
        do{
            if(i==k)
                break;
            i++;
        }while(next_permutation(s.begin(),s.end()));

        return s;
    }
};

int main(){
    Solution s;
    cout<<s.getPermutation(3,3);    
}