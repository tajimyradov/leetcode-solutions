#include<iostream>

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
    ListNode *swapPairs(ListNode *head) {
        ListNode *temp = new ListNode(-1);
        ListNode *res=temp;
        while (head!= nullptr && head->next  != nullptr) {
            temp->next = new ListNode(head->next->val);
            temp = temp->next;
            temp->next= new ListNode(head->val);
            temp=temp->next;
            head=head->next->next;
        }

        if (head!= nullptr)
            temp->next=new ListNode(head->val);

        return res->next;
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
//    l1.next->next->next->next->next = new ListNode(i);

    Solution s;

    ListNode *res;

    res = s.swapPairs(&l1);

    while (res->next != nullptr) {
        cout << res->val;
        res = res->next;
    }
}