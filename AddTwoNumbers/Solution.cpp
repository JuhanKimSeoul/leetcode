#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode* ans = ret;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int val = (l1->val + l2->val) % 10 + carry;
            carry = (l1->val + l2->val) / 10;
            ret->next = new ListNode(val);
            ret = ret->next; 
            l1 = l1->next;
            l2 = l2->next;
        }
        return ans->next;
    }
};

int main(){
    Solution sol;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* result = sol.addTwoNumbers(l1, l2);
    while(result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}