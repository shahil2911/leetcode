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

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<int,vector<int>, greater<int>> pq;
//         for(int i=0;i<lists.size();i++){
//             ListNode* current = lists[i];
//             while (current != nullptr) {
//                 pq.push(current->val);
//                 current = current->next;
//             }
//         }
//         ListNode* head=new ListNode(-1);
//         ListNode* tail=head;
//         while(!pq.empty()){
//             tail->next=new ListNode(pq.top());
//             pq.pop();
//             tail=tail->next; 
//         }
//         return head->next; 
//     }
// };


class myCompare{
    public:
    bool operator()(const ListNode* a, const ListNode* b){
        return (a->val>b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head= new ListNode(-1);
        ListNode* tail=head;
        priority_queue<ListNode*, vector<ListNode*>, myCompare>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr)
                pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto mini=pq.top();
            pq.pop();
            tail->next=mini;
            tail=tail->next;
            if(mini->next)
                pq.push(mini->next);
        }
        return head->next;

    }
};