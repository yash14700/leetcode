//O(log(min(m,n)))


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      //goal is to find index of smaller vector that breaks the combined vectors into two different groups

      //deal with situation in which one of the vectors is present entirely in one of the groups
      //when both are equal
      if (nums1.size() == nums2.size()) {
        if (nums1[nums1.size()-1] <= nums2[0]) {
          return (nums1[nums1.size()-1] + nums2[0])/2.0;
        }
        else if (nums2[nums2.size()-1] <= nums1[0]) {
          return (nums2[nums2.size()-1] + nums1[0])/2.0;
        }
      }


      //set smaller and larger vectors
      vector<int>& smaller = (nums1.size() < nums2.size())?nums1:nums2;
      vector<int>& larger =  (smaller.size() == nums1.size())?nums2:nums1;
      if(nums1.size() == nums2.size()) {
        larger = nums1;
      }

      //situation in which one of the vectors is entriely in one group
      int j = (larger.size() + smaller.size() -1)/2;

      //regular situation
      //pick i
      int i = smaller.size()/2;
      j =
      //compute j
      //loop until
        //if xxx increase i
        //if xxxx decrease i

      //median if odd
      //median if even
    }
};

// O(n) Solution
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
};
