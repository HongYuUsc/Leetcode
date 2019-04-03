class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        
        if(A.size() == 0)
        {
            return true;
        }
        
        priority_queue<int> pq;
        for(int i=0;i<A.size();i++)
        {
            pq.push(abs(A[i]));
        }
                    
        vector<int> B(A.size());
        for(int i=0;i<A.size();i++)
        {
            B[B.size() - 1 - i] = pq.top();
            pq.pop();
        }
        
        map<int,int> flag;
        map<int,int>::iterator it;
        for(int i=0;i<B.size();i++)
        {
            it = flag.find(B[i]);
            if(it != flag.end())
            {
                flag[B[i]] ++;
            }
            else
            {
                flag[B[i]] = 1;
            }
        }
        

        for(int i=0;i<B.size() - 1;i++)
        {
            if(flag[B[i]] != 0)
            {
                int k = 2 * B[i];
                it = flag.find(k);
                if(it != flag.end() && flag[k] != 0)
                {
                    flag[k] -= 1;
                    flag[B[i]] -= 1;
                }
                else
                {
                    return false;
                }
            }
            
        }
        
        return true;
    }
};
