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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* current = lists[i];
            while (current != nullptr) {
                pq.push(current->val);
                current = current->next;
            }
        }
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;
        while(!pq.empty()){
            tail->next=new ListNode(pq.top());
            pq.pop();
            tail=tail->next; 
        }
        return head->next; 
    }
};