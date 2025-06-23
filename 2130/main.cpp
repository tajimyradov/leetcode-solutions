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

private:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

public:
    int pairSum(ListNode *head)
    {

        ListNode *temp = head;
        if (head == nullptr)
        {
            return 0;
        }

        if (head->next->next == nullptr)
        {
            return head->val + head->next->val;
        }

        ListNode *fast = head->next;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            head = head->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseList(head);
        int mx = INT_MIN;
        while (newHead != nullptr && temp != nullptr)
        {
            int x = newHead->val;
            int y = temp->val;
            if (x + y > mx)
                mx = x + y;

            newHead = newHead->next;
            temp = temp->next;
        }
        return mx;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(32);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution s;

    cout << s.pairSum(head);
}