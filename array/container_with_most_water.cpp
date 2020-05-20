class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size()-1;
        int w = 0;
        int h = 0;
        int area = 0;
        while(right > left) {
            w = right - left;
            h = min(height[left], height[right]);
            area = w*h;
            if (area > result) {
                result = area;
            }
            if(h == height[left]) {
                left++;
            }
            if(h == height[right]) {
                right--;
            }
        }
        return result;
    }
};
