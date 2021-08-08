#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){

    int N,M;
    int cnt[50][4]={0,}; // 각 열마다 A,C,G,T 순으로 몇개 들어있는지

    cin>>N>>M;

    // 입력과 함께, 각 열마다 A,C,G,T가 몇개 들어있는지 세기
    for(int i=0;i<N;i++){
        string dna;
        cin>>dna;

        for(int j=0;j<M;j++){
            switch(dna[j]){
                case 'A':
                    cnt[j][0]++;
                    break;
                case 'C':
                    cnt[j][1]++;
                    break;
                case 'G':
                    cnt[j][2]++;
                    break;
                case 'T':
                    cnt[j][3]++;
                    break;

            }
        }
    }

    string res="";
    int HD=0; //해밍 디스턴스

    // 각 열마다.
    for(int i=0;i<M;i++){
        int max=-1;
        int alphaIdx=0;

        // 어떤 알파벳이 제일 많은지
        for(int j=0;j<4;j++){
            if(cnt[i][j]>max){
                max=cnt[i][j];
                alphaIdx=j;
            }
        }

        HD+=N-max; // N-max만큼 다름.


        switch (alphaIdx) {
            case 0:
                res+="A";
                break;
            case 1:
                res+="C";
                break;
            case 2:
                res+="G";
                break;
            case 3:
                res+="T";
                break;
        }
    }

    cout<<res<<"\n"<<HD<<"\n";

}
