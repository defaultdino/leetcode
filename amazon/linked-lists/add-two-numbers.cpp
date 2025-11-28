// https://leetcode.com/explore/interview/card/amazon/77/linked-list/513/

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
      ListNode *currentFirst = l1;
      ListNode *currentSecond = l2;

      ListNode *current = new ListNode();
      ListNode *head = current;

      int carry = 0;

      while (currentFirst || currentSecond || carry) {
        int currentFirstVal = 0;
        int currentSecondVal = 0;

        if (currentFirst)
          currentFirstVal = currentFirst->val;
        if (currentSecond)
          currentSecondVal = currentSecond->val;        
        
        int sum = (currentFirstVal + currentSecondVal) + carry;
        carry = sum / 10;

        current->val = sum % 10;

        if (currentFirst)
          currentFirst = currentFirst->next;
        if (currentSecond)
          currentSecond = currentSecond->next;

        if ((currentFirst || currentSecond) || carry) {
          current->next = new ListNode();
          current = current->next;
        }
      }

      return head;
    }
};