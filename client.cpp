#include <iostream>
#include <queue>
#define MAX_MENU_COUNT 11
using namespace std;

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
        int count, i, temp;
        cout << "메뉴 종류의 수를 입력해주세요(최대 10개) : ";
        cin >> count;
        cout << "메뉴를 입력해주세요 | 형식 : 1(메뉴 번호)\n";
        qMenu.push(0);
        for (i = 1; i <= count; i++) {
            cin >> temp;
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
    Order a;
    a.printIngredient();
    a.plusIngredient();
    a.printResult();
    return 0;
}