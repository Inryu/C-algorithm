#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

struct Student{
    string name;
    int korean,english, math;

    Student(string a, int b, int c, int d){
        name=a;
        korean=b;
        english=c;
        math=d;
    }

    bool operator<(const Student &b)const{
        if(korean!=b.korean) return korean>b.korean;
        if(english!=b.english) return english<b.english;
        if(math!=b.math) return math>b.math;
        return name<b.name;
    }
};

int main(){

    vector<Student> students;
    cin>>N;

    for(int i=0;i<N;i++){
        string name;
        int a,b,c;
        cin>>name>>a>>b>>c;
        students.push_back(Student(name,a,b,c));
    }
    sort(students.begin(), students.end());

    for(auto i:students)
        cout<<i.name<<"\n";
}