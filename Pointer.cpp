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
	포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만 포인터
	변수는 메모리 주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을
	선언할 수 있다. int변수의 주소는 int 포인터 변수에 저장을 해야한다.
	포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할때는
	무조건 4byte가 나온다. x64일때는 8byte가 나온다.

	포인터는 자기 스스로 아무런 일도 할 수 없다. 반드시 다른 변수의 메모리
	주소를 가지고 있어야 일을 할 수 있는데 가지고 있는 그 메모리 주소에
	접근해서 값을 제어할 수 있다.

	형태 : 변수타입 *변수명; 의 형태로 선언한다.
	*/

	int iNumber = 100;
	// 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
	int *pNum = &iNumber;

	std::cout << sizeof(int*) << std::endl;
	std::cout << sizeof(char*) << std::endl;
	std::cout << sizeof(double*) << std::endl;

	// pNum을 이용해서 iNumber의 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
	*pNum = 1234;

	std::cout << "iNumber Value : " << iNumber << std::endl;
	std::cout << "iNumber Address : " << &iNumber << std::endl;
	std::cout << "pNum Value : " << pNum << std::endl;
	std::cout << "pNum Address : " << &pNum << std::endl;

	/*
	포인터와 배열의 관계 : 배열명은 포인터다.(암기 중요!)
	배열명 자체가 해당 배열의 메모리에서의 시작점 주소를 의미한다.
	*/
	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::cout << "Array Address : " << iArray << std::endl;
	std::cout << "Array Address : " << &iArray[0] << std::endl;

	int* pArray = iArray;

	std::cout << pArray[2] << std::endl;
	// iArray가 맨 앞부분에 배열 시작 주소를 가지고 있는데,
	// pArray 포인터에 iArray 배열의 시작 주소를 넣어 주었기에,
	// pArray 포인터로 배열을 제어 할 수 있다.

	/*
	포인터 연산 : +, - 연산을 제공한다. ++, --도 가능한데 1을
	증가하게되면 단순히 메모리 주소값이 1 증가 하는 것이 아니다.
	int 포인터의 경우 int 타입의 메모리 주소를 갖게 되는데 메모리
	주소에 1을 더해주면 1 증가가 아닌 해당 포인터 타입의 변수 타입
	크기만큼 증가하게 된다. int 포인터이므로 int의 크기인 4만큼
	값이 증가하게 되는 것이다.
	*/

	std::cout << pArray << std::endl;
	std::cout << pArray + 2 << std::endl;
	std::cout << *pArray << std::endl;
	std::cout << *(pArray + 2) << std::endl;
	std::cout << *pArray + 100 << std::endl;
	// 연산자 우선순위로 인해 *pArray는 1이고, + 100 이므로
	// 결과가 101이 나온다.

	char *pText = "테스트 문자열";
	// 이런식으로 선언하면 바꾸지 않는 문자열을 선언하는 것이다.

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;

	pText = "abcd";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;

	pText = "abcd";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;
	// 저장되는 문자열이 같으면 같은 메모리 공간이 잡힌다.

	pText = "abcdefg";

	std::cout << pText << std::endl;
	std::cout << (int*)pText << std::endl;
	// 저장되는 문자열이 다르면 다른 메모리 공간에 잡힌다.

	char str[8] = "abcdefg";

	std::cout << str << std::endl;
	std::cout << (int*)str << std::endl;
	std::cout << (int*)&str[0] << std::endl;
	std::cout << &str << std::endl;

	// 구조체 포인터
	_tagStudent tStudent = { };

	tStudent.iKor = 100;

	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위 때문에 .을 먼저 인식하게 된다.
	// 메모리주소.은 잘못된 문법이다. 그러므로 *pStudent를 괄호로
	// 감싸준 후에 .을 이용해서 가리키는 대상의 멤버변수에 접근해야
	// 한다.
	(*pStudent).iKor = 50;
	std::cout << tStudent.iKor << std::endl;

	// 위 아래는 같은 표현이다. (->를 많이 사용한다.)
	
	// 메모리주소->을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
	pStudent->iKor = 80;

	std::cout << tStudent.iKor << std::endl;

	// void : "타입이 없다"를 의미한다.
	// void의 포인터 타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든
	// 모두 저장가능하다. 단, 역참조(값 변경)가 불가능하고 메모리 주소만 저장
	// 가능하다. 메모리 주소만 저장 가능한 버퍼로 쓰일 수 있다.
	void* pVoid = &iNumber;

	std::cout << "iNumber Address : " << pVoid << std::endl;
	// *pVoid = 10;
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;

	std::cout << iNumber << std::endl;

	// int* 타입으로 형 변환한 pVoid 포인터에 1234 대입하면 iNumber의 값
	// 역시 바뀐다.
	*((int*)pVoid) = 1234;

	std::cout << iNumber << std::endl;

	pVoid = &tStudent;

	std::cout << "tStudent Address : " << pVoid << std::endl;

	int iNumber1 = 1111;
	iNumber1 = 2222;
	pNum = &iNumber;

	// 이중 포인터 : *을 2개 붙인다. 일반 포인터 변수가 일반 변수의 메모리
	// 주소를 저장하는	변수라면 이중포인터는 포인터의 포인터이다. 즉, 이중
	// 포인터는 포인터 변수의 메모리 주소를 저장하는 포인터이다.
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