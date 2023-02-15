#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stack
void push(int data); // 함수 프로토타입 선언
int pop();
// queue
void main_enqueue(int data);
int main_dequeue();
void sub_enqueue(int data);
int sub_dequeue(); 
int queue_full(int array[]);
int queue_empty(int front, int rear, int array[]);

int main_queue_arr[10] , main_front = 0, main_rear = 0; // 큐의 배열, front, rear 전역변수 선언
int sub_queue_arr[10], sub_front = 0, sub_rear = 0;

int main() {
	int num, type = 0;
	while (1) {
		printf("\nPush is 1, Pop is 2 : ");
		scanf("%d", &type);
		if (type == 1) {        //push 함수 연산
			printf("Type your number : ");
			scanf("%d", &num);
			push(num);
		}
		else if (type == 2) {   //pop 함수 연산
			printf("%d is popped\n", pop());
		}
		else
			return 0;
		type = 0;
	}
}
void push(int data) {
	while(queue_empty(main_front, main_rear, main_queue_arr) == 0) { // 큐가 비게 될 때까지, main_dequeu를 sub_enqueue 반복 연산
		sub_enqueue(main_dequeue());
	}
	main_enqueue(data); // data 값 입력
	for (int i = 0; (i = sub_dequeue()) != -1;) { // 서브에 들어간 값을 메인으로 다시 enqueue
		main_enqueue(i);
	}
}
int pop() {
	return main_dequeue(); // pop함수에서 main_dequeue를 호출
}

void main_enqueue(int data) {
	if (main_rear == 9) {
		printf("Your main queue is full\n");// 차있을 때, 오류로 판단
		return;
	}
	else {
		if (queue_empty(main_front, main_rear, main_queue_arr) == 1) {// 큐가 차있지 않을 때, 큐가 비어있는 경우와 아닌 경우로 나눠 연산
			main_queue_arr[main_rear] = data;
		}
		else {
			main_rear++;
			main_queue_arr[main_rear] = data;
		}
		return;
	}
}

int main_dequeue() {
	int temp;
	if (queue_empty(main_front, main_rear, main_queue_arr) == 1) {
		printf("Your main queue is empty.\n");// 비어있을 때, 오류로 판단
		return -1;
	}
	else {
		if (main_front < main_rear) {// 큐가 비어있지 않을 때, front와 rear의 값에 따라 연산
			temp = main_queue_arr[main_front];
			main_queue_arr[main_front] = NULL;
			main_front++;
			return temp;
		}
		else if (main_front == main_rear) {
			temp = main_queue_arr[main_front];
			main_queue_arr[main_front] = NULL;
			return temp;
		}
	}
}

void sub_enqueue(int data) {
	if (sub_rear == 9) {
		printf("Your sub queue is full\n");// 차있을 때, 오류로 판단
		return;
	}
	else {
		if (queue_empty(sub_front, sub_rear, sub_queue_arr) == 0) { // 큐가 차있지 않을 때, 큐가 비어있는 경우와 아닌 경우로 나눠 연산
			sub_rear++;
			sub_queue_arr[sub_rear] = data;
		}
		else {
			sub_queue_arr[sub_rear] = data;
		}
		return;
	}
}

int sub_dequeue() { //서브 큐의 dequeue 함수
	int temp;
	if (queue_empty(sub_front, sub_rear, sub_queue_arr) == 1) { // 비어있을 때, 오류로 판단
		printf("Your sub queue is empty.\n");
		return -1;
	}
	else {
		if (sub_front < sub_rear) { // 큐가 비어있지 않을 때, front와 rear의 값에 따라 연산
			temp = sub_queue_arr[sub_front];
			sub_queue_arr[sub_front] = NULL;
			sub_front++;
			return temp;
		}
		else if (sub_front == sub_rear) {
			temp = sub_queue_arr[sub_front];
			sub_queue_arr[sub_front] = NULL;
			return temp;
		}
	}
}

int queue_full(int array[]) { // 큐가 차있는지 판단하는 코드
	if (main_rear == 9 && array[main_rear] != NULL) return 1; // main의 rear가 9이고 그자리 NULL이 아닐 때, 큐가 꽉 차있다고 판단 
	else return 0; 
}

int queue_empty(int front, int rear, int array[]) { // 큐가 비었는지 점검하는 코드
	if (front == rear && array[front] == NULL) return 1;// front와 near가 동일하고 그 자리가 비어있을 때 큐가 비었다고 판단
	else return 0;
}