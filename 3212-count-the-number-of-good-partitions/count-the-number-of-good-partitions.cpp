class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int M = 1e9 + 7;
        
        unordered_map<int, int> last_index;
        for (int i = 0; i < n; i++) {
            last_index[nums[i]] = i;
        }

        int result = 1;
        int j = 0;

        for (int i = 0; i < n; i++) {
        
            if (i > j) {
                result = (result * 2) % M;
            }
            j = max(j, last_index[nums[i]]);
        }

        return result;
    }
};