// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        vector<int> H(n,0);
        vector<int> L(n,0);
        vector<int> R(n,n);
        int maxArea = 0;
        for(int i = 0; i < m; ++i) {
            int left = 0;
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                } else {
                    H[j] = 0;
                    L[j] = 0;
                    left = j+1;
                }
            }
            int right = n;
            for(int j = n-1; j >= 0; --j) {
                if(matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    maxArea = max(maxArea, H[j]*(R[j]-L[j]));
                } else {
                    R[j] = n;
                    right = j;
                }
            }
        }
        return maxArea;
    }
};
