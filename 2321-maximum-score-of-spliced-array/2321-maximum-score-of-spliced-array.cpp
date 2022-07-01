class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),sum1=0,sum2=0,max_so_far1=0,max_here1=0,max_so_far2=0,max_here2=0;
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
            max_here1+=(nums2[i]-nums1[i]);
            max_here2+=(nums1[i]-nums2[i]);
            max_so_far1=max(max_so_far1,max_here1);
            max_so_far2=max(max_so_far2,max_here2);
            if(max_here1<0){
                max_here1=0;
            }
            if(max_here2<0){
                max_here2=0;
            }
        }
        return max(sum1+max_so_far1,sum2+max_so_far2);
    }
};