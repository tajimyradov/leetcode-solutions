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

    void print(ListNode *head) {
        ListNode *temp_head = head;
        while (temp_head != nullptr) {
            cout << temp_head->val << " ";
            temp_head = temp_head->next;
        }
        cout << endl;
    }
};

int main(){
    Solution s;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    ListNode *res;
    res=s.mergeTwoLists(head,head);
    s.print(res);
}