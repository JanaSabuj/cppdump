#include <iostream>
using namespace std;

#define N 20
int q[N];
int front = -1;
int rear = -1;

bool empty() {
	return (front == -1 and rear == -1);
}

bool full() {
	return rear == N - 1;
}

void enq(int x) {
	if (full())
		return;
	else if (empty()) {
		front = rear = 0;
		q[rear] = x;
	} else {
		rear++;
		q[rear] = x;
	}
}

void deq() {
	if (empty())
		return;
	else if (front == rear) {
		front = rear = -1;
	} else {
		front++;
	}
}

int peek() {
	if (empty())
		return -1;
	else
		return q[front];
}

int main() {
	enq(12);
	enq(5);
	enq(7);
	deq();
	deq();
	deq();
	int x = peek();
	cout << x << endl;
	return 0;
}
