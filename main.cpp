#include <stdio.h>

#include <iostream>
#include <queue>
using namespace std;
#define MAX 11
typedef struct {
    int top;
    char data[MAX];
} Stack;

string menu[20] = {
    "햄",          "치즈",        "치킨",     "양상추",   "베이컨", "토마토",
    "소고기 패티", "불고기 패티", "김치",     "초콜릿",   "젤리",   "누텔라",
    "마요네즈",    "케첩",        "스리라차", "청양고추", "된장",   "삼겹살"};
string bread[2] = {"▄▅▆▇▆▅▄", "◥██████◤"};

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
        cout << "┏━━━━━━━┳━━━━━━━━━━━━━━┓\n";
        cout << "┃   1   ┃      햄      ┃\n";
        cout << "┃   2   ┃     치즈     ┃\n";
        cout << "┃   3   ┃     치킨     ┃\n";
        cout << "┃   4   ┃    양상추    ┃\n";
        cout << "┃   5   ┃    베이컨    ┃\n";
        cout << "┃   6   ┃    토마토    ┃\n";
        cout << "┃   7   ┃  소고기 패티 ┃\n";
        cout << "┃   8   ┃  불고기 패티 ┃\n";
        cout << "┃   9   ┃     김치     ┃\n";
        cout << "┃   10  ┃    초콜릿    ┃\n";
        cout << "┃   11  ┃     젤리     ┃\n";
        cout << "┃   12  ┃    누텔라    ┃\n";
        cout << "┃   13  ┃   마요네즈   ┃\n";
        cout << "┃   14  ┃     케첩     ┃\n";
        cout << "┃   15  ┃   스리라차   ┃\n";
        cout << "┃   16  ┃   청양고추   ┃\n";
        cout << "┃   17  ┃     된장     ┃\n";
        cout << "┃   18  ┃    삼겹살    ┃\n";
        cout << "┗━━━━━━━┻━━━━━━━━━━━━━━┛\n";
    }
    void plusIngredient() {
        int i, temp;
        cout << "메뉴를 입력해주세요.\n"
             << "메뉴 입력이 끝나면 -1을 입력해서 종료해주세요.\n";
        while (true) {
            cin >> temp;
            if (temp == -1) break;
            if (temp < 1 || temp > 18) {
                cout << "없는 메뉴입니다.\n";
                continue;
            }
            qMenu.push(temp);
        }
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
    Stack Stemp;
    Stack s;
    Order o;
    a.initStack(&s);
    o.printIngredient();
    o.plusIngredient();
    queue<int> temp = o.qMenu;
    while (!temp.empty()) {
        a.Stacking(&s, temp.front());  // Queue에 저장된 값을 Stack에 저장
        temp.pop();
    }
    int size = o.qMenu.size();

    Stemp = s;
    cout << "\n"
         << "주문하신"
         << " ";
    a.Pop(&Stemp);
    for (int i = 0; i < size; i++) {
        cout << menu[a.Pop(&Stemp)];
    }
    cout << "버거 나왔습니다~~"
         << "\n";
    Stemp = s;
    cout << bread[0] << "\n";
    for (int i = 0; i < size; i++) {
        cout << menu[a.Pop(&Stemp) - 1] << "\n";
    }
    cout << bread[1];
    return 0;
}

/*
▄▅▆▇▆▅▄

◥██████◤
*/

/*
.　 /￣|
　｜ .｜따봉하나
,―′　 .|.∧ ∧ 드립니다
| ＿_）(＾ω＾)
| ＿_）|⊂)
| ＿_）|-Ｊ
ヽ＿)ノ

*/
