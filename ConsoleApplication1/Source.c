#include <stdio.h>

/* getInputNum - �Է°��� �����Ǵ� count�� �Ű������� �ް�, ������� �Է°��� �޾� Num �� �����ϴ� �Լ� */
int getInputNum(int count)
{
	int someNum = 0; //���ڷ� ���� ������ 0���� �ʱ�ȭ��
	printf("%d��° ������ �Է��� �ּ��� : ", count);  //  �������
	//scanf("%d", &firstNum);  - ���� �����÷ο� ������ ������ ������ �߻��Ǿ� scanf ��� scanf_s �Լ��� �����
	scanf_s("%d", &someNum);  // ������� ���� �Է� ���� ����

	printf("%d��° �Է��� ������ %d �Դϴ�.\n\n", count, someNum);  //  �������, ù��° ���� �Է°�

	return someNum; // �Է¹��� �������� ��ȯ��
}

/* betweenAdd - ù��°�� �ι�° ���������� �������� ����ϴ� �Լ� */
int betweenAdd(int firstNum, int secondNum) 
{
	int total = 0;  // ���� ���� ���� 0���� �ʱ�ȭ��
	for (int i = firstNum; i <= secondNum; i++) // ù��° ���ڷ� ���� ������  �ι�° ���ڷ� ���� ���ڱ��� �����ϴ� �ݺ����� ���� 
	{
		total += i; // �����տ� ��� ������ 
	}
	return total; // ���� ���� ������ ��ȯ��
}

/* compareAndResult - ù ��° ����(firstNum)�� �ι�° ����(secondNum), �Է��� �����Ǵ� ��(count) �� �Ű������� �ް� *  
 *					  �� ���� ������ ũ�⸦ ���ϰ�, �ùٸ� ���Ͻ� betweenAdd �� ȣ���Ͽ� ���� ����� ���ϴ� �Լ�   */
void compareAndResult(int firstNum, int secondNum, int count)
{	
	if (secondNum <= firstNum) // �ι�° ������ ù��° �������� �۰ų� ������
	{
		printf("info : �� ��° ������ ù ��° �������� Ŀ�� �� \n"); // ���� ���
		secondNum = getInputNum(secondNum, count);  // getInputNum �Լ��� ȣ���Ͽ� �ι�° ������ �� �Է°��� ����  
		compareAndResult(firstNum, secondNum, count); // compareAndResult �Լ��� ���ȣ���Ͽ� �ٽ� ����
	}
	else // �ι�° ������ ù��° �������� Ŭ ��� 
	{
		printf("�� ���� ������ ���� ���� %d �Դϴ�.\n\n", betweenAdd(firstNum,  secondNum));  //  �������,  betweendAdd �Լ��� �����Ͽ� ���� ��ȯ ������� ��� 
	}
}

/* addService - �� ���� ���� �����ϰ� �� �Լ��� �����ϰ� �� ���� ���θ� �����ϴ� service �Լ� */
void addService()
{
	// �Է��� ���� ����(firstNum , secondNum), ��������� (total) �� ��° �Է� �������� (count), ����۸޴�(userMenuSelect) ����� ���ÿ� 0 ���� �ʱ�ȭ ��
	int firstNum = 0, secondNum = 0, count = 0; int userMenuSelect = 0;  
	
	count++;  // ī��Ʈ ���� ������Ŵ count = 1 (ù��° ����)
	firstNum = getInputNum(count); // getInputNum �Լ��� �����Ͽ� ������� ù��° ���� �Է°��� ����

	count++; // ī��Ʈ ���� ������Ŵ count = 2 (�ι�° ����)
	secondNum = getInputNum(count); // getInputNum �Լ��� �����Ͽ� ������� �ι�° ���� �Է°��� ����

	compareAndResult(firstNum, secondNum, count); // ���� �Է� ���� ������(firstNum, secondNum)�� �Է� Ƚ��(count) ������ compareAndResult �Լ��� �����Ŵ

	printf("�ٽ� ��� �Ͻðڽ��ϱ�? \n(0�� �Է��ϸ� �ٽ� ���, �����Ϸ��� �ƹ� ���ڸ� �Է��ϼ���.) \n "); // ���� ���
	printf("�Է��ϼ��� : ");  // ���� ���
	//scanf("%d", &userMenuSelect);  - ���� �����÷ο� ������ ������ ������ �߻��Ǿ� scanf ��� scanf_s �Լ��� �����
	scanf_s("%d", &userMenuSelect); // �޴� �Է°��� ����
	printf("\n"); // ���� ��� 

	if (userMenuSelect == 0) // userMenuSelect�� 0 �̸� 
	{
		addService(); // addService �Լ��� ��� ȣ��
	}
	else // 0�� �ƴ� ������ ��� 
	{
		printf("���α׷��� �����մϴ�. \n "); // ���α׷��� ������Ŵ
		return 0; // 0�� ��ȯ��
	}
}

/* main - main �Լ�  */
int main()
{
	printf("�� ���� ������ �Է¹޾� �� ������ �����Ͽ� \n�� ���� ������ �Է� ���� �����ִ� ���α׷��Դϴ�. \n\n");  // ���α׷� ������ ��� 
	addService(); // ����ϴ� ��ƾ�� ���������� ȣ���ϴ� addService �Լ��� ������
	return 0; // 0�� ��ȯ��
}
