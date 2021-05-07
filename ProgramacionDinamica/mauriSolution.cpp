#include <iostream>
#include <vector>
#include <cstring>

using namespace std;



int knapsack(vector<pair<int, int>> items, int knsize){
    int dp[1000000];
    memset(dp, 0, sizeof(dp)/sizeof(dp[0]));
    for  (int i = 0; i < items.size(); i++){
        for (int j = knsize; j >= items[i].first; j--){
            int value = 0;
            value = max(dp[j], items[i].second + dp[j-items[i].first]);
            dp[j] = value;
        }
    }
    
    return dp[knsize];
}

int main(){
    vector<pair<int, int>> items;
    items.push_back(make_pair(5, 10));
    items.push_back(make_pair(7, 50));
    items.push_back(make_pair(8, 75));
    items.push_back(make_pair(15, 20));
    items.push_back(make_pair(25, 39));
    
    cout<<knapsack(items, 12)<<endl;
}