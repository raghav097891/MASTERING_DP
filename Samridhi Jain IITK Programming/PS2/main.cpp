#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges = {
    {7, 19}, {2, 14}, {0, 2}, {13, 19}, {4, 13}, {10, 19}, {6, 8}, {1, 13}, {5, 17}, {8, 17},{3, 8}, {12, 18}, {4, 16}, {9, 18}, {0, 7},
    {2, 9}, {7, 13}, {5, 14}, {10, 16}, {6, 12},{1, 8}, {3, 12}, {0, 12}, {11, 17}, {13, 15}, {8, 10}, {4, 6}, {7, 16}, {2, 4}, {9, 15},
    {5, 7}, {12, 14}, {0, 9}, {6, 18}, {1, 10}, {3, 15}, {11, 13}, {7, 9}, {10, 12}, {5, 11},{8, 14}, {15, 17}, {14, 16}, {4, 10}, {6, 15}, {0, 5}, {2, 11}, {1, 6}, {9, 11}, {5, 6},{3, 5}, {16, 18}
};
vector<int> exposure = {
    20, 40, 35, 60, 60, 35, 60, 35, 30, 30, 45, 25, 25, 25, 25, 30, 30, 70, 45, 25, 20, 45, 30, 30,40, 40, 80, 55, 70, 50, 55, 70, 45, 35, 50, 30, 55, 45, 60, 65, 65, 35, 50, 35, 50, 60, 65, 55, 35, 20, 20,45
};
vector<int> thresholds = {
    100, 0, 200, 30, 90, 0, 70, 170, 50, 80, 110, 40, 60, 130, 190, 120, 140, 180, 160, 150
};
vector<vector<pair<int, int>>> adjacent(20);
//Building our graph
void builddata() {
    int n=edges.size();
    for (int i=0;i<n;i++) {     
        int u = edges[i].first;       
        int v = edges[i].second;     
        adjacent[u].push_back({v,exposure[i]});      
    }
}
void solution(){
    int k;
    cin>>k;
    vector<int> current_path;
    set<int> defaulted_banks;
    vector<int>current_amount_wasted(20,0);//Basically the loan amount which are from defaulted banks
    for(int i=0;i<k;i++){
        int bankno;
        cin>>bankno;
        if(defaulted_banks.find(bankno)==defaulted_banks.end()){
            defaulted_banks.insert(bankno);
            current_path.push_back(bankno);
        }
    }
    sort(current_path.begin(), current_path.end());
    //BFS style traversing, which ensures to stop loop when no more banks are defaulting
    while(!current_path.empty()){
        for(int i=0;i<current_path.size();i++){
            cout<<current_path[i];
            if(i!=current_path.size()-1)cout<<" ";
        }
        cout<<endl;
        set<int> tmp;//For creating list of banks for next round of defaulting
        for(int i=0;i<current_path.size();i++){
            for(auto suffered: adjacent[current_path[i]]){
                int lender=suffered.first;
                int amt=suffered.second;
                if(defaulted_banks.find(lender)==defaulted_banks.end()){
                    current_amount_wasted[lender]+=amt;//Add the total lost amount by banks borrower defaulting
                    if(current_amount_wasted[lender]>=thresholds[lender]){//If current waste amount cross the threshold for a bank
                        defaulted_banks.insert(lender);
                        tmp.insert(lender);
                    }
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
