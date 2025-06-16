#include<iostream>



using namespace std;



class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};


int main(){
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = s.kidsWithCandies(candies, extraCandies);
    
    for (bool canHave : result) {
        cout << (canHave ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}