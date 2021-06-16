// problem link -> https://leetcode.com/problems/set-matrix-zeroes/submissions/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j,colm0=0; 
        for(i=0;i<matrix.size();i++){
            if(matrix[i][0]==0) colm0=1;
            for(j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    matrix[0][j]=0,matrix[i][0]=0;
            }
        }
        for(i=matrix.size()-1;i>=0;i--){
            for(j=matrix[0].size()-1;j>0;j--){
                if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
            }
            if(colm0==1) matrix[i][0]=0;
        }
    }
};

// time -> O(n*m)
// space -> O(1)