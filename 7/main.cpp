#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        if(x<=-2147483648)
            return 0;
        bool sign=false;

        if (x<0)
            sign=true;

        x=abs(x);
        int rev=214748364;

        int res=0;
        int count=0;
        while(x>0){
            if(x/10==0 && count==9){
                if (res>rev){
//                    cout<<"1";
                    return 0;
                }

                if (sign && x%10>8){
//                    cout<<"2";
                    return 0;}
                if (!sign && x%10>7){
//                    cout<<"3";
                    return 0;}
            }
            res=res*10+x%10;
            x/=10;
            count++;
        }

        if (sign)
            return -res;
        else
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(-2147483648);
}