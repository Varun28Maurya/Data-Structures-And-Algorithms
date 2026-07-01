#include<iostream>
using namespace std;
int main()
{
    int n=16;
    if(n<=0)
    {
        cout<<"False";
    }
    if((n&(n-1))==0 && (n-1)%3==0)
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}


/*
O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
    {
        return false;
    }
    if(n==1){
        return true;
    }
    if((n&(n-1))==0 && (n-1)%3==0)
    {
        return true;
    }
    else{
        return false;
    }
    return 0;
    }
};


*/
