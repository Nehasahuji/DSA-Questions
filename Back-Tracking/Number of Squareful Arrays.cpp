//https://leetcode.com/problems/number-of-squareful-arrays/
class Solution {
public:
bool isSquare(int N) {

        int x = sqrt(N);

        if(x*x != N)

        return false;

        return true;

}

    void recursion(vector<int> A, int index,int &res){
        int n = A.size();

        if(index==n-1){
            if(isSquare(A[index]+A[index-1]))
            {
                res++;
            }
            return;
        }

        for(int i=index;i<n;i++){
            if(index!=i && A[i]==A[index]) 
                 continue;
            
            swap(A[i],A[index]);
            
            if(index==0 || (index>0 && isSquare(A[index]+A[index-1]))){
                recursion(A,index+1,res);
            }
        }
    }

    int numSquarefulPerms(vector<int>& A) {
        if(A.size()==1) return 0;
        int res=0;
        sort(A.begin(),A.end());
        recursion(A,0,res);
        return res;
    }
};