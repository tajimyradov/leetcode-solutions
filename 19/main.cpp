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
    int lengthOfLinkedList(ListNode *head) {
        ListNode *temp_head = head;
        int count = 0;
        while (temp_head != nullptr) {
            count++;
            temp_head = temp_head->next;
        }
        return count;
    }


    void print(ListNode *head) {
        ListNode *temp_head = head;
        while (temp_head != nullptr) {
            cout << temp_head->val << " ";
            temp_head = temp_head->next;
        }
        cout << endl;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int l = lengthOfLinkedList(head);
        if (l == 1) {
            delete (head);
            return nullptr;
        }
        ListNode *temp_head = head;
        int r = l - n - 1;
        while (r > 0) {
            r--;
            temp_head = temp_head->next;
        }
        ListNode *d = nullptr;
        if (r == -1) {
            d = temp_head;
            head = temp_head->next;
        } else {
            if (temp_head->next->next == nullptr) {
                d = temp_head->next;
                temp_head->next = nullptr;
            } else {
                d = temp_head->next;
                temp_head->next = d->next;
            }
        }

        delete (d);

        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head = s.removeNthFromEnd(head, 2);
    s.print(head);
}