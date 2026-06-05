class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mid = n / 2;
        
        int sum= 0;
        
        for( int i = 0 ; i < n ; i++ ){
            
        
            sum += mat[i][i];
            
         
            sum += mat[n-1-i][i];
        }
        
        
        if( n % 2 == 1 ){
            
            sum -= mat[mid][mid];
        }
        
        return sum;
    }
};


//  Q2
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int m = mat.size();
        int n = mat[0].size();

        if(m * n != r * c) {
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));

        for(int i = 0; i < m * n; i++) {
            ans[i / c][i % c] = mat[i / n][i % n];
        }

        return ans;
    }
};

//q3
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

        
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};