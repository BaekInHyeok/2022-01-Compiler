/*���α׷��� : 2022-1 �����Ϸ� ���� 2
* �ۼ��� : 2020039096 ������
* ���� �ۼ� �Ϸ��� : 2022.04.09
* 1�� ���� : 2022.04.11
* Ư�̻��� : ���ڿ� ���� $�� �Է��Ͽ� ���ڿ��� �������� �˸���. ex) for -> for$, int123 -> int123$
*/
#include<stdio.h>//ǥ�� ����� �Լ��� ������ �ִ� <stdio.h> �������
#include<stdlib.h>//����ȯ�� ���� �������� ������ �ִ� <stlib.h> �������
#include<ctype.h>//���� �з��� ���� �Լ��� ������ �ִ� <ctype.h> �������

char c;//�ܼ�â�� �Է��� ���ڿ��� ���ڸ� �ϳ��� �޾ƿ� �����ϴ� ���� lookahead
char temp;//state�� 9�� �� �ӽ� ����ҷ� ����ϴ� ���� temp
int state = 0;//���̴��̾�׷� ��ġ�� �����ϴ� ���� state

//���̴��̾�׷� �Լ�
void transaltionDiagram() {
	while (1) {//while���� �̿��Ͽ� �ݺ� ����
		switch (state) {//������ state�� �������� switch������ state ���濡 ���� ó��

		//start(state == 0)
		case 0:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 0;
			//c�� ����� ���ڰ� ���ĺ��� ���
			else if (isalpha(c) != 0) {
				//c�� ����� ���ڰ� 'f'�̸� state�� 1 ����
				if (c == 'f')
					state = 1;
				//c�� ����� ���ڰ� 'i'�̸� state�� 4 ����
				else if (c == 'i')
					state = 4;
				//�ٸ� ���ĺ��� ��� state�� 8 ����
				else
					state = 8;
			}
			//c�� ����� ���ڰ� ���ĺ��� �ƴ� ��� state�� 9 ����
			else if (isalpha(c) == 0) {
				state = 9;
			}
			break;

		//f of 'for'(state == 1)
		case 1:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 1;
			//c�� ����� ���ڰ� ���ĺ��� ���
			else if (isalpha(c) != 0) {
				//c�� ����� ���ڰ� 'o'�̸� state�� 2 ����
				if (c == 'o')
					state = 2;
				//�ٸ� ���ĺ��� ��� state�� 8 ����
				else
					state = 8;
			}//c�� ����� ���ڰ� ������ ��� state�� 8 ����
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c�� ����� ���ڰ� Ư�������� ��� state�� 9 ����
				state = 9;
			break;

		//o of 'for'(state == 2)
		case 2:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 2;
			//c�� ����� ���ڰ� ���ĺ��� ���
			else if (isalpha(c) != 0) {
				//'r'�� ����Ǿ������� state�� 3 ����
				if (c == 'r')
					state = 3;
				//�� ���� ���ĺ��� ��� state�� 8 ����
				else
					state = 8;
			}//c�� ����� ���ڰ� ������ ��� state�� 8 ����
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c�� ����� ���ڰ� Ư�������� ��� state�� 9 ����
				state = 9;
			break;

		//r of 'for'(state == 3)
		case 3:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 3;
			//c�� ����� '$'�� ��� 1�� ���
			else if (c == '$') {
				printf("1 ");
				exit(0);
			}
			//c�� ����� ���ڰ� ���ĺ��̰ų� ������ ��� state�� 8 ����
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c�� ����� ���ڰ� Ư�������� ��� 1 ����ϰ� state�� 9 ����
			else {
				printf("1 ");
				state = 9;
			}
			break;

		//i of 'if', 'int'(state == 4)
		case 4:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 4;
			//c�� ����� ���ڰ� ���ĺ��� ���
			else if (isalpha(c) != 0) {
				//c�� ����� ���ڰ� 'f'�� ��� state�� 5 ����
				if (c == 'f')
					state = 5;
				//c�� ����� ���ڰ� 'n'�� ��� state�� 6 ����
				else if (c == 'n')
					state = 6;
				//�ٸ� ���ĺ��� ��� state�� 8 ����
				else
					state = 8;
			}//c�� ����� ���ڰ� ������ ��� state�� 8 ����
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c�� ����� ���ڰ� Ư�������� ��� state�� 9 ����
				state = 9;
			break;

		//f of 'if'(state == 5)
		case 5:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 5;
			//c�� ����� ���ڰ� '$'�� ��� �ܼ�â�� 2 ���
			else if (c == '$') {
				printf("2 ");
				exit(0);
			}
			//c�� ����� ���ڰ� ���ĺ��̰ų� ������ ��� state�� 8 ����
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c�� ����� ���ڰ� Ư�������� ��� 2�� ����ϰ� state�� 9 ����
			else {
				printf("2 ");
				state = 9;
			}
			break;

		//n of 'int'(state == 6)
		case 6:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 6;
			//c�� ����� ���ڰ� ���ĺ��� ���
			else if (isalpha(c) != 0) {
				//c�� ����� ���ڰ� 't'�� ����� ��� state�� 7 ����
				if (c == 't')
					state = 7;
				//�ٸ� ���ĺ��� ��� state�� 8 ����
				else
					state = 8;
			}//c�� ����� ���ڰ� ������ ��� state�� 8 ����
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c�� ����� ���ڰ� Ư�������� ��� state�� 9 ����
				state = 9;
			break;

		//t of 'int'(state == 7)
		case 7:c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 7;
			//c�� ����� ���ڰ� '$'�� ��� �ܼ�â�� 3 ����ϰ� ����
			else if (c == '$') {
				printf("3 ");
				exit(0);
			}
			//c�� ����� ���ڰ� ���ĺ��̰ų� ������ ��� state�� 8 ����
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c�� ����� ���ڰ� Ư�������� ��� �ܼ�â�� 3 ����ϰ� state�� 9 ����
			else {
				printf("3 ");
				state = 9;
			}
			break;

		//alphabet | digit(state == 8)
		case 8:
			//c�� ����� ���ڰ� ���ĺ��̰ų� ������ ���
			if (isalpha(c) != 0 || isdigit(c) != 0) {
				c = getchar();//c�� ���ڸ� �޾ƿ� ����
				//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
				if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
					state = 8;
				//state�� 8�� �����Ѵ�
				else {
					state = 8;
				}
			}
			//c�� ����� ���ڰ� Ư�������� ���
			else {
				//c�� ����� ���ڰ� '$'�� ��� �ܼ�â�� 9�� ����ϰ� �����Ѵ�.
				if (c == '$') {
					printf("9 ");
					exit(0);
				}
				//'$'�� �ƴ� ��� �ܼ�â�� 9�� ����ϰ� state�� 9�� �����Ѵ�.
				else {
					printf("9 ");
					state = 9;
				}
			}
			break;

		//digit | special(state == 9)
		case 9:
			temp = c;//c�� ����Ǿ� �ִ� ���ڸ� temp�� �����Ѵ�
			c = getchar();//���ڸ� �޾ƿͼ� ���� c�� ����
			//c�� ����� ���ڰ� blank, tab, newline, NUL�� ��쿡�� ���ư��� �ٽ� �޾ƿ´�
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 9;
			//c�� ����� ���ڰ� '$'�� ��� temp�� ����� ���ڸ� �ܼ�â�� ����ϰ� �����Ѵ�.
			else if (c == '$') {
				printf("invalid char '%c' ", temp);
				exit(0);
			}
			//c�� ����� ���ڰ� ���ĺ��̰ų� ���ڸ� temp�� ����� ���ڸ� �ܼ�â�� ����ϰ� state�� 8�� �����Ѵ�.
			else if (isalpha(c) != 0 || isdigit(c) != 0) {
				printf("invalid char '%c' ", temp);
				state = 8;
			}
			//c�� ����� ���ڰ� Ư�����ڸ� temp�� ����� ���ڸ� �ܼ�â�� ����ϰ� state�� 9�� �����Ѵ�.
			else {
				printf("invalid char '%c' ", temp);
				state = 9;
			}
			break;
		}
	}
}
//�����Լ�
void main() {
	transaltionDiagram();//���̴��̾�׷� �Լ� ����
}