class Solution {
public:
    int trap(vector<int>& height) { // height = [0,1,0,2,1,0,1,3,2,1,2,1]
        int left = 0, right = height.size() - 1, rightMax,
            waterTrapped; // left = 0, right = 11
        int leftMax = rightMax = waterTrapped = 0;

        while (left < right) { // run until reached center
            if (height[left] < height[right]) {
                // left side
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    waterTrapped += leftMax - height[left];
                }
                left++;
            } else {
                // right side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    waterTrapped += rightMax - height[right];
                }
                right--;
            }
        }

        return waterTrapped;
    }
};