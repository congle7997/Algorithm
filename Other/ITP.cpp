#include <iostream>
using namespace std;

const int MAX = 1000;
char s[MAX];
int top = -1;

bool isFull() {
    return (top == MAX);
}
bool isEmpty() {
    return (top == -1);
}
void push(char c) {
    if (!isFull()) {
        s[++top] = c;
    }
}
char pop() {
    return s[top--];
}

bool isNumber(char c) {
    if (c >= 48 && c <= 57) {
        return true;
    }
    else {
        return false;
    }
}
bool isOperator(char c) {
    char a[4] = { '+', '-', '*', '/' };
    for (int i = 0; i < 4; i++) {
        if (a[i] == c) {
            return true;
        }
    }
    return false;
}
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    else if (c == '(') {
        return 3;
    }
    else if (c == ')') {
        return -1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a[4][4], b[4][4];
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int x = 0, y = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            b[j][i] = a[x][j];
        }
        x++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
