#include <iostream>//This algorithm has time complexity of O(n+k) where k=range so if the differnce btw the max and min number is less this algorithm can be used
#include <vector>
#include <algorithm>
using namespace std;
vector<int> numsort(const vector<int>& arr){
    int max=*max_element(arr.begin(),arr.end());
    int min=*min_element(arr.begin(),arr.end());
    int range=max-min+1;
    vector<int> count(range,0);//Assigning a vector who have range no.of elements and all are zero
    for(auto t : arr){
        count[t-min]++;// Doing this will ensure that no.of count of min value remains at zero index and the value greater than that on further indexes
    }
    vector<int>output(arr.size());
    int index=0;
    for(int i=0;i<range;i++){
        while(count[i]>0){
            output[index]=i+min;//Ensuring that if count of any number is more than one than it comes more than one
            index++;
            count[i]--;
        }
    }
    return output;
}
