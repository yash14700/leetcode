class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int nums1counter = 0;
    int nums2counter = 0;
    vector<int> result;
    while(nums1counter < nums1.size() && nums2counter < nums2.size()) {
        if(nums1[nums1counter] < nums2[nums2counter]) {
          result.push_back(nums1[nums1counter]);
          nums1counter++;
        }
        else if(nums1[nums1counter] > nums2[nums2counter]) {
          result.push_back(nums2[nums2counter]);
          nums2counter++;
        }
        else {
          result.push_back(nums1[nums1counter]);
          nums1counter++;
          result.push_back(nums2[nums2counter]);
          nums2counter++;
        }
    }

    while(nums1counter < nums1.size()) {
      result.push_back(nums1[nums1counter]);
      nums1counter++;
    }

    while(nums2counter < nums2.size()) {
      result.push_back(nums2[nums2counter]);
      nums2counter++;
    }

    int median_pos = result.size() / 2;
    // if even
    if(result.size() % 2 == 0) {
      return result[median_pos - 1] + (result[median_pos] - result[median_pos-1])/2.0;
    }
    //else odd
    return result[median_pos];

  }
}
