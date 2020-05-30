
//Wrong solution, rechceck rule for right function

class Solution {
public:

  bool right(int x, int l, int r, int t) {
    if(
      (x > t && l > t && r > t && x > l && l > r && x > r) ||
      (x < t && l > t && r < t && x < l && l > r && x < r)
    ) {
      return true;
    }
    return false;
  }

    int search(vector<int>& nums, int target) {
      if(!nums.size()) {
        return -1;
      }
      int left = 0;
      int right = (int)nums.size() - 1;
      int mid;

      if(nums[left] == target) {
        return 0;
      }
      else if (nums[right] == target) {
        return right;
      }

      while(left < right) {
        mid = left + (right-left)/2;
        if(nums[mid] == target) {
          return mid;
        }
        else if(this->right(nums[mid], nums[left], nums[right], target)) {
          left = mid + 1;
        }
        else {
          right = mid - 1;
        }
      }
      if(nums[left] == target) {
        return left;
      }
      return -1;
    }
};

/*

examples
0....5.....10, looking for 7, go right because 7 > 5 && 0 < 5 && 7 < 10 && 5 < 10
1 ...5.6.7.0, looking for 7, go right because  7 > 5 && 1 < 5 && 7 > 0 &&
6.7.0.1.2.3.4.5.....10
11.12.0.1.2.3.5..7..10

edge cases
1. array is empty
2.  number is on the right or left ends

look at a number
1) found
2) go right

3) go left
4) not found
*/
