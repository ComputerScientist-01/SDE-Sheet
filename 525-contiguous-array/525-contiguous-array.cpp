class Solution {
public:
    int findMaxLength(vector<int>& nums) {
   
        unordered_map<int,int> map;
        map.insert({0, -1});
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count = count + (nums[i] == 1 ? 1 : -1);
            if (map.find(count) != map.end()) {
                maxlen = max(maxlen, i - map.at(count));
            } else {
                map.insert({count, i});
            }
        }
        return maxlen;

        
    }
};