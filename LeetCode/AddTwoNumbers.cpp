
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stk;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || sum != 0)
        {
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            stk.push(sum % 10);
            sum = sum / 10;
        }
        ListNode* prev = nullptr;
        while (!stk.empty())
        {
            ListNode* tmp = new ListNode;
            tmp->val = stk.top();
            tmp->next = prev;
            prev = tmp;
            stk.pop();
        }
        return prev;
    }
};
Time complexity is Max(l1.size(), l2.size()) * 2
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (l1 != nullptr || l2 != nullptr || sum != 0)
        {
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* tmp = new ListNode(sum % 10);
            if (head == nullptr)
                head = tail = tmp;
            else
            {
                tail->next = tmp;
                tail = tmp;
            }
            sum /= 10;
        }
        return head;
    }
};
//Time complexity is Max(l1.size(), l2.size()) + C