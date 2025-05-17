//1572. Matrix Diagonal Sum
//
//Given a square matrix mat, return the sum of the matrix diagonals.
//Only include the sum of all the elements on the primary diagonal and 
//all the elements on the secondary diagonal that are not part of the primary diagonal.
// 
//Example 1:
//Input: mat = [[1,2,3],
//              [4,5,6],
//              [7,8,9]]
//Output: 25
//Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
//Notice that element mat[1][1] = 5 is counted only once.
//
//Example 2:
//Input: mat = [[1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1],
//              [1,1,1,1]]
//Output: 8
//
//Example 3:
//Input: mat = [[5]]
//Output: 5

// ------------------------ The below code fails some testcases for some reasons -------------------------------

// class Solution {
// public:
//     int diagonalSum(vector<vector<int>>& mat) {
//         int sum = 0;

//         for(int i = 0; i < mat.size(); i++)
//         {
//             for(int j = 0; j < mat[0].size(); j++)
//             {
//                 if((j == i) || (j + i == mat.size() - 1)) // Fix: Use mat.size() (rows) for secondary diagonal condition
//                     sum += mat[i][j];
//             }
//         }

//         if(mat.size() % 2 == 1 && mat.size() == mat[0].size()) // Fix: Only subtract middle if matrix is square
//         {
//             sum -= mat[mat.size()/2][mat.size()/2];
//         }

//         return sum;
//     }
// };

// ------------------------------------------------ Solution 2 --------------------------------------------------------

// class Solution {
// public:
//     int diagonalSum(vector<vector<int>>& mat) {
//         int m = mat.size();       // Number of rows
//         int n = mat[0].size();    // Number of columns
//         int sum = 0;

//         for (int i = 0; i < min(m, n); i++) {  
//             sum += mat[i][i];  // Primary diagonal
//             if (i != n - 1 - i)  // Avoid double-counting center element
//                 sum += mat[i][n - 1 - i]; // Secondary diagonal
//         }

//         return sum;
//     }
// };

// ------------------------------------------------- Solution 3 ------------------------------------------------------

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();  // Since it's a square matrix, rows == cols

        for(int i = 0; i < n; i++)
        {
            sum += mat[i][i];               // Primary diagonal
            if(i != n - 1 - i)              // Prevent double-counting the center element
                sum += mat[i][n - 1 - i];   // Secondary diagonal
        }

        return sum;
    }
};

