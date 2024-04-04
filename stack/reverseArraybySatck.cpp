#include<bits/stdc++.h>
using namespace std;

int main(){
    string st="deepak";

    stack<char>s;

    for(int i=0; i<st.length(); i++){
        char ch=st[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout<<"Answer is: "<<ans<<endl;
}