#include <iostream>
using namespace std;
int main() {
    int n=4,start=3;
    int nums[n],ans=0;
        for(int i=0;i<n;i++)
        {
            nums[i]=start+2*i;
            ans^=nums[i];
        }
    cout<<ans<<endl;
    return 0;
}

/*
class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n],ans=0;
        for(int i=0;i<n;i++)
        {
            nums[i]=start+2*i;
            ans^=nums[i];
        }
        return ans;
    }
};
*/