#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int start, int end) {
    int answer = 0;

    while(start<=end){
        if(arr[start]==arr[end]){ //동일하면
            start++;
            end--;
        }else{ //다르면
            if(arr[start]<arr[end]){
                arr[start+1]=arr[start]+arr[start+1];
                start++;
            }else{
                arr[end-1]=arr[end]+arr[end-1];
                end--;
            }
            answer++;

        }

    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, i;

    int start = 0;
    int end = 0;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++) {
        cin>>arr[i];
    }
    end = n - 1; //마지막 인덱스

    cout << solution(arr, start, end);

    return 0;
}