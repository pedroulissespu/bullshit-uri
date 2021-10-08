#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int mw (int a, int b){
    if (b == 0) return a;
    if (a > b) return mw(b, a%b);
    else return mw(a, b%a);
}

int alpha(string x){
    for (int i = 0  ; i < x.size(); i++)
        if (!isalpha(x[i])) return 0;
    return 1;
}

void trata(string &x){
    for (int i = 0 ; i < x.size(); i++){
        if (!isalpha(x[i])) x[i] = ' ';
    }
}

void up(string &x){
    for (int i = 0 ; i < x.size(); i++)
        x[i] = toupper(x[i]);
}

int main (){
    ios_base :: sync_with_stdio(0);
    string x0, x1;
    int c = 0;
    int b = 0;
    int wuw=0;
    map<string,int>m;
    while (cin >> x1){
        trata(x1);
        stringstream ss;
        ss << x1;
        while (ss >> x0){
            if (x0 == "BULLSHIT"){
                   b++;
                   wuw = c;
                   m.clear();
               }

            else{
                up(x0);
                if (!m[x0]){
                    c++;
                    m[x0]++;
                }

            }
        }
    }
    c = wuw;
    if (c == 0) cout << "0 / " << b << '\n';
    else if (b == 0) cout << "0 / 0\n";
    else
    {
           int md = mw(c,b);
        cout << c/md << " / " << b/md << endl;
    }
}
