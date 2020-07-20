#include <iostream>
using namespace std;

const int MAX = 1000;
int s[MAX];
int top = -1;

bool isFull() {
    return (top == MAX);
}
bool isEmpty() {
    return (top == -1);
}
void push(int x) {
    if (isFull()) {
        s[++top] = x;
    }
}
int pop() {
    return s[top--];
}

bool isNumber(char c) {
    if (c >= 48 && c <= 57) {
        return true;
    } else {
        return false;
    }
}
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    } else if (c == '(') {

    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a;
    cin >> a;
    cout << a + a;
}
