class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // the approach here is that we make a hasmap and store value of c and d                in hashmap
        // then we check if -(a+b) exists in that hasmap or not
        // then we simply update the count
        
        //time complexity - O(N^2)
        //space complexity - O(N^2)
        
        int count=0,size=nums1.size();
        unordered_map<int,int> mp;
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        
        
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
              count+=mp[-(nums3[i]+nums4[j])];  
            }
        }
        
        return count;
    }
};