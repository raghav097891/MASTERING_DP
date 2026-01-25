#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges = {
    {7, 19}, {2, 14}, {0, 2}, {13, 19}, {4, 13}, {10, 19}, {6, 8}, {1, 13}, {5, 17}, {8, 17},{3, 8}, {12, 18}, {4, 16}, {9, 18}, {0, 7},
    {2, 9}, {7, 13}, {5, 14}, {10, 16}, {6, 12},{1, 8}, {3, 12}, {0, 12}, {11, 17}, {13, 15}, {8, 10}, {4, 6}, {7, 16}, {2, 4}, {9, 15},
    {5, 7}, {12, 14}, {0, 9}, {6, 18}, {1, 10}, {3, 15}, {11, 13}, {7, 9}, {10, 12}, {5, 11},{8, 14}, {15, 17}, {14, 16}, {4, 10}, {6, 15}, {0, 5}, {2, 11}, {1, 6}, {9, 11}, {5, 6},{3, 5}, {16, 18}
};
vector<vector<int>> adjacent(20);
void builddata() {
    int n=edges.size();
    for (int i=0;i<n;i++) {     
        int u = edges[i].first;       
        int v = edges[i].second;     
        adjacent[u].push_back(v);      
    }
}
int main() {
	builddata();
	vector<int>no_of_borrowers(20,0);//To calculate no. of borrowers for each bank
	for(auto i: edges){
	    no_of_borrowers[i.second]++;//Adding no. of borrowers
	}
	queue<int>allowed_defaulting;//To maintain the order in which they get defaulted and to store which all can be defaulted
	//First finding the banks which have 0 borrowers to start defaulting 
	for(int i=0;i<20;i++){
	    if(no_of_borrowers[i]==0)allowed_defaulting.push(i);
	}
	while(!allowed_defaulting.empty()){
	    int curr=allowed_defaulting.front();
	    allowed_defaulting.pop();//Defaulted current bank
	    cout<<curr;
	    for(int lender: adjacent[curr]){
			//To reduce no. of borrowers left , so that when the count becomes zero it can become ready to default
	        no_of_borrowers[lender]--;
	        if(no_of_borrowers[lender]==0){
	            allowed_defaulting.push(lender);
	        }
	    }
	    if(!allowed_defaulting.empty())cout<<" ";
	}
	return 0;
}
