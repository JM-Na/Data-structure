#define _CRT_SECURE_NO_WARNINGS // scanf 출력 오류 수정
#include <stdio.h>
#define MAX 5 // array 의 길이 정의
#define True 1
#define False 0

int delete();
int insert(int num);
int buffer_full();
int buffer_empty();
// 함수의 프로토타입 선언

int array[MAX];
int front = 0, rear = 0;
// 배열 및  front, rear 전역 변수 선언

int main() {
	int selectMode, num; /* selectMode : 함수가 insert를 할지 delete를 할지 함수를 종료할지 확인하는 변수
						    num : insert를 통해 버퍼로 삽입될 수*/
	do {
		printf("Select your mode\n Delete is 0, insert is 1, end is 2 : ");
		scanf("%d", &selectMode);
		if (selectMode == 0) { // if else 문으로 main함수에서 실행할 함수 결정
			delete();
		}
		else if (selectMode == 1) {
			printf("\nType your number: ");
			scanf("%d", &num);
			insert(num);
		}
		else if (selectMode == 2) { // 함수 및 while 문 종료
			break;
		}
		else { // 에러 방지
			printf("Type appropriate number\n");
		}
		printf("Front is %d, Rear is %d\n\n", front, rear); // Front, Rear 함수가 1회 실행될 때마다 확인
	} while (1);

	return 0;
}


int delete() { // delete를 싱행할 함수
	if (buffer_empty() == True) return;
	else if (buffer_empty() == False) {
		printf("\nNumber %d has been deleted\n", array[front-1]); // delete 된 수 출력
		array[front-1] = NULL; // delete 된 자리에 NULL 입력
		if (front == rear) { // Front, Rear 값 조정 if else 문
			if (front == 5) { // Front, Rear가 같고 5일 때, 그 다음 버퍼로 넘기기 위해 Front, Rear를 1로 재정의 
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
	else if (buffer_full() == False) { // 버퍼가 full이 아닐 경우
		if (rear == 0) {// Rear가 0이면 첫 입력으로 판단하고 Front, Rear를 1로 정의
			front = 1;
			rear = 1;
		}
		else rear++;
		if (rear > 5) rear -= 5; // Rear가 5보다 커지면 안되므로 5보다 커질 시 1로 조정
		array[rear - 1] = num;
	}
}


int buffer_full() { // 버퍼가 꽉 찼는지 판단하는 함수
	if (rear == 5 && front == 1) return True;
	else if (front > rear && front-1 ==rear) return True;
	else return False;
}

int buffer_empty() { // 버퍼가 비었는지 확인하는 함수
	if (rear == front && array[front - 1] == NULL) {
		printf("\nDelete failed. Buffer is empty\n");
		return True;
	}
	else return False;
}