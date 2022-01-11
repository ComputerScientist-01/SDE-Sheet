class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        //traverse the array with their original speeds
        while(true)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            
            if(slow == fast){
                break;
            }
        }
        
        //condition where collision is bound to happen
        // here we increment both of them by 1
        slow=nums[0];
        
        while(slow != fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};