class Solution {
public:
    
    int partition(int l,int h,vector<int>& nums){
        int pivot=nums[l],i=l,j=h;
        while(i<j){
            while(nums[i]<=pivot && i<j){
                i++;
            }
            while(nums[j]>pivot){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
    
    int rec(int l,int h,vector<int>& nums,int k){
        if(l<h){
            int ind=partition(l,h,nums);
            if(ind==k){
                return nums[ind];
            }
            else if(k<ind){
                return rec(l,ind-1,nums,k);
            }
            else{
                return rec(ind+1,h,nums,k);
            }
        }
        else if(l==h){
            return nums[l];
        }
        return INT_MAX;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return rec(0,n-1,nums,n-k);
    }
};