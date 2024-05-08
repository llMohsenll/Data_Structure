#ifndef POLONOMIAL_H
#define POLONOMIAL_H


#include <math.h>
#include <iostream>
using namespace std;
class polonomial {
    public:
    polonomial();
    ~polonomial();
    int s[2][100];
    // z -> zarib
    // Tav -> tavan
    void push(int Z,int Tav);
    int claculate(int x);
    int pop (int Tav);
    int i =0 ;


};

polonomial ::polonomial(){

}
polonomial::~polonomial(){
    delete s;
}
void polonomial ::push(int Tav,int Z){
    bool check =0;
    for(int j=0;j<i;j++){
        if(s[0][j] == Tav) {s[1][j]+=Z;
            check=1;
        }

    }
    if(!check){
    s[0][i]=Tav;
    s[1][i]=Z;
    i++;
    }
    //cout<< i<<endl;
}
int polonomial :: pop ( int Tav){
    for(int j=0 ; j<i;j++){
        if(s[0][j]== Tav){
            for(int k= j;k<i;k++){
                s[0][k]=s[0][k+1];
                s[1][k]= s[1][k+1];
            }
        }
    }
}
int polonomial:: claculate(int x){
int Ans=0;
for(int j=0;j<i;j++){
    Ans+=pow(x,s[0][j])*s[1][j];
}
return Ans;

}
#endif // POLONOMIAL_H
