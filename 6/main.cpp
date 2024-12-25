#include<iostream>
#include<fstream>
using namespace std;


class Solution {
public:
    string convert(string s, int n) {
        int i,ii,jj;
        int a[s.length()+1];
        string res ="";
        for(i=0;i<=s.length();i++)
            a[i]=0;

        bool w=false;
        int j;
        int start =0;
        for(i=n-1;i>=1;i--){
            bool v= false;
            for (j=start;j<s.length();j+=(2*(i))) {
                res += s[j];
                a[j]=1;
                v=!v;
                if (w && !v)
                {
                    j+=2*((n-i)-1);
                    if(j>s.length()-1)
                        break;
                    res+=s[j];
                    a[j]=1;
                    v=!v;
                }
            }

            start++;
            w=true;

            res+="";
        }

        for(i=0;i<s.length();i++){

            a[i]==0?res+=s[i]:res;
        }

        return  res;
    }
};




int main(){
    string s;
    ifstream  fin("6/input.txt");
    int i,n,ii,jj=0;
    fin>>s>>n;


    Solution ss;
    cout<<ss.convert(s,n);

}