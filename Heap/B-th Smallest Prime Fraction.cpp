/* Time Complexity: O(Nlog(B))
Space Complexity: O(K)
*/

vector<int> Solution::solve(vector<int> &A, int B) {
     priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                double x = A[i]/(A[j]*1.0);
                
                if(pq.size()==B){
                    if(x<pq.top().first){
                        pq.pop();

                        pq.push({x,{A[i],A[j]}});
                    }
                }else{
                    pq.push({x,{A[i],A[j]}});
                }
            }
        }


    return {pq.top().second.first,pq.top().second.second};
}
