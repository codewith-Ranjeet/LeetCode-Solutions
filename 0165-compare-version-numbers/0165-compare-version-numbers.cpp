class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size();
        int m = v2.size();
        
        for(int i = 0, j = 0; i < n || j < m; i++, j++){
            int x1 = 0, x2 = 0;
            while(i < n && v1[i] != '.') x1 = 10 * x1 + (v1[i++] - '0');
            while(j < m && v2[j] != '.') x2= 10 * x2 + (v2[j++] - '0');
        
            if(x1 < x2)
                return -1;
            else if(x1 > x2) 
                return 1;
        }
        return 0;
    }
};