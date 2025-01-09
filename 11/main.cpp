#include<iostream>
using namespace  std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int end=height.size();
        int start=0;
        int max_area=0;

        while(end!=start){
            if(max_area<((end-start)*min(height[end],height[start]))){
                max_area=(end-start)*min(height[end],height[start]);
            }


            if (height[end]> height[start])
                start++;
            else
                end--;
        }
        return max_area;
    }
};

int main(){
    Solution s;
    vector<int> ss;
    ss.push_back(1);
    ss.push_back(8);
    ss.push_back(6);
    ss.push_back(2);
    ss.push_back(5);
    ss.push_back(4);
    ss.push_back(8);
    ss.push_back(3);
    ss.push_back(6);
    cout<<s.maxArea(ss);
}