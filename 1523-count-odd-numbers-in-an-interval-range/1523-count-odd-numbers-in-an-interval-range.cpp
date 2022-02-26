class Solution {
public:
    int countOdds(int low, int high) {
        int N = (high-low)/2;       
        
        // if low or high are odd change value of n
        if((low %2 !=0) || (high%2 !=0)){
            N+=1;
        }
        return N;
    }
};