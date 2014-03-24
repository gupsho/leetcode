class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> nums;
        int index1 = 0, index2 = 0;
        
        for(int i = 0; i < numbers.size(); i++)
            nums[numbers[i]] = i;
            
        for(int i = 0; i < numbers.size(); i++)
        {
            int num = target - numbers[i];
            if(nums.find(num) != nums.end() && nums[num] != i)
            {
                index1 = i + 1;
                index2 = nums[num] + 1;
                break;
            }

        }
        
        result.push_back(index1);
        result.push_back(index2);
        
        return result;
    }
};
