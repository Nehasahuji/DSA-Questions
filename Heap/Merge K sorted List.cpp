/*# Approach: Using Min heap [priority queue]
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: O(N * K * log K)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(K)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
*/

```
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
    //create a compare funtion to sort the queue like min heap
    struct compare{
        bool operator()(
            struct ListNode* a, struct ListNode* b)
            {
                return a->val > b->val;
            }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Step1: create a priority queue contains min heap
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        //Step2: insert first Node of every linked list in priority_queue
        for(int i=0;i<lists.size();i++){
            // to check list has some value
            if(lists[i]!=NULL){
                pq.push(lists[i]);  
            }
        }

        //Step3: check weather queue is empty or not 
        // where k=0 or having empty list
        if(pq.empty()){
            return NULL;
        }


        //step 4: create a node to consider as head of resultant node
        ListNode* start = new ListNode(0);
        ListNode* end = start;

        //Step5 Iterate all the list
        while(!pq.empty()){
            
            //Step 6: Get the top element of 'pq'
            ListNode* curr = pq.top();
            pq.pop();

            //Step 7: Add the top element of 'pq'
            // to the resultant merged list
            end->next=curr;
            end=end->next;  


            //Step 8:  Check if there is a node
            // next to the 'top' node
            // in the list of which 'top'
            // node is a member
            if(curr->next!=NULL){
                // Step 9: Push the next node of top node
                // in 'pq'
                pq.push(curr->next);
            }
        }
        return start->next;
    }
};  
```
If you find any issue in understanding the solution then comment below, will try to help you.
If you found my solution useful.
So please do upvote and encourage me to document all leetcode problems😃
Happy Coding :)

