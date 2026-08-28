class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // At most one character can have odd frequency
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != 0)
                    return "";

                mid = 'a' + i;
                cnt[i]--;
            }
        }

        // cnt now contains even frequencies
        // We store pairs in the left half
        vector<int> leftCnt(26);

        for (int i = 0; i < 26; i++) {
            leftCnt[i] = cnt[i] / 2;
        }

        int half = n / 2;

        // Try to make the left half equal to target's left half
        for (int i = 0; i < half; i++) {
            leftCnt[target[i] - 'a']--;
        }

        // Check if counts are valid
        bool possible = true;

        for (int x : leftCnt) {
            if (x < 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            string left = target.substr(0, half);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += mid;

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        // Backtrack from right to left
        for (int i = half - 1; i >= 0; i--) {

            // Restore target[i]
            leftCnt[target[i] - 'a']++;

            // If prefix before i cannot be formed, continue
            bool ok = true;

            for (int x : leftCnt) {
                if (x < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            int cur = target[i] - 'a';

            // Try a character greater than target[i]
            for (int j = cur + 1; j < 26; j++) {

                if (leftCnt[j] == 0)
                    continue;

                leftCnt[j]--;

                string left = target.substr(0, i);

                left += char('a' + j);

                // Fill remaining positions with smallest characters
                for (int k = 0; k < 26; k++) {
                    while (leftCnt[k] > 0) {
                        left += char('a' + k);
                        leftCnt[k]--;
                    }
                }

                string right = left;
                reverse(right.begin(), right.end());

                string ans = left;

                if (n % 2)
                    ans += mid;

                ans += right;

                return ans;
            }
        }

        return "";
    }
};