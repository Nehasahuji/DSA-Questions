int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    int start=0;
    int end=-1;
    int currsum=0;
    
    unordered_map<int,int> mp;
    
    for(int i=0;i<A.size();i++){
        currsum+=A[i];
      // cout <<  currsum << " " << currsum-B << " || ";
        
        if(currsum==B){
            start=0;
            end=i;
            ans=max(ans,end+1);
        }
        
        if(mp.find(currsum-B)!=mp.end()){
            start=mp[currsum-B]+1;
            end=i;
            ans=max(ans,end-start+1);
        }
        
        mp.insert({currsum,i});
    }
    
    
    return ans;
}

Time Complexity: (O(n));
Space Complexity: O(n)