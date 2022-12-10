// MAX는 define으로 처리
// cout는 std::cout로 해야 됨. 앞에 매번 붙이기 싫으면
// include 밑에 using namespace std; 입력하삼 메인 함수에 클래스 불러와서 테스트
// 해보셈
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 11
typedef struct {
    int top;
    char data[MAX];
} Stack;
class St{
public:
  void initStack(Stack *s) { s-> top == -1; }
  int Full(Stack *s){ return s -> top == MAX - 1; }
  int Empty(Stack *s){ return s-> top == -1; }
  void Push(Stack *s, int temp){
    s -> top++;
    s -> data[s->top] = temp;
  }
  void Stacking(Stack *s, int temp){
    if(Full(s)) printf("Out of range");
    s -> top++;
    s -> data[s->top] = temp;
  }
  int Pop(Stack *s){
    if(Empty(s)) return -1;
    return s->data[s->top--];
  }
};

int main(){
  St a;
  Stack s;
  int test = 10; // temp data
  a.initStack(&s);
  for(int i=0;i<test; i++){
    a.Push(&s, i);
    printf("%d",a.Pop(&s));
  }
  return 0;
}
