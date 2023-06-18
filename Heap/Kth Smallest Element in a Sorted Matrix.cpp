int Solution::solve(vector<vector<int> > &A, int B) {
   priority_queue<int,vector<int>, greater<int>> pq;
   
   for(int i=0;i<A.size();i++){
       for(int j=0;j<A[i].size();j++){
           pq.push(A[i][j]);
       }
   }

   while(!pq.empty() && B>1){
     //  cout << pq.top() << " ";
       pq.pop();
       B--;
   }

   if(!pq.empty()){
       return pq.top();
   }
  
   return 0;
}
