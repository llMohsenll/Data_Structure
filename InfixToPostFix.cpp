#include <iostream>
#include <string>
#include<math.h>
#include "stack.h"
using namespace std;
bool check(char n){
if(n=='('||n=='+'||n=='-'||n=='*'||n=='/'||n=='^'){return 1;}
return 0;
}
string InToFix(string infix){
    string postfix = "";
    Stack<char> s(10);
    char n;
    int i;

    for(i =0 ;infix[i]!= '\0';i++ ){
n=infix[i];
        if(check(n)){
            // cout <<n;
            s.push(n);
        }else if(n==')'){
                while(!s.IsEmpty()&& s.Top()!= '('){

                      postfix+=s.Top();
                      postfix+= " ";
                        s.pop();
        }
            s.pop();
        }else if(isalnum(n)){
        int j;
        for(;isalnum(infix[i]);i++){
        postfix+=infix[i];
        }
        i--;
        postfix+= " ";
        }
        }
       while (!s.IsEmpty()) {
    postfix += s.Top();
    s.pop();
}
        return postfix;


}
int CalculatePostfix(string postfix) {
    Stack<int> s(10);
    int i;
    char n;
    for ( i =0 ;postfix[i]!= '\0';i++) {
       n= postfix[i];
    if(isalnum(n)){
            int j ;
            int x=0;
            for(j=0;isalnum(postfix[i]);i++ ){
               x = (x*10)+ ((int)postfix[i]-48);
               j++;
            }
            cout<< x<<endl;
            s.push(x);

        }
        else if(check(n)){
            int operand2 = s.Top();
            s.pop();
            int operand1 = s.Top();
            s.pop();
            int m;
            switch (n) {

            case '+':
                m=operand1 + operand2;
                s.push(m);
                break;
            case '-':
                m=operand1 - operand2;
                s.push(m);
                break;
            case '*':
                m=operand1 * operand2;
                s.push(m);
                break;
            case '/':
                m=operand1 / operand2;
                s.push(m);
                break;
            }
        }
    }

    return s.Top();
}

int main()
{

   string infix;
   cout << "Enter an infix : ";
   cin >> infix;
    string postfix= InToFix(infix);
    cout << "postfix : " <<postfix<< endl;
   int result = CalculatePostfix(postfix);
    cout << "The result is : "<<result<<endl;
    return 0;
}
