/*
The local ship renting service has a special rate plan:

It is up to a passenger to choose a ship.
If the chosen ship has X (X > 0) vacant places at the given moment, then the ticket for such a ship costs X.
The passengers buy tickets in turn, the first person in the queue goes first, then the second one, and so on up to A-th person.

You need to tell the maximum and the minimum money that the ship company can earn if all A passengers buy tickets.



Problem Constraints
1 ≤ A ≤ 3000
1 ≤ B ≤ 1000
1 ≤ C[i] ≤ 1000
It is guaranteed that there are at least A empty seats in total.



Input Format
First argument is a integer A denoting the number of passengers in the queue.
Second arugument is a integer B deonting the number of ships.
Third argument is an integer array C of size B where C[i] denotes the number of empty seats in the i-th ship before the ticket office starts selling tickets.



Output Format
Return an array of size 2 denoting the maximum and minimum money that the ship company can earn.



Example Input
Input 1:

 A = 4
 B = 3
 C = [2, 1, 1]
Input 2:

 A = 4
 B = 3
 C = [2, 2, 2]


Example Output
Output 1:

 [5, 5]
Output 2:

 [7, 6]


Example Explanation
Explantion 1:

 Maximum money can be earned if the passenger choose : 2(first ship) + 1(first ship) + 1(second ship) + 1(third ship).
 So, the cost will be 5.
 Minimum money can be earned if the passenger choose : 1(senocd ship) + 2(first ship) + 1(first ship) + 1(third ship).
 So, the cost will be 5.
Explanation 2:

 Maximum money can be earned if the passenger choose : 2(first ship) + 2(second ship) + 2(third ship) + 1(first ship).
 So, the cost will be 7.
 Minimum money can be earned if the passenger choose : 2(senocd ship) + 2(first ship) + 1(first ship) + 1(second ship).
 So, the cost will be 6.
*/vector<int> Solution::solve(int A, int B, vector<int> &C) {
    //create a max heap to always get a max value
    priority_queue<int> max_cost_pq;

    //create a min heap to always get min cost of ticket
    priority_queue<int,vector<int>,greater<int>> min_cost_pq;

    //add all the cost of passenger into the heaps;
    for(int i=0;i<C.size();i++){
        max_cost_pq.push(C[i]);
        min_cost_pq.push(C[i]);
    }
    
    //variable to store max cost
    int max_cost=0;

    //calculate max cost of every person and toatl max cost
    for(int i=0;i<A;i++){
        int current_max_cost = max_cost_pq.top();
        max_cost = max_cost + current_max_cost;
        max_cost_pq.pop();
        //decrease cost if a seat is booked
        if(current_max_cost>1){
            max_cost_pq.push(current_max_cost-1);
        }
    }
    
     //variable to store min cost
    int min_cost=0;

    //calculate max cost of every person and total min cost
    for(int i=0;i<A;i++){
        int current_min_cost = min_cost_pq.top();
        min_cost = min_cost + current_min_cost;
        min_cost_pq.pop();
        //decrease cost if a seat is booked
        if(current_min_cost>1){
            min_cost_pq.push(current_min_cost-1);
        }
    }

    return {max_cost,min_cost};
}
/*
Time Complexity:O(n) + O(n) + O(nlogn) -> O(nlogn)
Space Complexity:O(n)
*/