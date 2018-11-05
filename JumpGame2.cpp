class Solution {
public:
    int jump(vector<int>& nums) {
        int currfast = 0, currend = 0,jumps = 0;
        for(int i=0;i<nums.size()-1;i++){
            currfast = max(currfast,nums[i]+i);
            if(i == currend){
                jumps++;
                currend = currfast;
                if(currend>nums.size()-1)
                    break;
            }
        }
        return jumps;
    }
};
