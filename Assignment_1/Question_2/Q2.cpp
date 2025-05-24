#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fn(vector<int>& echoes){
    vector<int>tmp;
    tmp.push_back(*echoes.begin());
    for (vector<int>::iterator it = echoes.begin() + 1; it != echoes.end(); it++) {
        auto it1 = upper_bound(tmp.begin(), tmp.end(), *it);
        if (it1 == tmp.end()) {
            tmp.push_back(*it);
        } 
        else {
            *it1 = *it;
        }
    }
    return tmp.size();
}
int main(){
    int n;
    cout<<"Please enter a number";
    cin>>n;
    vector<int> echoes(n);
    for(int i=0;i<n;i++){
        cin>>echoes[i];
    }
    int max_length=fn(echoes);
    cout<<max_length;
    return 0;
}