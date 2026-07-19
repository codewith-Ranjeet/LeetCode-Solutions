class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> r(n, vector<int>(n));
        int top = 0, down = n - 1;
        int left = 0, right = n - 1;
        int curr_element = 1;

        while(curr_element <= n * n){
            //left to right
            for(int i = left; i <= right; i++) r[top][i] = curr_element++;
            top++;
            
            //top to down
            for(int i = top; i <= down; i++) r[i][right] = curr_element++;
            right--;
            
            //right to left
            for(int i = right; i >= left && curr_element <= n * n; i--) r[down][i] = curr_element++;
            down--;
            
            //down to top
            for(int i = down; i >= top && curr_element <= n * n; i--) r[i][left] = curr_element++;
            left++;
        }

        return r;
    }
};