#include <iostream>
using namespace std;

int main(){
    int A,B,i,sum=0;

    cin>>A>>B;

    for(i=A;i<B;i++){
        cout<<i<<" + ";
        sum+=i; 
    }
 
    cout<<B<<" = "<<(sum+B);

    return 0;

}
