// space complexity = m*n = O(mn) -- Here space complexity does not matter as we store the result required by question, not storing anything for computation?

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        r = ((n - r) < r) ? n - r : r;

        long long ans = 1;
        for (int i = 1; i <= r; ++i) {
            ans = ans * n;
            ans = ans / i;
            n--;
        }

        return ans;
    }

    vector<int> generateSingleRow(int rowNum) {
        vector<int> row = {1}; // 1st element added here

        long long ans = 1;
        for (int i = 1; i < rowNum; ++i) {
            ans = ans * (rowNum - i); // here i variable is also the column number, so we can rename i as col
            ans = ans / i;
            row.push_back(ans);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;

        for (int i = 1; i <= numRows; ++i) {
            vector<int> row = generateSingleRow(i);
            rows.push_back(row);
        }

        return rows;
    }
};

int main()
{
    Solution s;

    // Q1 - given row and position, return value from pascal's triangle
    // time complexity = r = O(r)
    int rowVal = 5;
    int positionVal = 3; // -- r
    int result = s.nCr(rowVal - 1, positionVal - 1); // -1 as index starts from 0 for nCr
    cout << result << "\n\n";

    // Q2 - given row number, return that row of pascal's triangle
    // time complexity = n = O(n)
    int rowNum = 5; // -- n
    vector<int> row = s.generateSingleRow(rowNum);
    for (int i = 0; i < rowNum; ++i) {
        cout << row[i] << " ";
    }
    cout << "\n\n";

    // Q3 - given number of rows, return all those rows of pascal's triangle
    // time complexity = n * n = n^2 = O(n^2)
    int numRows = 5;
    vector<vector<int>> rows = s.generate(numRows);
    for (int i = 0; i < rows.size(); ++i) {
        for (int j = 0; j < rows[i].size(); ++j) {
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }
}