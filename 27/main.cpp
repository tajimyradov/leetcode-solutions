#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {

        if (nums.size()==0)
            return 0;

        int k=0;
        int i=0;


        while(i<nums.size()){
            if (nums[i]!=val){
                swap(nums[i],nums[k]);
                k++;
            }

            i++;
        }

        return k;
    }
};

int main() {
    Solution s;
    vector<int> p = {3,2,2,3};
    int res = s.removeElement(p,3);
    cout << res<<endl;

    for (int i = 0; i < res; i++)
        cout<<p[i]<<" ";
}