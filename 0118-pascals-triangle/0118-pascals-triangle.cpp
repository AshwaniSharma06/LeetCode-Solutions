class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {

            // Every row contains i + 1 elements
            vector<int> row(i + 1, 1);

            // Calculate middle elements
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1]
                       + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};