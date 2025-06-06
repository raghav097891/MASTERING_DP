#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
vector<long long> power(){
    int n=10*10*10*10*10;
    vector<long long>pow2(n);
    pow2[0]=1;
    for(int i=1;i<=n;i++){
        pow2[i]=(2*pow2[i-1])%MOD;
    }
    return pow2;
}
int main(){
    int t;
    cin>>t;
    vector<long long> pow2 = power();
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n);
        vector<int>q(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        long long val = (pow2[p[0]] + pow2[q[0]])%MOD;
        cout << val << " ";
        int maxind1=0;
        int maxind2=0;
        for(int i=1;i<n;i++){
            maxind1=(max(p[maxind1],p[i])==p[maxind1])? maxind1:i;
            maxind2=(max(q[maxind2],q[i])==q[maxind2])? maxind2:i;
            int max1=p[maxind1];
            int max2=q[maxind2];
            if(max1>max2){
                long long val=(pow2[max1]+pow2[q[i-maxind1]])%MOD;
                cout<<val<<" ";
            }
            else if(max1<max2){
                long long val=(pow2[p[i-maxind2]]+pow2[max2])%MOD;
                cout<<val<<" ";
            }
            else if(q[i-maxind1]>p[i-maxind2]){
                long long val=(pow2[max1]+pow2[q[i-maxind1]])%MOD;
                cout<<val<<" ";
            }
            else{
                long long val=(pow2[p[i-maxind2]]+pow2[max2])%MOD;
                cout<<val<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
