#include <iostream>
using namespace std;

class Order {
   public:
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
};

int main() {
    Order a;
    a.printIngredient();
    return 0;
}