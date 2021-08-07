#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> cards;

    cin>>n;
    for(int i=0;i<n;i++){
        int val; cin>>val;
        cards.push_back(val);
    }

    sort(cards.begin(), cards.end());
    reverse(cards.begin(), cards.end());

    int gold=0;
    int lv=cards[0];
    for(int i=1;i<n;i++){
        gold+=lv+cards[i];
    }

    cout<<gold<<"\n";
}
