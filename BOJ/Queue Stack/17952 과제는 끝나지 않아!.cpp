#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){

    int totalScore=0;
    int N;
    cin>>N;

    stack<pair<int,int>> st;

    for(int i=0;i<N;i++){
        bool isExist; //과제 있는지
        cin>>isExist;

        if(isExist){
            int score,time;
            cin>>score>>time;
            st.push({score,time});
        }

        if(!st.empty()){
            st.top().second--;
            if(st.top().second==0){
                totalScore+=st.top().first;
                st.pop();
            }
        }
    }
    cout<<totalScore<<"\n";
}