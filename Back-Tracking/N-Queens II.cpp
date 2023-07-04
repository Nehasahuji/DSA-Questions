# Complexity
- Time complexity:TC:O(n!)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
     void placeNQueen(int& ans,
                     int row,int n,
                     vector<bool>& columns_record,
                     vector<bool>& left_diagonal_record,
                     vector<bool>& right_diagonal_record){
        
        
        //base case
        if(row==n){
            ans++;
        }
        
        
        //iterate over all columns
        for(int col=0;col<n;col++){
            if(columns_record[col]==false &&
               left_diagonal_record[row-col+n-1]==false &&
               right_diagonal_record[row+col]==false
            ){
                columns_record[col] = true;
                left_diagonal_record[row-col+n-1] = true;
                right_diagonal_record[row+col]=true;
                placeNQueen(ans,row+1,n,columns_record,left_diagonal_record,right_diagonal_record);
                columns_record[col] =  
                left_diagonal_record[row-col+n-1] = 
                right_diagonal_record[row+col]=false;                
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        
        //create a vector to store every possible ans
        vector<int> sol;
        
        vector<bool> columns_record(n,false),
                     left_diagonal_record((2*n) -1 ,false),
                     right_diagonal_record((2*n) -1 ,false);
                     
        
        placeNQueen(ans,0,n,columns_record,left_diagonal_record,right_diagonal_record);
        
        return ans;
    }
};
```