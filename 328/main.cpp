#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = head;
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->next == nullptr)
        {
            return head;
        }

        ListNode *even = head->next;

        ListNode *even_head = new ListNode;
        ListNode *odd_head = new ListNode;

        ListNode *temp_even_head = even_head;
        ListNode *temp_odd_head = odd_head;

        while ((odd->next != nullptr && odd->next->next != nullptr))
        {
            odd_head->next = new ListNode(odd->val);
            odd_head = odd_head->next;
            odd = odd->next->next;
        }

        odd_head->next = new ListNode(odd->val);
        odd_head = odd_head->next;

        while (even->next != nullptr && even->next->next != nullptr)
        {
            even_head->next = new ListNode(even->val);
            even_head = even_head->next;
            even = even->next->next;
        }

        even_head->next = new ListNode(even->val);

        odd_head->next = temp_even_head->next;

        return temp_odd_head->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution s;

    head = s.oddEvenList(head);
}