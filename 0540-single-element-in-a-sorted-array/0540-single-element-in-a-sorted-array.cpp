class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap;
        if(nums.size()==1) {
            return nums[0];
        }
        
        for(auto&it:nums) {
            umap[it]++;
        }
        
        for(auto&it:umap) {
            if(it.second==1) {
                return it.first;
            }
        }
        return 0;
    }
};