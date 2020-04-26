#include <iostream>
#include <vector>
using namespace std;

int n;
int a[109];
vector<string> v;
string temp = "";
int countA = 0, countB = 0;

void Try(int k) {
    for (int i = 1; i <= 2; i++) {
        if (i == 1) {
            temp += "A ";
            countA += a[k];
        } else {
            temp += "B ";
            countB += a[k];
        }

        if (k == n) {
            if (countA == countB) {
                v.push_back(temp);
            }
        } else {
            Try(k + 1);
        }

        temp.erase(temp.size() - 2);
        if (i == 1) {
            countA -= a[k];
        } else {
            countB -= a[k];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Try(1);

    if (v.size() > 0) {      
        cout << v.size() << endl;                
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    } else {
        cout << "khong chia duoc";
    }
}