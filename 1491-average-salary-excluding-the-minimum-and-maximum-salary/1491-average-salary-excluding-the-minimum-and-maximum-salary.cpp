class Solution {
public:
    double average(vector<int>& salary) {
        double average=0;
        int n=salary.size();
        sort(salary.begin(),salary.end());
        for(int i=1; i<n-1;i++){
             average += salary[i];
        }
        average/=(n-2);
        return average;
    }
};