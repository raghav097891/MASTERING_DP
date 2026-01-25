#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edges = {
     {0,1},{1, 2}, {2, 3}, {3, 4}, {4, 0}, {2, 5}, {5, 6}, {6, 2}, {7, 8}, {8, 9}, {9, 10}, {10, 7}, {11, 12}, {12, 13}, {13, 14}, 
    {14, 11},{15, 16}, {16, 17}, {17, 18}, {18, 15}, {19, 20}, {20, 21}, {21, 22}, {22, 19}, {23, 24}, {24, 25}, {25, 26}, {26, 23}, 
    {27, 28}, {28, 29},{29, 27}, {3, 4}, {7, 8}, {4, 7}, {10, 11}, {14, 15}, {18, 19}, {22, 23}, {26, 27}, {6, 8}, {9, 12}, {13, 16}, 
    {17, 20}, {21, 24},{25, 28}, {1, 15}, {5, 19}, {8, 23}, {12, 27}, {16, 0}, {20, 7}, {24, 11}, {28, 3}, {0, 29}, {3, 17}, {7, 21}, 
    {11, 25}, {15, 4},{19, 8}, {23, 12}, {27, 16}
};
double raw_probs[] = {
    0.81,0.93, 0.67, 0.61, 0.77, 0.77, 0.89, 0.77, 0.77, 0.67, 0.95, 0.44, 0.44, 0.41, 0.95, 0.41, 0.54, 0.44, 0.38, 0.44, 0.38, 0.41,
    0.95, 0.41, 0.95, 0.41, 0.54, 0.44, 0.38, 0.44, 0.38, 0.41, 0.95, 0.41, 0.95, 0.41, 0.95, 0.41, 0.54, 0.44, 0.38, 0.44, 0.38, 0.41,
    0.95, 0.41, 0.95, 0.41, 0.54, 0.44, 0.38, 0.44, 0.38, 0.41, 0.95, 0.41, 0.95, 0.41, 0.54, 0.44, 0.74
};
vector<vector<pair<int,double>>> adjacent(30);
void builddata() {
    int n=edges.size();
    for (int i=0;i<n;i++) {     
        int u = edges[i].first;       
        int v = edges[i].second;
        double prob=raw_probs[i];
        adjacent[u].push_back({v,prob});      
    }
}

// I found it similar like Dijkstra's algorithm where we find best path to reach from one place to another with minimum distance
void solve(int start_bank,int end_bank){
    priority_queue<pair<double, int>> options;//Basically it shows probabilty of reaching a certain bank being default and the bank no.
    vector<int>previous_bank(30,-1);//To backtrack and get our path back(by remembering to reach here what was the previous best)
    vector<double>max_probability(30,0.0);
    max_probability[start_bank]=1.0;
    options.push({1.0,start_bank});
    while(!options.empty()){
        int current_bank=options.top().second;
        double current_probability=options.top().first;
        options.pop();
        if(current_probability<max_probability[current_bank])continue;//If we have reached this current bank by a better method we could ignore this path
        if(current_bank==end_bank)break;
        //Finding path from current bank to next bank
        for(auto next: adjacent[current_bank]){
            double nxt_probability=next.second*current_probability;
            int nxt_bank=next.first;
            if(nxt_probability>max_probability[nxt_bank]){
                previous_bank[nxt_bank]=current_bank;
                max_probability[nxt_bank]=nxt_probability;
                options.push({nxt_probability,nxt_bank});
            }
        }
    }
    if(max_probability[end_bank]==0.0){
        cout<<fixed<<setprecision(6)<<0.000000<<endl<<endl;
    }
    else {
        cout<<fixed<<setprecision(6)<<max_probability[end_bank]<<endl;
        vector<int>best_path;
        int i=end_bank;
        //As previous of start bank will be -1
        while(i!=-1){
            best_path.push_back(i);
            i=previous_bank[i];
        }
        reverse(best_path.begin(),best_path.end());
        for(int i=0;i<best_path.size();i++){
            cout<<best_path[i];
            if(i!=best_path.size()-1)cout<<" ";
        }
        cout<<endl;
    }
}
int main() {
	builddata();
	int t;
	cin>>t;
	while(t--){
	    int strt,end;
	    cin>>strt>>end;
	    solve(strt,end);
	    if(t>0)cout<<endl;
	}
	return 0;
}
