/*프로그램명 : 2022-1 컴파일러 과제 1
* 작성자 : 2020039096 백인혁
* 최초 작성 완료일 : 2022.03.28
*/

#include<stdio.h>//표준 입출력 함수를 가지고 있는 <stdio.h> 헤더파일
#include<stdlib.h>//실행환경 관련 변수들을 가지고 있는 <stlib.h> 헤더파일

char lookahead;//콘솔창에 입력한 문자열의 문자를 하나씩 받아와 저장하는 변수 lookahead

//error 구문을 출력하고 1을 반환하고 종료시킨다
void error() {
	printf("error\n");
	exit(1);
}

char nexttoken() {
	char c;
	while (1) {
		c = getchar();//문자 받아와서 저장
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			continue;//받은 문자가 사칙연산에 해당하지 않거나 $이 아니면 다시 받아온다
		return(c);//c를 반환한다
	}
}

void match(char token) {
	//토큰이 일치하면 다음 문자를 받아온다
	if (lookahead == token)
		lookahead = nexttoken();
	//같지 않으면 에러를 출력하고 종료시킨다.
	else {
		error();
	}
}

/*expr -> expr + term
* expr -> expr - term
* expr -> term
* 
* =>
* 
* expr -> term rest1
* rest1 -> + term rest1 || rest1 -> - term rest1 || ε
*/

//expr -> term rest1
expr() {
	term(); putchar('3');
	rest1();
}

//rest1 -> + term rest1 || - term rest1 || ε
rest1() {
	//rest1 -> + term rest1 
	if (lookahead == '+') {
		match('+'); term(); // + term
		putchar('1'); //putchar('+'); 
		rest1();//rest1
	}

	//rest1 -> - term rest1
	else if (lookahead == '-') {
		match('-'); term(); // - term
		putchar('2'); //putchar('-');
		rest1();
	}

	//ε
	else;
}

/*term -> term * factor
* term -> term / factor
* term -> factor
* 
* =>
* 
* term -> factor rest2
* rest2 -> * factor rest2 || / factor rest2 || ε
*/

//term -> factor rest2
term() {
	factor();
	rest2();
}

//rest2 -> * factor rest2 || / factor rest2 || ε
rest2() {
	//rest2 -> * factor rest2
	if (lookahead == '*') {
		match('*'); factor();// * factor
		putchar('4'); //putchar('*');
		rest2();// rest2
	}

	//rest2 -> / factor rest2
	else if (lookahead == '/') {
		match('/'); factor();// / factor
		putchar('5');//putchar('/');
		rest2();// rest2
	}
	//ε
	else;
}

//factor -> 0 ~ 9 || ( expr )
factor() {

	//factor -> 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9
	if (lookahead == '0' || lookahead == '1' || lookahead == '2' || lookahead == '3' || lookahead == '4' || 
		lookahead == '5' || lookahead == '6' || lookahead == '7' || lookahead == '8' || lookahead == '9') {
		putchar('6');//putchar(lookahead);
		match(lookahead);
	}

	//factor -> ( expr )
	else if (lookahead == '(') {
		match('(');
		expr();
		if (lookahead == ')') {
			match(')');
		}
		putchar('7'); //putchar('('); //putchar(')');
	}
	else
		error();
}

//메인함수
void main() {
	lookahead = nexttoken();//lookahead에 문자열의 시작점에 있는 문자를 받아와 저장한다
	expr();//expr() 수행

	//lookahead에 $가 저장되면 한줄 띄고 0을 반환하면서 종료
	if (lookahead == '$') {
		printf("\n");
		exit(0);
	}
	//아닐 경우 error 출력
	else
		error();
}