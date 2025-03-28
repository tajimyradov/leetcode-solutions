#include <iostream>
#include<set>

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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res=new ListNode();
        ListNode *temp=res;
        while(list1!=nullptr || list2!=nullptr){
            if (list1==nullptr) {
                res->next = new ListNode(list2->val);
                list2=list2->next;
                res=res->next;
            }
            else if (list2==nullptr) {
                res->next = new ListNode(list1->val);
                list1=list1->next;
                res=res->next;
            }
            else if (list1->val<list2->val){
                res->next = new ListNode(list1->val);
                list1=list1->next;
                res=res->next;
            }else{
                res->next = new ListNode(list2->val);
                list2=list2->next;
                res=res->next;
            }

        }
        return temp->next;
    }

    ListNode *mergeRecursion(int i, int j, vector<ListNode*> &arr){
        if (i==j)
            return arr[i];
        int mid = i+(j-i)/2;

        ListNode* head1= mergeRecursion(i,mid,arr);
        ListNode* head2= mergeRecursion(mid+1,j,arr);

        ListNode* head= mergeTwoLists(head1,head2);

        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size()==0)
            return nullptr;
        return mergeRecursion(0,lists.size()-1,lists);
    }
};

int main() {
    int i;
    ListNode l1(1);
    i = 2;
    l1.next = new ListNode(i);
    i++;
    l1.next->next = new ListNode(i);
    i++;
    l1.next->next->next = new ListNode(i);
    i++;
    l1.next->next->next->next = new ListNode(i);
    i++;
    l1.next->next->next->next->next = new ListNode(i);


    ListNode l2(1);
    i = 2;
    l2.next = new ListNode(i);
    i++;
    l2.next->next = new ListNode(i);
    i++;
    l2.next->next->next = new ListNode(i);
    i++;
    l2.next->next->next->next = new ListNode(i);
    i++;
    l2.next->next->next->next->next = new ListNode(i);

    ListNode l3(1);
    i = 2;
    l3.next = new ListNode(i);
    i++;
    l3.next->next = new ListNode(i);
    i++;
    l3.next->next->next = new ListNode(i);
    i++;
    l3.next->next->next->next = new ListNode(i);
    i++;
    l3.next->next->next->next->next = new ListNode(i);


    vector<ListNode *> input;
    input.push_back(&l1);
    input.push_back(&l2);
    input.push_back(&l3);

    Solution s;

    ListNode *res;

    res = s.mergeKLists(input);

    while (res->next != nullptr) {
        cout << res->val;
        res = res->next;
    }
}