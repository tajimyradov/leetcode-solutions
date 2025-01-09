#include<iostream>

using namespace std;

class Solution {
public:
    string addString(string c, int n){
        string s;

        for(int i=1;i<=n;i++)
            s+=c;

        return s;
    }

    string intToRoman(int num) {
        string s;
        bool w = false;
        int n = 0;
        int r=0;
        if (!w && num >= 1000) {
            w = true;
            n = 1000;
        }

        if (!w && num >= 100) {
            w = true;
            n = 100;
        }

        if (!w && num >= 10) {
            w = true;
            n = 10;
        }

        if (!w && num>=1){
            w=true;
            n=1;
        }

        while(n>0){
            r=num/n%10;

            if (r>0 && n==1000){
                s+= addString("M",r);
            }

            if (n==100){
                if (r==9)
                    s+="CM";
                if (r==5)
                    s+="D";
                if (r==4)
                    s+="CD";
                if(r<4)
                    s+= addString("C",r);
                if(r> 5 && r<9)
                    s+="D"+ addString("C",r-5);
            }


            if (n==10){
                if (r==9)
                    s+="XC";
                if (r==5)
                    s+="L";
                if (r==4)
                    s+="XL";
                if(r<4)
                    s+= addString("X",r);
                if(r> 5 && r<9)
                    s+="L"+ addString("X",r-5);
            }

            if (n==1){
                if (r==9)
                    s+="IX";
                if (r==4)
                    s+="IV";
                if (r==5)
                    s+="V";
                if(r<4)
                    s+= addString("I",r);
                if(r> 5 && r<9)
                    s+="V"+ addString("I",r-5);
            }


            n/=10;
        }

        return s;
    }
};


int main() {
    Solution s;
    cout << s.intToRoman(3891);
}