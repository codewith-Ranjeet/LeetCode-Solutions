class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        
        for(int i = 0, j = 0; i < n || j < m; i++, j++){
            string num1, num2;
            while(i < n && version1[i] != '.') num1 += version1[i++];
            while(j < m && version2[j] != '.') num2 += version2[j++];

            if(num1 == "") num1 = "0";
            if(num2 == "") num2 = "0";
            
            int n1 = stoi(num1);
            int n2 = stoi(num2);

            if(n1 < n2)
                return -1;
            else if(n1 > n2) 
                return 1;
        }
        return 0;
    }
};