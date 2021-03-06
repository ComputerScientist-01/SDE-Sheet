class Solution {
public:
	void backtracking(int j, vector<int>& arr, vector<int>& sub, vector<vector<int>>& ans) {
		for (int i = j; i < arr.size(); i++) {
			sub.push_back(arr[i]);
			ans.push_back(sub);
			backtracking(i + 1, arr, sub, ans);
			sub.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums) {
		vector<vector<int>> ans{{}}; // push empty sub
		vector<int> sub;
		backtracking(0, nums, sub, ans);
		return ans;
	}
};
// Time complexity: The number of subsets = O(2^n)