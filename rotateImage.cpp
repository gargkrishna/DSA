// problem link -> https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,n=matrix.size(),m=matrix[0].size();
        for(i=0;i<n;i++){
            for(j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
         for(i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// time -> O(n^2)
// space -> O(1)