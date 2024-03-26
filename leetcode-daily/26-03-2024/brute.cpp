// Hard - https://leetcode.com/problems/first-missing-positive/?envType=daily-question&envId=2024-03-26

// time complexity = n + n = O(2n)
// space complexity = n = O(n) -- make this O(1) for optimal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        int smallest = 1;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashTable.find(nums[i]);
            if (it == hashTable.end()) { // if doesn't exist in hash table, add it
                hashTable[nums[i]] = 1;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashTable.find(i + 1);
            if (it == hashTable.end()) { // if smallest positive integer doesn't exist in hash table, make it smallest
                smallest = i + 1;
                break;
            } else if (i + 1 == nums.size()) { // edge case - if it is last element and smallest not found, then make next number as smallest 
                smallest = i + 2;
            }
        }

        return smallest;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 0};
    cout << s.firstMissingPositive(nums) << endl;
}