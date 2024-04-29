#include <iostream>

struct _tagStudent {
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {
	/*
	������ : ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������
	������ �޸� �ּҸ� �����ϰ� �ȴ�. ��� ���� Ÿ���� ������ Ÿ����
	������ �� �ִ�. int������ �ּҴ� int ������ ������ ������ �ؾ��Ѵ�.
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� �����Ҷ���
	������ 4byte�� ���´�. x64�϶��� 8byte�� ���´�.

	�����ʹ� �ڱ� ������ �ƹ��� �ϵ� �� �� ����. �ݵ�� �ٸ� ������ �޸�
	�ּҸ� ������ �־�� ���� �� �� �ִµ� ������ �ִ� �� �޸� �ּҿ�
	�����ؼ� ���� ������ �� �ִ�.

	���� : ����Ÿ�� *������; �� ���·� �����Ѵ�.
	*/

	int iNumber = 100;
	// ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.
	int *pNum = &iNumber;

	std::cout << sizeof(int*) << std::endl;
	std::cout << sizeof(char*) << std::endl;
	std::cout << sizeof(double*) << std::endl;

	// pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
	// �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
	// �������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
	*pNum = 1234;

	std::cout << "iNumber Value : " << iNumber << std::endl;
	std::cout << "iNumber Address : " << &iNumber << std::endl;
	std::cout << "pNum Value : " << pNum << std::endl;
	std::cout << "pNum Address : " << &pNum << std::endl;

	/*
	�����Ϳ� �迭�� ���� : �迭���� �����ʹ�.(�ϱ� �߿�!)
	�迭�� ��ü�� �ش� �迭�� �޸𸮿����� ������ �ּҸ� �ǹ��Ѵ�.
	*/
	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << "Array Address : " << iArray << std::endl;
	std::cout << "Array Address : " << &iArray[0] << std::endl;

	int* pArray = iArray;

	std::cout << pArray[2] << std::endl;
	// iArray�� �� �պκп� �迭 ���� �ּҸ� ������ �ִµ�,
	// pArray �����Ϳ� iArray �迭�� ���� �ּҸ� �־� �־��⿡,
	// pArray �����ͷ� �迭�� ���� �� �� �ִ�.

	/*
	������ ���� : +, - ������ �����Ѵ�. ++, --�� �����ѵ� 1��
	�����ϰԵǸ� �ܼ��� �޸� �ּҰ��� 1 ���� �ϴ� ���� �ƴϴ�.
	int �������� ��� int Ÿ���� �޸� �ּҸ� ���� �Ǵµ� �޸�
	�ּҿ� 1�� �����ָ� 1 ������ �ƴ� �ش� ������ Ÿ���� ���� Ÿ��
	ũ�⸸ŭ �����ϰ� �ȴ�. int �������̹Ƿ� int�� ũ���� 4��ŭ
	���� �����ϰ� �Ǵ� ���̴�.
	*/

	std::cout << pArray << std::endl;
	std::cout << pArray + 2 << std::endl;
	std::cout << *pArray << std::endl;
	std::cout << *(pArray + 2) << std::endl;
	std::cout << *pArray + 100 << std::endl;
	// ������ �켱������ ���� *pArray�� 1�̰�, + 100 �̹Ƿ�
	// ����� 101�� ���´�.

	char *pText = "�׽�Ʈ ���ڿ�";
	// �̷������� �����ϸ� �ٲ��� �ʴ� ���ڿ��� �����ϴ� ���̴�.

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;

	pText = "abcd";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;

	pText = "abcd";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;
	// ����Ǵ� ���ڿ��� ������ ���� �޸� ������ ������.

	pText = "abcdefg";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;
	// ����Ǵ� ���ڿ��� �ٸ��� �ٸ� �޸� ������ ������.

	char str[8] = "abcdefg";

	std::cout << str << std::endl;
	std::cout << (int*)str << std::endl;
	std::cout << (int*)&str[0] << std::endl;
	std::cout << &str << std::endl;

	// ����ü ������
	_tagStudent tStudent = { };

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// ������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�.
	// �޸��ּ�.�� �߸��� �����̴�. �׷��Ƿ� *pStudent�� ��ȣ��
	// ������ �Ŀ� .�� �̿��ؼ� ����Ű�� ����� ��������� �����ؾ�
	// �Ѵ�.
	(*pStudent).iKor = 50;
	std::cout << tStudent.iKor << std::endl;

	// �� �Ʒ��� ���� ǥ���̴�. (->�� ���� ����Ѵ�.)
	
	// �޸��ּ�->�� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
	pStudent->iKor = 80;

	std::cout << tStudent.iKor << std::endl;

	// void : "Ÿ���� ����"�� �ǹ��Ѵ�.
	// void�� ������ Ÿ���� Ȱ���� �� �ִ�.
	// void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ�
	// ��� ���尡���ϴ�. ��, ������(�� ����)�� �Ұ����ϰ� �޸� �ּҸ� ����
	// �����ϴ�. �޸� �ּҸ� ���� ������ ���۷� ���� �� �ִ�.
	void* pVoid = &iNumber;

	std::cout << "iNumber Address : " << pVoid << std::endl;
	// *pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;

	std::cout << iNumber << std::endl;

	// int* Ÿ������ �� ��ȯ�� pVoid �����Ϳ� 1234 �����ϸ� iNumber�� ��
	// ���� �ٲ��.
	*((int*)pVoid) = 1234;

	std::cout << iNumber << std::endl;

	pVoid = &tStudent;

	std::cout << "tStudent Address : " << pVoid << std::endl;

	int iNumber1 = 1111;
	iNumber1 = 2222;
	pNum = &iNumber;

	// ���� ������ : *�� 2�� ���δ�. �Ϲ� ������ ������ �Ϲ� ������ �޸�
	// �ּҸ� �����ϴ�	������� ���������ʹ� �������� �������̴�. ��, ����
	// �����ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.
	int** ppNum = &pNum;

	*ppNum = &iNumber1;
	*pNum = 3333;

	std::cout << "iNumber1 : " << iNumber1 << std::endl;
	std::cout << "iNumber : " << iNumber << std::endl;
	std::cout << "iNumber Addr : " << &iNumber << std::endl;
	std::cout << "*pNum : " << *pNum << std::endl;
	std::cout << "pNum Value : " << pNum << std::endl;
	std::cout << "pNum Addr : " << &pNum << std::endl;
	std::cout << "*ppNum : " << *ppNum << std::endl;
	std::cout << "**ppNum : " << **ppNum << std::endl;
	std::cout << "ppNum Value : " << ppNum << std::endl;
	std::cout << "ppNum Addr : " << &ppNum << std::endl;

}