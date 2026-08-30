class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find index of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        // Make sure mn is the left index
        // and mx is the right index
        if (mn > mx)
            swap(mn, mx);

        // Case 1: remove both from left
        int left = mx + 1;

        // Case 2: remove both from right
        int right = n - mn;

        // Case 3: min from left, max from right
        int both = (mn + 1) + (n - mx);

        return min({left, right, both});
    }
};