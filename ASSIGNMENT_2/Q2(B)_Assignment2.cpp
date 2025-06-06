#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1)cout<<arr[0];
    if(n==2)cout<<max(arr[0],arr[1]);
    else{
        int prev2=arr[0];int prev1=max(arr[0],arr[1]);int curr=prev1;
        for(int i=2;i<n-1;i++){
            int take=arr[i]+prev2;
            int nottake=prev1;
            curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        int pre2=arr[1];int pre1=max(arr[2],arr[1]);int currb=pre1;
        for(int i=3;i<n;i++){
            int take=arr[i]+pre2;
            int nottake=pre1;
            currb=max(take,nottake);
            pre2=pre1;
            pre1=currb;
        }
        cout<<max(curr,currb);
    }
    return 0;
}