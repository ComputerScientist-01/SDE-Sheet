class Solution {
    public:
        int findPairs(vector < int > & nums, int k) {
            unordered_map < int, int > mp;
            int count = 0, i = 0;
            for (i = 0; i < nums.size(); i++) mp[nums[i]]++;
            for (auto i: mp) 
            {
                if (k == 0) 
                {
                    if (i.second > 1) 
                        count++;
                } 
                else if (mp.find(i.first + k) != mp.end()) 
                {
                    count++;
                }
            }
            
            return count;
        }
};