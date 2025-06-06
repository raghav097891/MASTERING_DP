// BRUTE FORCE
#include <bits/stdc++.h>
using namespace std;
int min_cost(int n){
    if(n==1){
        return 0;
    }
    if(n%2==0){
        return 1+min_cost(n/2);
    }
    else{
        return min(1+min_cost(n+1),1+min_cost(n-1));
    }
}
int main(){
    int n;
    cin>>n;
    int min=0;
    min=min_cost(n);
    cout<<min;
    return 0;
}
//DP SOLUTION
int min_cost(int n,unordered_map<int,int>&dp){
    if(n==1){
        return 0;
    }
    if(dp.count(n))return dp[n];
    if(n%2==0){
        return dp[n]=1+min_cost(n/2,dp);
    }
    else{
        return dp[n]=min(1+min_cost(n+1,dp),1+min_cost(n-1,dp));
    }
}
int main(){
    int n=11;
   
    unordered_map<int,int>dp;
    min_cost(n,dp);
    cout<<dp[n];
    return 0;
}
//SOLUTION BY OBSERVATION LESS SPACE COMPLEXITY
int main(){
    int n;
    cin>>n;
    int min_cost=0;
    while(n!=1){
        if((n&1)==0){
            min_cost+=1;
            n=n/2;
        }
        else{
            if(n==3){
                min_cost+=1;
                n-=1;
            }
            else if(n&2==1){// As when number is odd but doing this will allow us to change the number such that it can atleast be divisible by 2^2 or more.
                min_cost+=1;
                n+=1;
            }
            else{
                min_cost+=1;
                n-=1;
            }
        }
    }
    cout<<min_cost<<endl;
    return 0;
}