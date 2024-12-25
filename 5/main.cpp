#include <iostream>
using namespace std;

class Solution {
public:

    bool check(const string &s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int i, j;
        int maxLength = 1, start = 0;
        for(i=0;i<s.length();i++){
            for(j=0;j<s.length();j++){

                if (check(s, i, j) && (j - i + 1) > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }

            }
        }

        return s.substr(start, maxLength);
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
}