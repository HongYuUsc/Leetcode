class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_val(2);
        vector<int> min_val(2);
        max_val[0] = nums[0];
        min_val[0] = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                max_val[i%2] = max(nums[i],max_val[(i-1)%2]*nums[i]);
                min_val[i%2] = min(nums[i],min_val[(i-1)%2]*nums[i]);
            }
            else
            {
                max_val[i%2] = max(nums[i],min_val[(i-1)%2]*nums[i]);
                min_val[i%2] = min(nums[i],max_val[(i-1)%2]*nums[i]);
            }
            if(res<max_val[i%2])
                res = max_val[i%2];
        }
        return res;
    }
};
