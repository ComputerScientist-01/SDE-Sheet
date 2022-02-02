class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //sliding window technique using my own template
        int n = s.size();  //length of source string
        int m = p.size();  //length of target string
        
        //init an array or var to save the result as per the question requirement
        vector<int> startIndices;
        
        //if target string size is greater than source string size
        if(m > n) {
            return startIndices;
        }
        
        //create a hashmap to save the characters count of the target substring.
        //<char, int> = (Character, Frequency of the Characters)        
        unordered_map<char,int> charCount;        
        for(int i=0; i<m; i++) {
            if(charCount.find(p[i]) == charCount.end()) {
                charCount[p[i]] = 1;
            }
            else {
                charCount[p[i]]++;
            }
        }
        
        //num of unique chars in target string
        int uniqueCharCount = charCount.size(); 
        
        //Two Pointers: left -> first pointer of the window,
        //right -> last pointer of the window
        int left = 0;
        int right = 0;
        
        //maintain a counter to check whether curr window in source string
        //matches the given condition with target string.        
        int numHits = 0;

        //loop the source string till right pointer reaches end of source string
        while(right < n) {
            
            //add the character at the right pointer which is now
            //a part of the window and update hashmap accordingly            
            if(charCount.find(s[right]) != charCount.end()) {
                if(charCount[s[right]] == 0) {
                    numHits--;
                }
                //modify the counter as per the requirement
                charCount[s[right]]--;
                if(charCount[s[right]] == 0) {
                    numHits++;
                }
            }
            if( right - left + 1 > m) {
                //increment left pointer whenever the window size
                //crosses the target string size to keep the window size
                //equal to the target string size
                left++;
                
                //remove the character which is no longer part of the window
                //and update hashmap accordingly
                if(charCount.find(s[left-1]) != charCount.end()) {
                    if(charCount[s[left-1]] == 0) {
                        numHits--;
                    }
                    //modify the counter as per the requirement
                    charCount[s[left-1]]++;
                    if(charCount[s[left-1]] == 0) {
                        numHits++;
                    }
                }                
            }
            
            //whenever the current window in source string fulfils the 
            //given conditions in the target string, add it to the result 
            if(numHits == uniqueCharCount) {
                startIndices.push_back(left);
            }
            
            //increment right pointer in each iteration
            right++;
        }
        
        //return result 
        return startIndices;
    }
};