/*���α׷��� : 2022-1 �����Ϸ� ���� 1
* �ۼ��� : 2020039096 ������
* ���� �ۼ� �Ϸ��� : 2022.03.28
*/

#include<stdio.h>//ǥ�� ����� �Լ��� ������ �ִ� <stdio.h> �������
#include<stdlib.h>//����ȯ�� ���� �������� ������ �ִ� <stlib.h> �������

char lookahead;//�ܼ�â�� �Է��� ���ڿ��� ���ڸ� �ϳ��� �޾ƿ� �����ϴ� ���� lookahead

//error ������ ����ϰ� 1�� ��ȯ�ϰ� �����Ų��
void error() {
	printf("error\n");
	exit(1);
}

char nexttoken() {
	char c;
	while (1) {
		c = getchar();//���� �޾ƿͼ� ����
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			continue;//���� ���ڰ� ��Ģ���꿡 �ش����� �ʰų� $�� �ƴϸ� �ٽ� �޾ƿ´�
		return(c);//c�� ��ȯ�Ѵ�
	}
}

void match(char token) {
	//��ū�� ��ġ�ϸ� ���� ���ڸ� �޾ƿ´�
	if (lookahead == token)
		lookahead = nexttoken();
	//���� ������ ������ ����ϰ� �����Ų��.
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
* rest1 -> + term rest1 || rest1 -> - term rest1 || ��
*/

//expr -> term rest1
expr() {
	term(); putchar('3');
	rest1();
}

//rest1 -> + term rest1 || - term rest1 || ��
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

	//��
	else;
}

/*term -> term * factor
* term -> term / factor
* term -> factor
* 
* =>
* 
* term -> factor rest2
* rest2 -> * factor rest2 || / factor rest2 || ��
*/

//term -> factor rest2
term() {
	factor();
	rest2();
}

//rest2 -> * factor rest2 || / factor rest2 || ��
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
	//��
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

//�����Լ�
void main() {
	lookahead = nexttoken();//lookahead�� ���ڿ��� �������� �ִ� ���ڸ� �޾ƿ� �����Ѵ�
	expr();//expr() ����

	//lookahead�� $�� ����Ǹ� ���� ��� 0�� ��ȯ�ϸ鼭 ����
	if (lookahead == '$') {
		printf("\n");
		exit(0);
	}
	//�ƴ� ��� error ���
	else
		error();
}