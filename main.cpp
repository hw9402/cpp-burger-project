#include <stdio.h>
#include <stdlib.h>
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
    if (Full(s))
      printf("Out of range");
    s->top++;
    s->data[s->top] = temp;
  }
  int Pop(Stack *s) {
    if (Empty(s))
      return -1;
    return s->data[s->top--];
  }
};

class Event {
public:
  string sidemenu[5] = {"감자튀김", "취두부", "양파", "단무지", "어니언링"};
  void Search(string a) {
    for (int i = 0; i < 5; i++) {
      if (a == sidemenu[i]) {
        cout << sidemenu[i] << " 있어요~" << "\n";
        continue;
      }
      else {
        cout << a << " 없어요~" << "\n";}
        return;
      }
    }
  void Quiz(string a){
    string winners[7] = {"우루과이", "이탈리아", "브라질", "독일", "아르헨티나", "스페인", "잉글랜드"};
    for(int i=0; i<7; i++){
      if (a == winners[i]) {
        int gift = rand() % 7;
        cout << "정답! 상품은 " << sidemenu[gift] << "입니다!";
        return;
      }
    }
    for(int i=0; i<7; i++){
      if(a != winners[i]){
        cout << "땡! 다음 기회에..";
        return;
      }
    }
    }
};

class Order {
public:
  queue<int> qMenu;
  void printIngredient() {
    cout << "       INGREDIANT         \n";
    cout << "┏━━━━━━━━━━━━━━┳━━━━━━━┓\n";
    cout << "┃     재료     ┃  번호 ┃\n";
    cout << "┣━━━━━━━━━━━━━━╋━━━━━━━┫\n";
    cout << "┃      햄      ┃   1   ┃\n";
    cout << "┃     치즈     ┃   2   ┃\n";
    cout << "┃     치킨     ┃   3   ┃\n";
    cout << "┃    양상추    ┃   4   ┃\n";
    cout << "┃    베이컨    ┃   5   ┃\n";
    cout << "┃    토마토    ┃   6   ┃\n";
    cout << "┃  소고기 패티 ┃   7   ┃\n";
    cout << "┃  불고기 패티 ┃   8   ┃\n";
    cout << "┃     김치     ┃   9   ┃\n";
    cout << "┃    초콜릿    ┃   10  ┃\n";
    cout << "┃     젤리     ┃   11  ┃\n";
    cout << "┃    누텔라    ┃   12  ┃\n";
    cout << "┃   마요네즈   ┃   13  ┃\n";
    cout << "┃     케첩     ┃   14  ┃\n";
    cout << "┃   스리라차   ┃   15  ┃\n";
    cout << "┃   청양고추   ┃   16  ┃\n";
    cout << "┃     된장     ┃   17  ┃\n";
    cout << "┃    삼겹살    ┃   18  ┃\n";
    cout << "┗━━━━━━━━━━━━━━┻━━━━━━━┛\n";
  }
  void plusIngredient() {
    int i, temp;
    cout << "햄버거 재료를 입력해주세요.\n"
         << "재료 입력이 끝나면 -1을 입력해서 종료해주세요.\n";
    while (true) {
      cin >> temp;
      if (temp == -1)
        break;
      if (temp < 1 || temp > 18) {
        cout << "없는 재료입니다.\n";
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
  Event e;
  Stack s;
  Order o;
  a.initStack(&s);
  o.printIngredient();
  o.plusIngredient();
  queue<int> temp = o.qMenu;
  while (!temp.empty()) {
    a.Stacking(&s, temp.front()); // Queue에 저장된 값을 Stack에 저장
    temp.pop();
  }
  int size = o.qMenu.size();

  Stemp = s;
  cout << "정답을 맞추면 사이드메뉴가 공짜!!"
       << "\n";
  cout << "정답 입력하기(any key) / 사이드 메뉴 검색하기(S) : ";
  char cmd;
  cin >> cmd;
  if (cmd == 'S') {
    string element;
    cout << "검색 : ";
    cin >> element;
    e.Search(element);
  }
  else{
    string answer;
    cout << "역대 월드컵 우승국은?" << "\n";
    cout << "정답 : ";
    cin >> answer;
    e.Quiz(answer);
  }
  cout << "\n" << "주문하신" << " ";
  for (int i = 0; i < size; i++) {
    cout << menu[a.Pop(&Stemp)-1];
  }
  cout << "버거 나왔습니다~~" << "\n";
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
