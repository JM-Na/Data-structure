#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stack
void push(int data); // �Լ� ������Ÿ�� ����
int pop();
// queue
void main_enqueue(int data);
int main_dequeue();
void sub_enqueue(int data);
int sub_dequeue(); 
int queue_full(int array[]);
int queue_empty(int front, int rear, int array[]);

int main_queue_arr[10] , main_front = 0, main_rear = 0; // ť�� �迭, front, rear �������� ����
int sub_queue_arr[10], sub_front = 0, sub_rear = 0;

int main() {
	int num, type = 0;
	while (1) {
		printf("\nPush is 1, Pop is 2 : ");
		scanf("%d", &type);
		if (type == 1) {        //push �Լ� ����
			printf("Type your number : ");
			scanf("%d", &num);
			push(num);
		}
		else if (type == 2) {   //pop �Լ� ����
			printf("%d is popped\n", pop());
		}
		else
			return 0;
		type = 0;
	}
}
void push(int data) {
	while(queue_empty(main_front, main_rear, main_queue_arr) == 0) { // ť�� ��� �� ������, main_dequeu�� sub_enqueue �ݺ� ����
		sub_enqueue(main_dequeue());
	}
	main_enqueue(data); // data �� �Է�
	for (int i = 0; (i = sub_dequeue()) != -1;) { // ���꿡 �� ���� �������� �ٽ� enqueue
		main_enqueue(i);
	}
}
int pop() {
	return main_dequeue(); // pop�Լ����� main_dequeue�� ȣ��
}

void main_enqueue(int data) {
	if (main_rear == 9) {
		printf("Your main queue is full\n");// ������ ��, ������ �Ǵ�
		return;
	}
	else {
		if (queue_empty(main_front, main_rear, main_queue_arr) == 1) {// ť�� ������ ���� ��, ť�� ����ִ� ���� �ƴ� ���� ���� ����
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
		printf("Your main queue is empty.\n");// ������� ��, ������ �Ǵ�
		return -1;
	}
	else {
		if (main_front < main_rear) {// ť�� ������� ���� ��, front�� rear�� ���� ���� ����
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
		printf("Your sub queue is full\n");// ������ ��, ������ �Ǵ�
		return;
	}
	else {
		if (queue_empty(sub_front, sub_rear, sub_queue_arr) == 0) { // ť�� ������ ���� ��, ť�� ����ִ� ���� �ƴ� ���� ���� ����
			sub_rear++;
			sub_queue_arr[sub_rear] = data;
		}
		else {
			sub_queue_arr[sub_rear] = data;
		}
		return;
	}
}

int sub_dequeue() { //���� ť�� dequeue �Լ�
	int temp;
	if (queue_empty(sub_front, sub_rear, sub_queue_arr) == 1) { // ������� ��, ������ �Ǵ�
		printf("Your sub queue is empty.\n");
		return -1;
	}
	else {
		if (sub_front < sub_rear) { // ť�� ������� ���� ��, front�� rear�� ���� ���� ����
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

int queue_full(int array[]) { // ť�� ���ִ��� �Ǵ��ϴ� �ڵ�
	if (main_rear == 9 && array[main_rear] != NULL) return 1; // main�� rear�� 9�̰� ���ڸ� NULL�� �ƴ� ��, ť�� �� ���ִٰ� �Ǵ� 
	else return 0; 
}

int queue_empty(int front, int rear, int array[]) { // ť�� ������� �����ϴ� �ڵ�
	if (front == rear && array[front] == NULL) return 1;// front�� near�� �����ϰ� �� �ڸ��� ������� �� ť�� ����ٰ� �Ǵ�
	else return 0;
}