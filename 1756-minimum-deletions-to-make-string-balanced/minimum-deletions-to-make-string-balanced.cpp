class Solution {
public:
    int minimumDeletions(string s) {

        int aRemaining = 0;

        for(char c : s)
            if(c == 'a')
                aRemaining++;

        int bCount = 0;
        int ans = aRemaining;

        for(char c : s){

            if(c == 'a')
                aRemaining--;
            else
                bCount++;

            ans = min(ans, bCount + aRemaining);
        }

        return ans;
    }
};