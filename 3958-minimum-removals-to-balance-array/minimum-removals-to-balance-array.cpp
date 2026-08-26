class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int i=0;
        int j=0;
        long long min=nums[0];
        long long max=nums[0];
        int L=1;

        while(j<n){
            min=nums[i];
            max=nums[j];

            while(i<j && max>k*min){
                i++;
                min=nums[i];
            }
          L=std::max(L,j-i+1);
          j++;
        }
        return n-L;
    }
};