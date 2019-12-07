//两数之和
//unordered_map查找速度比vector快很多
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size<=1) return NULL;
        vector<int> ans;
        auto d=nums.begin();
        for(auto i=nums.begin();i<nums.end()-1;i++){
            d=find(i+1,nums.end(),target-*i);
            if(!=nums.end()){
                ans.push_back(i-nums.begin());
                ans.push_back(d-nums.begin());
                break;
            }
        }
        return ans;
    }
};

//类似的方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        while(nums.size()!=1){
            auto d=find(nums.begin(),nums.end()-1,target-*(nums.end()-1));
            if(d!=nums.end()-1){
                ans.push_back(d-nums.begin());
                ans.push_back(nums.end()-1-nums.begin());
                break;
            }
            else nums.pop_back();
        }
        return ans;
    }
};
