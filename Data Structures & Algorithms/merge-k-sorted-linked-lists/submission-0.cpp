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

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //min heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        //first we will store the heads of the lists
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while(!pq.empty()){
            ListNode *node = pq.top();
            pq.pop();

            if(node->next != nullptr){
                pq.push(node->next);
            }

            curr->next = new ListNode(node->val);
            curr = curr->next;

        }
        return dummy->next;
        
    }
};
