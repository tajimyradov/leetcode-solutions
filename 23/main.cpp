#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        bool w =false;
        ListNode *res=new ListNode();

        ListNode *mn=lists[0];
        for (ListNode* node : lists) {
            if (mn->val>node->val){
                mn=node;
            }
        }
        res->val=mn->val;
        mn=mn->next;

        mn=nullptr;
        while (!w){
            w= true;
            for (ListNode* node : lists) {
                if (node!=nullptr && node->val==res->val){
                    w= false;
                    res->next=new ListNode(node->val);
                    res=res->next;
                    node=node->next;
                }
                if (node!=nullptr && res->val<node->val){
                    if (mn==nullptr)
                    {
                        w=false;
                        mn=node;
                    }
                    else if (node->val<mn->val) {w=false; mn = node; }
                }
            }

            res->next=new ListNode(mn->val);
            res=res->next;
        }
    }
};


int main() {

//    [
//              1->4->5,
//              1->3->4,
//              2->6
//    ]


    Solution ss;

    ListNode *l1=new ListNode()

    ss.mergeKLists()
}