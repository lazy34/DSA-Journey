#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& inter) {
        std::vector<std::vector<int>> ans;
        int n = inter.size();
        if (n == 0)
            return ans;
        std::sort(inter.begin(), inter.end()); // Sort array
        ans.push_back(inter[0]);
        int j = 0;
        for (int i = 1; i < n; i++) {
            // If next interval merges with the previous
            if (ans[j][1] >= inter[i][0]) {
                // Continue until we get the overlapping intervals
                ans[j][1] = std::max(ans[j][1], inter[i][1]);
            } else {
                j++;
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input: intervals
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Call the merge function
    std::vector<std::vector<int>> mergedIntervals = solution.merge(intervals);

    // Display the merged intervals
    std::cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
