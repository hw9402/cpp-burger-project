#include<stdio.h>
#include<iostream>
class Stacking{
	public:
		int MAX = cnt; // 입력받은 햄버거의 토핑 수
		typedef struct {
			int top;
			char data[MAX];
		}Stack;
		void initStack( Stack *s ){
			s -> top == -1;
		}
		int isFull( Stack *s ){
			return s -> top == MAX-1; 
		}
		int isEmpty( Stack *s ){
			cout << "It's just Bread...";
			return s -> top == -1;
		}
		void push( Stack *s, char c ){
			if(isFull(s)){
				cout << "The burger is gonna be collapes!";
				s -> top++;
				s-> data[s->top] = c;
				return;
	}
		char pop( Stack *s ){
	 		if (isEmpty(s)){
		 		cout << "  빵  \n  빵  ";
		 		return -1;
	 		}
		return s->data[s->top--];
		}
}
}

int main(){
	
	return 0;
}