class Solution {
public:
    bool isValidRow(vector<vector<char> > &sudukoMatrix,int row,int col,int no){
    for(int i=0;i<9;i++){
        if(sudukoMatrix[row][i] -'0' == no){
            return false;
        }
    }

    return true;
}

//validation for cloumn
bool isValidCol(vector<vector<char> > &sudukoMatrix,int row,int col,int no){
    for(int i=0;i<9;i++){
        if(sudukoMatrix[i][col] -'0' == no){
            return false;
        }
    }

    return true;
}

//validation for block
bool isValidBlock(vector<vector<char> > &sudukoMatrix,int row,int col,int no){
    int startRow = row - row %3; //get start row of block 
    int startCol = col - col%3;  //get start col of block 
    //iterate over isValidBlock
    for(int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            //if we found elemnet we search retun false
            if(sudukoMatrix[i][j]-'0'==no){
                return false;
            }
        }
    }

    return true;
}
bool fillSuduko(vector<vector<char> > &sudukoMatrix,int index){
    //In suduko we have 81 boxes starting from 0 so boxes are in range 0 to 80
    //base case
    if(index==81){
        return true;
    }

    //get row and col from index
    int row = index/9;
    int col = index%9;
    
    //check if current block is valid to fill or not
    if(sudukoMatrix[row][col]!='.'){
        return fillSuduko(sudukoMatrix,index+1);
    }

    for(int no=1;no<=9;no++){
        if(isValidRow(sudukoMatrix,row,col,no) && //check row is valid 
           isValidCol(sudukoMatrix,row,col,no) &&  //check col is valid
           isValidBlock(sudukoMatrix,row,col,no)){  //check if valid for box
                 
                 sudukoMatrix[row][col] = char(no)+'0'; 
                //call for next index
                if(fillSuduko(sudukoMatrix,index+1)){
                    return true;
                }
                //backtarack the path 
                sudukoMatrix[row][col]='.'; 
                
           }
    }

    return false;
}

    void solveSudoku(vector<vector<char>>& sudukoMatrix) {
        fillSuduko(sudukoMatrix,0);
    }
};