struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        ListNode head;
        ListNode* cur = &head;
        while (l2 != nullptr && l1 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = new ListNode(l1->val, nullptr);
                l1 = l1->next;
            }
            else
            {
                cur->next = new ListNode(l2->val, nullptr);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == nullptr)
            cur->next = l2;
        else if (l2 == nullptr)
            cur->next = l1;
        return head.next;
    }
};
/*Runtime: 8 ms
Memory Usage: 15.5 MB*/