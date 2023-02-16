#define _CRT_SECURE_NO_WARNINGS // scanf ��� ���� ����
#include <stdio.h>
#define MAX 5 // array �� ���� ����
#define True 1
#define False 0

int delete();
int insert(int num);
int buffer_full();
int buffer_empty();
// �Լ��� ������Ÿ�� ����

int array[MAX];
int front = 0, rear = 0;
// �迭 ��  front, rear ���� ���� ����

int main() {
	int selectMode, num; /* selectMode : �Լ��� insert�� ���� delete�� ���� �Լ��� �������� Ȯ���ϴ� ����
						    num : insert�� ���� ���۷� ���Ե� ��*/
	do {
		printf("Select your mode\n Delete is 0, insert is 1, end is 2 : ");
		scanf("%d", &selectMode);
		if (selectMode == 0) { // if else ������ main�Լ����� ������ �Լ� ����
			delete();
		}
		else if (selectMode == 1) {
			printf("\nType your number: ");
			scanf("%d", &num);
			insert(num);
		}
		else if (selectMode == 2) { // �Լ� �� while �� ����
			break;
		}
		else { // ���� ����
			printf("Type appropriate number\n");
		}
		printf("Front is %d, Rear is %d\n\n", front, rear); // Front, Rear �Լ��� 1ȸ ����� ������ Ȯ��
	} while (1);

	return 0;
}


int delete() { // delete�� ������ �Լ�
	if (buffer_empty() == True) return;
	else if (buffer_empty() == False) {
		printf("\nNumber %d has been deleted\n", array[front-1]); // delete �� �� ���
		array[front-1] = NULL; // delete �� �ڸ��� NULL �Է�
		if (front == rear) { // Front, Rear �� ���� if else ��
			if (front == 5) { // Front, Rear�� ���� 5�� ��, �� ���� ���۷� �ѱ�� ���� Front, Rear�� 1�� ������ 
				front = 1;
				rear = 1;
			}
			else
			{
				front++;
				rear++;
			}
		}
		else 
			front++;
	}
}

int insert(int num) {
	if (buffer_full() == True) {
		printf("\nAs Front = Rear + 1, so overflow\n");
	}
	else if (buffer_full() == False) { // ���۰� full�� �ƴ� ���
		if (rear == 0) {// Rear�� 0�̸� ù �Է����� �Ǵ��ϰ� Front, Rear�� 1�� ����
			front = 1;
			rear = 1;
		}
		else rear++;
		if (rear > 5) rear -= 5; // Rear�� 5���� Ŀ���� �ȵǹǷ� 5���� Ŀ�� �� 1�� ����
		array[rear - 1] = num;
	}
}


int buffer_full() { // ���۰� �� á���� �Ǵ��ϴ� �Լ�
	if (rear == 5 && front == 1) return True;
	else if (front > rear && front-1 ==rear) return True;
	else return False;
}

int buffer_empty() { // ���۰� ������� Ȯ���ϴ� �Լ�
	if (rear == front && array[front - 1] == NULL) {
		printf("\nDelete failed. Buffer is empty\n");
		return True;
	}
	else return False;
}