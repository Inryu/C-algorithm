#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N;
        vector<pair<int,int>> score; // (서류, 면접)
        cin>>N;

        for(int i=0;i<N;i++){
            int a,b; cin>>a>>b;
            score.push_back(make_pair(a,b));
        }

        sort(score.begin(), score.end()); // 서류 순위순으로 정렬

        int cnt=1;
        int interviewScore=score[0].second; //1위의 면접 점수

        // 그 뒤에부턴, 면접 점수가 무조건 더 높아야 채용
        for(int i=1;i<N;i++){
            if(score[i].second<interviewScore){
                cnt++;
            }
            // 제일 높은 순위로 업데이트
            interviewScore=min(score[i].second, interviewScore);
        }

        cout<<cnt<<"\n";
    }

    return 0;
}

