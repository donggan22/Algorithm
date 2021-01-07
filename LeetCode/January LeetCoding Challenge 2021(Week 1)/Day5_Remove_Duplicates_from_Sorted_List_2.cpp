
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        bool flag = false;
        ListNode mHead;
        ListNode* prev = &mHead;
        mHead.next = head;
        while (1)
        {
            if (head->next == nullptr)
            {
                if (flag)
                {
                    prev->next = nullptr;
                    return mHead.next;
                }
                else
                {
                    prev->next = head;
                    return mHead.next;
                }
            }
            else 
            {
                if (head->val == head->next->val)
                {
                    head = head->next;
                    flag = true;
                }
                else
                {
                    if (flag)
                    {
                        prev->next = head->next;
                        head = head->next;
                        flag = false;
                    }
                    else
                    {
                        prev->next = head;
                        prev = head;
                        head = head->next;
                        flag = false;
                    }
                }

            }
        }
        return mHead.next;
    }
};