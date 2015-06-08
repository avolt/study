#include <stdio.h>

/* getInputNum - 입력값이 증가되는 count를 매개변수로 받고, 사용자의 입력값을 받아 Num 를 전달하는 함수 */
int getInputNum(int count)
{
	int someNum = 0; //인자로 받은 변수를 0으로 초기화함
	printf("%d번째 정수를 입력해 주세요 : ", count);  //  문구출력
	//scanf("%d", &firstNum);  - 버퍼 오버플로우 문제로 컴파일 오류가 발생되어 scanf 대신 scanf_s 함수를 사용함
	scanf_s("%d", &someNum);  // 사용자의 정수 입력 값을 받음

	printf("%d번째 입력한 정수는 %d 입니다.\n\n", count, someNum);  //  문구출력, 첫번째 정수 입력값

	return someNum; // 입력받은 정수값을 반환함
}

/* betweenAdd - 첫번째와 두번째 정수사이의 최종합을 계산하는 함수 */
int betweenAdd(int firstNum, int secondNum) 
{
	int total = 0;  // 최종 합의 변수 0으로 초기화함
	for (int i = firstNum; i <= secondNum; i++) // 첫번째 인자로 받은 정수가  두번째 인자로 받은 숫자까지 증감하는 반복문을 실행 
	{
		total += i; // 최종합에 계속 더해짐 
	}
	return total; // 최종 합의 변수를 반환함
}

/* compareAndResult - 첫 번째 정수(firstNum)와 두번째 정수(secondNum), 입력이 증가되는 수(count) 를 매개변수로 받고 *  
 *					  두 정수 사이의 크기를 비교하고, 올바른 값일시 betweenAdd 를 호출하여 최종 결과를 구하는 함수   */
void compareAndResult(int firstNum, int secondNum, int count)
{	
	if (secondNum <= firstNum) // 두번째 정수가 첫번째 정수보다 작거나 같을시
	{
		printf("info : 두 번째 정수가 첫 번째 정수보다 커야 함 \n"); // 문자 출력
		secondNum = getInputNum(secondNum, count);  // getInputNum 함수를 호출하여 두번째 정수의 재 입력값을 받음  
		compareAndResult(firstNum, secondNum, count); // compareAndResult 함수를 재귀호출하여 다시 검증
	}
	else // 두번째 정수가 첫번째 정수보다 클 경우 
	{
		printf("두 정수 사이의 최종 합은 %d 입니다.\n\n", betweenAdd(firstNum,  secondNum));  //  문구출력,  betweendAdd 함수를 실행하여 최종 반환 결과값을 출력 
	}
}

/* addService - 각 정수 값을 선언하고 각 함수를 실행하고 재 실행 여부를 결정하는 service 함수 */
void addService()
{
	// 입력을 받을 정수(firstNum , secondNum), 최종결과값 (total) 몇 번째 입력 숫자인지 (count), 재시작메뉴(userMenuSelect) 선언과 동시에 0 으로 초기화 함
	int firstNum = 0, secondNum = 0, count = 0; int userMenuSelect = 0;  
	
	count++;  // 카운트 값을 증가시킴 count = 1 (첫번째 정수)
	firstNum = getInputNum(count); // getInputNum 함수를 실행하여 사용자의 첫번째 정수 입력값을 받음

	count++; // 카운트 값을 증가시킴 count = 2 (두번째 정수)
	secondNum = getInputNum(count); // getInputNum 함수를 실행하여 사용자의 두번째 정수 입력값을 받음

	compareAndResult(firstNum, secondNum, count); // 각각 입력 받은 정수값(firstNum, secondNum)과 입력 횟수(count) 값으로 compareAndResult 함수를 실행시킴

	printf("다시 계산 하시겠습니까? \n(0을 입력하면 다시 계산, 중지하려면 아무 숫자를 입력하세요.) \n "); // 문자 출력
	printf("입력하세요 : ");  // 문자 출력
	//scanf("%d", &userMenuSelect);  - 버퍼 오버플로우 문제로 컴파일 오류가 발생되어 scanf 대신 scanf_s 함수를 사용함
	scanf_s("%d", &userMenuSelect); // 메뉴 입력값을 받음
	printf("\n"); // 문자 출력 

	if (userMenuSelect == 0) // userMenuSelect가 0 이면 
	{
		addService(); // addService 함수를 재귀 호출
	}
	else // 0이 아닌 숫자일 경우 
	{
		printf("프로그램을 중지합니다. \n "); // 프로그램을 중지시킴
		return 0; // 0을 반환함
	}
}

/* main - main 함수  */
int main()
{
	printf("두 개의 정수를 입력받아 두 정수를 포함하여 \n각 정수 사이의 입력 값을 더해주는 프로그램입니다. \n\n");  // 프로그램 설명문구 출력 
	addService(); // 계산하는 루틴이 순차적으로 호출하는 addService 함수를 실행함
	return 0; // 0을 반환함
}
