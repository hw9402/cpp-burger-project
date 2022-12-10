#include <stdio.h>

#include <iostream>
#include <queue>
using namespace std;
#define MAX 11

typedef struct {
    int top;
    char data[MAX];
} Stack;

class St {
   public:
    void initStack(Stack *s) { s->top = -1; }
    int Full(Stack *s) { return s->top == MAX - 1; }
    int Empty(Stack *s) { return s->top == -1; }
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

class Order {
   public:
    queue<int> qMenu;
    void printIngredient() {
        cout << "          MENU         \n";
        cout << " ----------------------\n";
        cout << "|      햄      |   1   |\n";
        cout << "|     치즈     |   2   |\n";
        cout << "|     치킨     |   3   |\n";
        cout << "|    양상추    |   4   |\n";
        cout << "|    베이컨    |   5   |\n";
        cout << "|    토마토    |   6   |\n";
        cout << "|  소고기 패티 |   7   |\n";
        cout << "|  불고기 패티 |   8   |\n";
        cout << "|     김치     |   9   |\n";
        cout << "|    초콜릿    |   10  |\n";
        cout << "|     젤리     |   11  |\n";
        cout << "|    누텔라    |   12  |\n";
        cout << "|   마요네즈   |   13  |\n";
        cout << "|     케첩     |   14  |\n";
        cout << "|   스리라차   |   15  |\n";
        cout << "|   청양고추   |   16  |\n";
        cout << "|     된장     |   17  |\n";
        cout << "|    삼겹살    |   18  |\n";
        cout << " ----------------------\n";
    }
    void plusIngredient() {
        int i, temp;
        cout << "메뉴를 입력해주세요.\n"
             << "메뉴 입력이 끝나면 -1을 입력해서 종료해주세요.\n";
        qMenu.push(0);
        while (true) {
            cin >> temp;
            if (temp == -1) break;
            if (temp < 1 || temp > 18) {
                cout << "없는 메뉴입니다.\n";
                continue;
            }
            qMenu.push(temp);
        }
        qMenu.push(0);
    }
    void printResult() {
        int i;
        queue<int> temp = qMenu;
        while (!temp.empty()) {
            cout << temp.front() << "\n";
            temp.pop();
        }
    }
};

int main() {
    St a;
    Stack s;
    Order o;
    o.printIngredient();
    o.plusIngredient();
    o.printResult();
    return 0;
}