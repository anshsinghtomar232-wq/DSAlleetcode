class Solution {
public:
    bool isPalindrome(string_view str) {
        if (str.empty()) {
            return true;
        }

        size_t left {0};
        size_t right {str.length() - 1}; // substract by 1 cuz index start from 0

        int first_ch {0}, second_ch {0};

        while (left < right) {
            // left
            first_ch = std::tolower(str[left]);
            if (!isalnum(first_ch))
            {
                left++;
                continue;
            }

            // right
            second_ch = std::tolower(str[right]);
            if (!isalnum(second_ch))
            {
                right--;
                continue;
            }

            if (first_ch != second_ch)
            {
                return false;
            }

            left++; right--;
        }

        return true;
    }
};