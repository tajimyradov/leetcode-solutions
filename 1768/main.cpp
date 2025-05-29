#include<iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      int sumLen=word1.length()+word2.length();
      int i=0,j=0;
      string res="";
      while (res.length()<sumLen) {
        if (i<word1.length() )
          {res+=word1[i]; i++;}
        if (j<word2.length())
          {res+=word2[j]; j++;}
      }

      return res;
    }
};

int main(){
  Solution s;
  cout<<s.mergeAlternately("", "bbb");
}