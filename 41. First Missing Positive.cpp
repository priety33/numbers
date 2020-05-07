class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        int i=0;
        int j=nums.size()-1;
        while(i<nums.size() && i<=j){ //moving all 0 and negatives at end of array
            if(nums[i]<=0){
                swap(nums[i],nums[j]);
                j--;
            }else{
                i++;
            }
        }
        for(i=0;i<=j && i<nums.size();i++){ //placing positive ints at their correct indices
            if(nums[i]>0 && nums[i]-1<=j && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
                if(nums[i]<=j && nums[i]!=i+1) i--;
            }
        }
        for(i=0;i<=j && i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return j+2;
    }
};
