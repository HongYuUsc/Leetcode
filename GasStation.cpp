class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int l = gas.size();
        if(l == 0)
            return -1;
        for(int i=0;i<2*l;i++){
            diff.push_back(gas[i%l]-cost[i%l]);
        }
        int j(0),k(0),sum(0);
        while(j-k<l && j<diff.size()){
            sum += diff[j];
            if(sum>=0){
                j++;
            }
            else{
                sum = 0;
                k=j+1;
                j++;
            }
        }
        if(j-k == l)
            return k;
        else
            return -1;
    }
};
