class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
         int result=0;

         for(int i=0;i<nums.size()>>1;i++){
            result=max(result,nums[i]+nums[j-i]);
         }
        return result;
    }
};