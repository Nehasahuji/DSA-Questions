class Solution {
public:
    bool isCheck(vector<int>& piles,int mid,int H){
        int time = 0;
       
        for (int i = 0; i < piles.size(); i++) {
            // to get the ceil value
            if (piles[i] % mid != 0) {
                // in case of odd number
                time += ((piles[i] / mid) + 1);
            }
            else {
                // in case of even number
                time += (piles[i] / mid);
            }
        }

        // check if time is less than
        // or equals to given hour
        if (time <= H) {
            return true;
        }
        else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //get minimum and maximum no of bananas in pile

      
        int minNoBananas=1;
        int maxNoBananas=1;

        for(int i=0;i<piles.size();i++){
            maxNoBananas=max(maxNoBananas,piles[i]);
        }
        
        //apply binary search
        int start = minNoBananas,end=maxNoBananas;

        while(start<end){
            int mid = start+(end-start)/2;

            if(isCheck(piles,mid,h)){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        return end;
    }
};
Time complexity: O(N log W) (W is the max bananas from all piles)
Space complexity:O(1)

