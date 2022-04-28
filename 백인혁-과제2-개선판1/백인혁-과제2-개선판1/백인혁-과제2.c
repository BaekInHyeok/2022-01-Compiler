/*프로그램명 : 2022-1 컴파일러 과제 2
* 작성자 : 2020039096 백인혁
* 최초 작성 완료일 : 2022.04.09
* 1차 수정 : 2022.04.11
* 특이사항 : 문자열 끝에 $가 입력하여 문자열이 끝났음을 알린다. ex) for -> for$, int123 -> int123$
*/
#include<stdio.h>//표준 입출력 함수를 가지고 있는 <stdio.h> 헤더파일
#include<stdlib.h>//실행환경 관련 변수들을 가지고 있는 <stlib.h> 헤더파일
#include<ctype.h>//문자 분류에 관한 함수를 가지고 있는 <ctype.h> 헤더파일

char c;//콘솔창에 입력한 문자열의 문자를 하나씩 받아와 저장하는 변수 lookahead
char temp;//state가 9일 때 임시 저장소로 사용하는 변수 temp
int state = 0;//전이다이어그램 위치를 저장하는 변수 state

//전이다이어그램 함수
void transaltionDiagram() {
	while (1) {//while문을 이용하여 반복 수행
		switch (state) {//변수를 state를 기준으로 switch문으로 state 변경에 대한 처리

		//start(state == 0)
		case 0:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 0;
			//c에 저장된 문자가 알파벳인 경우
			else if (isalpha(c) != 0) {
				//c에 저장된 문자가 'f'이면 state에 1 저장
				if (c == 'f')
					state = 1;
				//c에 저장된 문자가 'i'이면 state에 4 저장
				else if (c == 'i')
					state = 4;
				//다른 알파벳인 경우 state에 8 저장
				else
					state = 8;
			}
			//c에 저장된 문자가 알파벳이 아닌 경우 state에 9 저장
			else if (isalpha(c) == 0) {
				state = 9;
			}
			break;

		//f of 'for'(state == 1)
		case 1:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 1;
			//c에 저장된 문자가 알파벳인 경우
			else if (isalpha(c) != 0) {
				//c에 저장된 문자가 'o'이면 state에 2 저장
				if (c == 'o')
					state = 2;
				//다른 알파벳인 경우 state에 8 저장
				else
					state = 8;
			}//c에 저장된 문자가 숫자인 경우 state에 8 저장
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c에 저장된 문자가 특수문자인 경우 state에 9 저장
				state = 9;
			break;

		//o of 'for'(state == 2)
		case 2:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 2;
			//c에 저장된 문자가 알파벳인 경우
			else if (isalpha(c) != 0) {
				//'r'이 저장되어있으면 state에 3 저장
				if (c == 'r')
					state = 3;
				//그 외의 알파벳인 경우 state에 8 저장
				else
					state = 8;
			}//c에 저장된 문자가 숫자인 경우 state에 8 저장
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c에 저장된 문자가 특수문자인 경우 state에 9 저장
				state = 9;
			break;

		//r of 'for'(state == 3)
		case 3:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 3;
			//c에 저장된 '$'인 경우 1을 출력
			else if (c == '$') {
				printf("1 ");
				exit(0);
			}
			//c에 저장된 문자가 알파벳이거나 숫자일 경우 state에 8 저장
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c애 저장된 문자가 특수문자일 경우 1 출력하고 state에 9 저장
			else {
				printf("1 ");
				state = 9;
			}
			break;

		//i of 'if', 'int'(state == 4)
		case 4:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 4;
			//c에 저장된 문자가 알파벳일 경우
			else if (isalpha(c) != 0) {
				//c에 저장된 문자가 'f'인 경우 state에 5 저장
				if (c == 'f')
					state = 5;
				//c에 저장된 문자가 'n'인 경우 state에 6 저장
				else if (c == 'n')
					state = 6;
				//다른 알파벳인 경우 state에 8 저장
				else
					state = 8;
			}//c에 저장된 문자가 숫자인 경우 state에 8 저장
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c에 저장된 문자가 특수문자인 경우 state에 9 저장
				state = 9;
			break;

		//f of 'if'(state == 5)
		case 5:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 5;
			//c에 저장된 문자가 '$'일 경우 콘솔창에 2 출력
			else if (c == '$') {
				printf("2 ");
				exit(0);
			}
			//c에 저장된 문자가 알파벳이거나 숫자일 경우 state에 8 저장
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c에 저장된 문자가 특수문자일 경우 2를 출력하고 state에 9 저장
			else {
				printf("2 ");
				state = 9;
			}
			break;

		//n of 'int'(state == 6)
		case 6:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 6;
			//c에 저장된 문자가 알파벳인 경우
			else if (isalpha(c) != 0) {
				//c에 저장된 문자가 't'에 저장된 경우 state에 7 저장
				if (c == 't')
					state = 7;
				//다른 알파벳인 경우 state에 8 저장
				else
					state = 8;
			}//c에 저장된 문자가 숫자인 경우 state에 8 저장
			else if (isdigit(c) != 0) {
				state = 8;
			}
			else//c에 저장된 문자가 특수문자인 경우 state에 9 저장
				state = 9;
			break;

		//t of 'int'(state == 7)
		case 7:c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 7;
			//c에 저장된 문자가 '$'일 경우 콘솔창에 3 출력하고 종료
			else if (c == '$') {
				printf("3 ");
				exit(0);
			}
			//c에 저장된 문자가 알파벳이거나 숫자일 경우 state에 8 저장
			else if (isalpha(c) != 0 || isdigit(c) != 0)
				state = 8;
			//c에 저장된 문자가 특수문자일 경우 콘솔창에 3 출력하고 state에 9 저장
			else {
				printf("3 ");
				state = 9;
			}
			break;

		//alphabet | digit(state == 8)
		case 8:
			//c에 저장된 문자가 알파벳이거나 숫자인 경우
			if (isalpha(c) != 0 || isdigit(c) != 0) {
				c = getchar();//c에 문자를 받아와 저장
				//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
				if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
					state = 8;
				//state에 8을 저장한다
				else {
					state = 8;
				}
			}
			//c에 저장된 문자가 특수문자일 경우
			else {
				//c에 저장된 문자가 '$'인 경우 콘솔창에 9를 출력하고 종료한다.
				if (c == '$') {
					printf("9 ");
					exit(0);
				}
				//'$'가 아닌 경우 콘솔창에 9를 출력하고 state에 9을 저장한다.
				else {
					printf("9 ");
					state = 9;
				}
			}
			break;

		//digit | special(state == 9)
		case 9:
			temp = c;//c에 저장되어 있는 문자를 temp에 저장한다
			c = getchar();//문자를 받아와서 변수 c에 저장
			//c에 저장된 문자가 blank, tab, newline, NUL일 경우에는 돌아가서 다시 받아온다
			if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
				state = 9;
			//c에 저장된 문자가 '$'인 경우 temp에 저장된 문자를 콘솔창에 출력하고 종료한다.
			else if (c == '$') {
				printf("invalid char '%c' ", temp);
				exit(0);
			}
			//c에 저장된 문자가 알파벳이거나 숫자면 temp에 저장된 문자를 콘솔창에 출력하고 state에 8을 저장한다.
			else if (isalpha(c) != 0 || isdigit(c) != 0) {
				printf("invalid char '%c' ", temp);
				state = 8;
			}
			//c에 저장된 문자가 특수문자면 temp에 저장된 문자를 콘솔창에 출력하고 state에 9을 저장한다.
			else {
				printf("invalid char '%c' ", temp);
				state = 9;
			}
			break;
		}
	}
}
//메인함수
void main() {
	transaltionDiagram();//전이다이어그램 함수 실행
}