class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        while(1)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if(tortoise == hare)
                break;
        }

       int ptr1 = nums[0];
       int ptr2 = tortoise;
        while(ptr1 != ptr2)
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
        
    }
};
