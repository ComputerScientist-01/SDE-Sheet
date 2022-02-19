class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX,min_n = INT_MAX;
        priority_queue<int> pq;
        for(auto n:nums){
            n = (n%2)?n*2:n;
            pq.push(n);
            min_n = min(n,min_n);
        }
        while(pq.top()%2 == 0){
            res = min(res,pq.top() - min_n);
            min_n = min(min_n,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-min_n);
    }
};