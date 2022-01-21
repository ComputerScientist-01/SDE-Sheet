class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // create answer vector
        vector<vector<int>> ans;
        for(int i=0; i <numRows;i++){
            //create row vector of size (i+1)
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                //retrieve value from previous rows
                row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            // push row vec in answer
            ans.push_back(row);
        }
        //final answer
        return ans;
    }
};