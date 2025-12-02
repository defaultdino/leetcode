// https://leetcode.com/explore/interview/card/amazon/77/linked-list/2976/

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode *dummy = new ListNode();
      ListNode *curr = dummy;

      ListNode *firstCurr = list1;
      ListNode *secondCurr = list2;

      while (firstCurr && secondCurr) {
        if (firstCurr->val < secondCurr->val) {
          curr->next = new ListNode(firstCurr->val);
          curr = curr->next;
          firstCurr = firstCurr->next;
        } else if (secondCurr->val < firstCurr->val) {
          curr->next = new ListNode(secondCurr->val);
          curr = curr->next;
          secondCurr = secondCurr->next;
        } else {
          curr->next = new ListNode(firstCurr->val);
          curr = curr->next;
          firstCurr = firstCurr->next;
        }
      }

      if (firstCurr) {
        curr->next = firstCurr;
      }
      if (secondCurr) {
        curr->next = secondCurr;
      }

      return dummy->next;
    }
};