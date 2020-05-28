class Solution {
public:
  vector<vector<int>> result = {};
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> curr_set = {};
    if (target == 0 || !candidates.size()) {
      return {{}};
    }
      for(int pos = 0; pos < (int)candidates.size(); pos++) {
        curr_set.push_back(candidates[pos]);
        backtracker(candidates, pos, target, curr_set, candidates[pos]);
        curr_set.pop_back();
      }
      return result;
  }

  void backtracker(vector<int>& candidates, int pos, int target, vector<int>& curr_set, int sum) {
    //if sum == target, add to results vector
    if(sum == target) {
      result.push_back(curr_set);
    }
    if(sum > target) {
      return;
    }


    //try all combinations starting from pos
    for(;pos < (int)candidates.size(); pos++) {
      curr_set.push_back(candidates[pos]);
      backtracker(candidates, pos, target, curr_set, sum + candidates[pos]);
      curr_set.pop_back();
    }
  }
};
