//Leetcode 83. Remove Duplicates from Sorted List
//Easy
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr)
        {
            return head;
        }
        
        ListNode* itr1 = head;
        if (head->next==nullptr)
        {
            return head;
        }
        
        ListNode* itr2 = head->next;
        while (itr2!=nullptr)
        {
            if (itr1->val==itr2->val)
            {
                itr1->next = itr2->next;
                itr2 = itr2->next;

            }
            else
            {
                itr1 = itr1->next;
                itr2 = itr2->next;
            }
        }
        return head;
        
    }
};
