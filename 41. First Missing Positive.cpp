//gfg solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]<=0 || nums[i]-1>=n) continue;
            
            int val= nums[i];
            while(nums[val-1]!=val) {
                int nextval= nums[val-1];
                nums[val-1]= val;
                val= nextval;
                if(val<=0 || val-1>=n) break;
            }
        }
        for(int i=0; i<n; i++) if(nums[i]!=i+1) return i+1;
        return n+1;
    }
};
