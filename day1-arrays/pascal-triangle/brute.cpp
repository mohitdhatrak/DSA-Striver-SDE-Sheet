// time complexity = m*n = n^2 = O(n^2) ?
// space complexity = m*n = O(mn) -- Here space complexity does not matter as we store the result required by question, not storing anything for computation?

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;

        for (int i = 0; i < numRows; ++i) {
            vector<int> v = {1};
            int size = i + 1;

            if (size > 1) {
                for (int j = 1; j <= size - 2; ++j) {
                    int value = rows[i - 1][j - 1] + rows[i - 1][j];
                    v.push_back(value);
                }

                v.push_back(1);
            }

            rows.push_back(v);
        }

        return rows;
    }
};

int main()
{
    Solution s;
    int numRows = 5;
    vector<vector<int>> rows = s.generate(numRows);

    for (int i = 0; i < rows.size(); ++i) {
        for (int j = 0; j < rows[i].size(); ++j) {
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }
}