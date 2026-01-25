#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges = {
    {7, 19}, {2, 14}, {0, 2}, {13, 19}, {4, 13}, {10, 19}, {6, 8}, {1, 13}, {5, 17}, {8, 17},{3, 8}, {12, 18}, {4, 16}, {9, 18}, {0, 7},
    {2, 9}, {7, 13}, {5, 14}, {10, 16}, {6, 12},{1, 8}, {3, 12}, {0, 12}, {11, 17}, {13, 15}, {8, 10}, {4, 6}, {7, 16}, {2, 4}, {9, 15},
    {5, 7}, {12, 14}, {0, 9}, {6, 18}, {1, 10}, {3, 15}, {11, 13}, {7, 9}, {10, 12}, {5, 11},{8, 14}, {15, 17}, {14, 16}, {4, 10}, {6, 15}, {0, 5}, {2, 11}, {1, 6}, {9, 11}, {5, 6},{3, 5}, {16, 18}
};
vector<vector<int>> adjacent(20);
void builddata() {
    for (auto i : edges) {     
        int u = i.first;       
        int v = i.second;      
        adjacent[u].push_back(v);      
    }
}
void solution(){
    int k;
    cin>>k;
    vector<int> current_path;
    set<int> defaulted_banks;
    for(int i=0;i<k;i++){
        int bankno;
        cin>>bankno;
        if(defaulted_banks.find(bankno)==defaulted_banks.end()){
            defaulted_banks.insert(bankno);
            current_path.push_back(bankno);
        }
    }
    sort(current_path.begin(), current_path.end());
    while(!current_path.empty()){
        for(int i=0;i<current_path.size();i++){
            cout<<current_path[i];
            if(i!=current_path.size())cout<<" ";
        }
        cout<<endl;
        set<int> tmp;
        for(int i=0;i<current_path.size();i++){
            for(int lender: adjacent[current_path[i]]){
                if(defaulted_banks.find(lender)==defaulted_banks.end()){
                    defaulted_banks.insert(lender);
                    tmp.insert(lender);
                }
            }
        }
        current_path.clear();
        for(int i: tmp){
            current_path.push_back(i);
        }
    }
}

int main() {
	builddata();
	int t;
	cin>>t;
	while(t--){
	    solution();
	    if(t!=0)cout<<endl;
	}
	return 0;
}
