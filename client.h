#pragma once
#include <queue>
using namespace std;
class Order {
   public:
    queue<int> qMenu;
    void printIngredient();
    void plusIngredient();
    void printResult();
};
