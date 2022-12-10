#include <stdio.h>

#include <iostream>
using namespace std;
#define MAX 11
typedef struct {
    int top;
    char data[MAX];
} Stack;
class St {
   public:
    void initStack(Stack *s) { s->top == -1; }
    int Full(Stack *s) { return s->top == MAX - 1; }
    int Empty(Stack *s) { return s->top == -1; }
    void Push(Stack *s, int temp) {
        s->top++;
        s->data[s->top] = temp;
    }
    void Stacking(Stack *s, int temp) {
        if (Full(s)) printf("Out of range");
        s->top++;
        s->data[s->top] = temp;
    }
    int Pop(Stack *s) {
        if (Empty(s)) return -1;
        return s->data[s->top--];
    }
};

int main() {
    St a;
    Stack s;
    int test = 10;  // temp data
    a.initStack(&s);
    for (int i = 0; i < test; i++) {
        a.Push(&s, i);
        printf("%d", a.Pop(&s));
    }
    return 0;
}
