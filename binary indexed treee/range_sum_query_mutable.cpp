class NumArray {
public:
  vector<int> sums = {};
  vector<int> & nums;

  NumArray(vector<int>& nums_param): nums(nums_param) {
    if(nums.size()) {
      sums.resize((int)nums.size());
      sums[0] = nums[0];
      for(int i = 1; i < (int)nums.size(); i++) {
        sums[i] = sums[i-1] + nums[i];
      }
    }
  }

  void update(int i, int val) {
    int old_val = nums[i];
    nums[i] = val;
    for(; i < sums.size(); i++) {
      sums[i] += val - old_val;
    }
  }

  int sumRange(int i, int j) {
    if(i == 0) {
      return sums[j];
    }
    return sums[j] - sums[i-1];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
