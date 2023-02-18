#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stack 프로토타입 정의
void main_push(int a);
int main_pop();
void sub_push(int a);
int sub_pop();
int stack_full(int top);
int stack_empty(int top);
//queue의 enqueue, dequeue 프로토 타입 정의
void enqueue(int data);
int dequeue();

// 스택의 전역 변수 선언
int main_stack_arr[10], main_top = -1;
int sub_stack_arr[10], sub_top = -1;

int main() { // 가상의 queue 역할을 하는 main 함수
	int num, type = 0;
	while (1) {
		printf("Enqueue : 1, Dequeue : 2 ");
		scanf("%d", &type);
		if (type == 1) {        //enqueue 함수 연산
			printf("Type your number : ");
			scanf("%d", &num);
			enqueue(num);
		}
		else if (type == 2) {   //dequeue 함수 연산
			printf("%d\n", dequeue());
		}
		else
			return 0;
		type = 0;
	}
}

void enqueue(int data) { // enqueue 함수
	while(stack_empty(main_top) == 0) { // 메인 스택이 빌 때까지 서브 스택으로 이동
		sub_push(main_pop());
	}
	main_push(data); 
	for (int i = 0; (i = sub_pop()) != -1;) { // 데이터 푸쉬 이후 서브 스택에 있던 데이터 메인으로 다시 이동
		main_push(i);
	}
}

int dequeue() { // dequeue 함수, main_pop호출
	return main_pop();
}

void main_push(int data) { // main 스택의 push 함수
	if (main_top == 9) {
		printf("Your stack is full\n");// 스택이 차있을 때 오류 메세지 출력
		return;
	}
	else {
		main_top++;
		main_stack_arr[main_top] = data;
		return;
	}
}

int main_pop() {
	int temp;
	if (stack_empty(main_top) == 0) { // 스택이 비어있지 않을 때, temp에 값 일시 저장후 출력
		temp = main_stack_arr[main_top]; 
		main_top--;
		return temp;
	}
	else {
		printf("Your stack is empty\n"); // 스택이 비어있을 때, 오류 메세지 출력
		return -1;
	}
}

void sub_push(int data) { // sub 스택의 push 함수
	if (sub_top == 9) {
		printf("Your stack is full\n");// 스택이 차있을 때 오류 메세지 출력
		return;
	}
	else {
		sub_top++;
		sub_stack_arr[sub_top] = data;
		return;
	}
}

int sub_pop() {
	int temp;
	if (stack_empty(sub_top) == 0) { // 스택이 비어있지 않을 때, temp에 값 일시 저장후 출력
		temp = sub_stack_arr[sub_top];
		sub_top--;
		return temp;
	}
	else {
		printf("Your stack is empty\n"); // 스택이 비어있을 때, 오류 메세지 출력
		return -1;
	}
}

int stack_full(int top) {
	if (top == 9) { // top이 9 일때 꽉찼다고 판단
		return 1;
	}
	else
		return 0;
}

int stack_empty(int top) {
	if (top == -1) // top이 -1 일 시 비었다고 판단
		return 1;
	else
		return 0;
}