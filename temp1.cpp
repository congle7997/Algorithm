#include <iostream>
using namespace std;

const int MAX = 1000;
int q[MAX];
int front = 0, rear = -1;

bool isEmpty() {
	return front > rear;
}

bool isFull() {
	return rear == MAX;
}

void push(int x) {
	q[++rear] = x;
}

int pop() {
	int x = q[front];
	for (int i = front; i < rear; i++) {
		q[i] = q[i + 1];
	}
	rear--;
	return x;
}

int main() {
	freopen("input.txt", "r", stdin);

	push(1);
	push(2);
	push(3);
	pop();

	while (!isEmpty()) {
		cout << pop() << " ";
	}
}