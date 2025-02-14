/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            
            while(curr != nullptr){
              ListNode* nexxt  = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nexxt;
               
    
            }
            return prev;
        }
    
    // recursive 
    
          ListNode* reverseeList(ListNode* head){
            if(head == NULL || head->next == NULL) return head;
            ListNode* prev = NULL;
            ListNode* temp = reverseeList(head->next);
            head->next->next = head;
            head->next = prev;
            return temp;
          }
    };