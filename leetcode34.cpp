class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        int low = 0;
        int high = nums.size() - 1;
        vector<int> range(2);
        range[0] = -1;
        range[1] = -1;
        if(nums.size() == 0)
            return range;
        while(high > low)
        {
            int mid = (high + low)/2;
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        if(nums[low] != target)
            return range;
        int begin = low;
        low = 0;
        high = nums.size() - 1;
        while(high > low)
        {
            int mid = (high + low)/2;
            if(nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        int end;
        if(nums[high] == target || high == 0)
            end = high;
        else
            end = high - 1;
        range[0] = begin;
        range[1] = end;
        return range;
    }
};
