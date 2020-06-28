//requirements: array contain n+1 elements 1<=a[i]<=n, and only one element is duplicate;
//Fast And Slow Pointer : its mathmatical proven that if theres array of n+1 elements and one dulpicate
//then it act as linked list by next element by the current element as a index;
//Pigeon-hole principle : here elements(n) is a pigeon and n+1 array is hole;

int findDuplicate(vector<int>& nums) {
    //Fast and Slow Pointer O(n)
    // int slow=nums[0];
    // int fast=nums[nums[0]];
    // while(slow!=fast){
    //     slow=nums[slow];
    //     fast=nums[nums[fast]];
    // }
    // fast=0;
    // while(slow!=fast){
    //     fast=nums[fast];
    //     slow=nums[slow];
    // }
    // return slow;
    
    
    //binary search with pigeon-hole principle O(nLogn)
    int l=0,r=nums.size()-1;
    while(l<r){
        int mid=(l+r)/2;
        int count=0;
        for(auto a:nums){
            if(a<=mid) count++;
        }
        if(count<=mid) l=mid+1;
        else r=mid;
    }
    return l;
}