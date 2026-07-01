#include <iostream>
using namespace std;
int main() {
    
    int nums1[] = {1,2,3},nums2[]={2,4};
    int n1=sizeof(nums1),n2=sizeof(nums2);
    int i=0,j=0;
    while(j!=n2 && i!=n1)
    {
        if(nums1[i]==nums2[j])
        {
            return nums1[i];
        }
        else if(nums1[i]>nums2[j])
        {
            j++;
        }
        else{
            i++;
        }
    }

    return 0;
}

/*
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=size(nums1),n2=size(nums2);
        int i=0,j=0;
        while(i!=n1 && j!=n2)
        {
            if(nums1[i]==nums2[j])
            {
                return nums1[i];
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};

*/