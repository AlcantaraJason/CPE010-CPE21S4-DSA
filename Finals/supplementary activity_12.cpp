#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>>& mat, int row, int col, int cost) {
    if (row < 0 || col < 0) return 0;
    if (row == 0 && col == 0) return (mat[0][0] == cost) ? 1 : 0;

    return countPaths(mat, row - 1, col, cost - mat[row][col]) +
           countPaths(mat, row, col - 1, cost - mat[row][col]);
}

int main() {
    vector<vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };
    
    int targetCost = 25;
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int result = countPaths(matrix, rows - 1, cols - 1, targetCost);
    cout << "Number of paths with cost " << targetCost << " = " << result << endl;
    return 0;
}
