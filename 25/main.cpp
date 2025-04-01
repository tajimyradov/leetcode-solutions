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


private:

    pair<ListNode *, pair<ListNode *, ListNode *>> reverseK(ListNode *cur, int k) {

        ListNode* temp=cur;
        int kk=k;
        while (temp && kk-1){
            kk--;
            temp=temp->next;
        }
        if (temp== nullptr)
            return make_pair(cur, make_pair(nullptr, nullptr));

        ListNode *last = cur;
        ListNode *prv = cur;
        cur = cur->next;

        while (k-1 && cur) {

            ListNode *nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
            k--;
        }


        return make_pair(prv, make_pair(last, cur));

    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {

        if (k <= 1 || k == 1)
            return head;

        ListNode *last = nullptr;
        ListNode *chainTail;
        ListNode *nextChain = head;
        head = nullptr;
        while (nextChain) {
            pair<ListNode *, pair<ListNode *, ListNode *>> p = reverseK(nextChain, k);
            ListNode *chainHead = p.first;
            chainTail = p.second.first;
            nextChain = p.second.second;


            if (!head)
                head = chainHead;
            else
                last->next = chainHead;
            last = chainTail;
        }

        if (chainTail!= nullptr)
            last->next= nullptr;


        return head;
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

    Solution s;
    ListNode *res = s.reverseKGroup(&l1, 3);

    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
}