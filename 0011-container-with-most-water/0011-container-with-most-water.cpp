class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i < j) {
            int h = min(height[i], height[j]);  //height
            area = max(area, h * (j - i));      //max area

            if (height[i] < height[j])          //move pointer having smaller height
                i++;
            else
                j--;
        }
        return area;
    }
};