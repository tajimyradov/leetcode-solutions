#include<iostream>
#include<unordered_map>

using namespace std;

//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string> &words) {
//        vector<int> res;
//        if (words.size() == 0)
//            return res;
//        if (s.length() == 0)
//            return res;
//
//        unordered_map<string, int> m, M;
//        for (int i = 0; i < words.size(); i++)
//            m[words[i]]++;
//
//        int wordLength = words[0].length();
//        int count = words.size();
//        int ii = 0;
//        int jj = ii + count * wordLength;
//        while (jj <= s.length()) {
//            int tCount = 0;
//            M = m;
//            for (int i = ii; i <= jj - wordLength; i += wordLength) {
//
//                string c = s.substr(i, wordLength);
//                if (M[c] == 0) {
//                    ii++;
//                    jj++;
//                    break;
//                } else {
//                    M[c]--;
//                    tCount++;
//                }
//
//            }
//
//            if (tCount == count) {
//                res.push_back(ii);
//                ii += 1;
//                jj += 1;
//            }
//
//        }
//        return res;
//    }
//};



class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        if (s.size() < totalLen) return res;

        unordered_map<string, int> wordCount;
        for (const string &word: words) wordCount[word]++;


        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordCount.count(word)) {
                    window[word]++;
                    count++;


                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == numWords) res.push_back(left);
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> words = {"word", "good", "best", "good"};
    vector<int> res = s.findSubstring("wordgoodgoodgoodbestword", words);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}