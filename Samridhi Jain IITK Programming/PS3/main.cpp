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
vector<vector<pair<int, int>>> lender(20);
//Storing data in a way that we can see borrowers of each bank
void builddata() {
    int n=edges.size();
    for (int i=0;i<n;i++) {     
        int u = edges[i].first;       
        int v = edges[i].second;     
        lender[v].push_back({u,exposure[i]});      
    }
}

int maxdebt(int current_bank,vector<int>&dp){
    if(dp[current_bank]!=-1){
        return dp[current_bank];//If aldready calculated why to calculate again 
    }
    int max_debt=0;
	//Asking all its borrower how much max exposure you can pass to me
    for(auto i: lender[current_bank]){
        int debtor_exposure=i.second;
        int debtor=i.first;
        int curr_debt=maxdebt(debtor,dp)+debtor_exposure;// It works in chain so for finding max exposure for this bank we will ask its borrower bank regarding what is their max + current exposure
        max_debt=max(max_debt,curr_debt);//Simple dp statement
    }
    return dp[current_bank]=max_debt;
}
int main() {
	builddata();
	vector<int>dp(20,-1);//Stores the max exposure which can happen this bank
	//Finding max exposure by a chain of borrowing for each bank
	for(int current_bank=0;current_bank<20;current_bank++){
	    cout<<maxdebt(current_bank,dp);
	    if(current_bank!=19)cout<<" ";
	}
	return 0;
}
