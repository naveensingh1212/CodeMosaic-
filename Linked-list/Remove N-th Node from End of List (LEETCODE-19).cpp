class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* temp = head;
            int cnt = 0;
    
    
            while (temp != NULL) {
                temp = temp->next;
                cnt++;
            }
    
    
            if (cnt == n) {
                ListNode* newHead = head->next;
                delete head;
                return newHead;
            }
    
            int res = cnt - n - 1;
            temp = head;
            while (res > 0) {
                temp = temp->next;
                res--;
            }
    
         
            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
    
            return head;
        }
    
    
    ///OPTIMAL
    
    
       ListNode* removeeNthFromEnd(ListNode* head, int n) {
        ListNode* fastp = head;
        ListNode* slowp = head;
            fastp = fastp->next;
    
     
        if (fastp == NULL)
            return head->next;
    
    
        while (fastp->next != NULL) {
            fastp = fastp->next;
            slowp = slowp->next;
        }
    
        ListNode* delNode = slowp->next;
        slowp->next = slowp->next->next;
        delete delNode;
        return head;
    }
       
    
    };
    