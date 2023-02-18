#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stack ������Ÿ�� ����
void main_push(int a);
int main_pop();
void sub_push(int a);
int sub_pop();
int stack_full(int top);
int stack_empty(int top);
//queue�� enqueue, dequeue ������ Ÿ�� ����
void enqueue(int data);
int dequeue();

// ������ ���� ���� ����
int main_stack_arr[10], main_top = -1;
int sub_stack_arr[10], sub_top = -1;

int main() { // ������ queue ������ �ϴ� main �Լ�
	int num, type = 0;
	while (1) {
		printf("Enqueue : 1, Dequeue : 2 ");
		scanf("%d", &type);
		if (type == 1) {        //enqueue �Լ� ����
			printf("Type your number : ");
			scanf("%d", &num);
			enqueue(num);
		}
		else if (type == 2) {   //dequeue �Լ� ����
			printf("%d\n", dequeue());
		}
		else
			return 0;
		type = 0;
	}
}

void enqueue(int data) { // enqueue �Լ�
	while(stack_empty(main_top) == 0) { // ���� ������ �� ������ ���� �������� �̵�
		sub_push(main_pop());
	}
	main_push(data); 
	for (int i = 0; (i = sub_pop()) != -1;) { // ������ Ǫ�� ���� ���� ���ÿ� �ִ� ������ �������� �ٽ� �̵�
		main_push(i);
	}
}

int dequeue() { // dequeue �Լ�, main_popȣ��
	return main_pop();
}

void main_push(int data) { // main ������ push �Լ�
	if (main_top == 9) {
		printf("Your stack is full\n");// ������ ������ �� ���� �޼��� ���
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
	if (stack_empty(main_top) == 0) { // ������ ������� ���� ��, temp�� �� �Ͻ� ������ ���
		temp = main_stack_arr[main_top]; 
		main_top--;
		return temp;
	}
	else {
		printf("Your stack is empty\n"); // ������ ������� ��, ���� �޼��� ���
		return -1;
	}
}

void sub_push(int data) { // sub ������ push �Լ�
	if (sub_top == 9) {
		printf("Your stack is full\n");// ������ ������ �� ���� �޼��� ���
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
	if (stack_empty(sub_top) == 0) { // ������ ������� ���� ��, temp�� �� �Ͻ� ������ ���
		temp = sub_stack_arr[sub_top];
		sub_top--;
		return temp;
	}
	else {
		printf("Your stack is empty\n"); // ������ ������� ��, ���� �޼��� ���
		return -1;
	}
}

int stack_full(int top) {
	if (top == 9) { // top�� 9 �϶� ��á�ٰ� �Ǵ�
		return 1;
	}
	else
		return 0;
}

int stack_empty(int top) {
	if (top == -1) // top�� -1 �� �� ����ٰ� �Ǵ�
		return 1;
	else
		return 0;
}