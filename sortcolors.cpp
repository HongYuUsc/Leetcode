class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeropt = 0;
        int twopt = nums.size()-1;
        int i = zeropt;
        while(i<=twopt)
        {
            if(nums[i] == 0)
            {
                swap(nums[zeropt++],nums[i++]);
            }
            else if(nums[i] == 2)
            {
                swap(nums[twopt--],nums[i]);
            }
            else
            {
                i++;
            }
        }
    }
};
