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
    ListNode *deleteMiddle(ListNode *head)
    {

        ListNode *temp = head;
        if (head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *next_next = head->next->next;
        ListNode *prev = head;
        head = head->next;
        while (next_next != nullptr && next_next->next != nullptr)
        {
            next_next = next_next->next->next;
            prev = head;
            head = head->next;
        }

        prev->next = head->next;
        return temp;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);

    Solution s;

    head = s.deleteMiddle(head);
}