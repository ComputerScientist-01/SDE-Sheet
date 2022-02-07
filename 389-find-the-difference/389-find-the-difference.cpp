class Solution {
public:
    char findTheDifference(string s, string t) {
        int difference=0;
        for(auto &i : t){
            difference+=i;
        }
        for(auto &i : s){
            difference-=i;
        }
        return char(difference);
    }
    
};