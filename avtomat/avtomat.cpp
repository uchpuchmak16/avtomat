#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() {
        cashOnHand = 500; //опредлеяет количество денег в кассе равным 500
    }

    cashRegister(int cash) { //
        cashOnHand = cash;
    }

    int getCurrentBalance() { // возвращает значение cashOnHand
        return cashOnHand;
    }

    void acceptAmount(int amount) { // для получения суммы, внесенной клиентом, и обновления суммы в кассе
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int itemCost;
public:
    dispenserType() {  // устанавливает стоимость и кол-во предметов в диспенсере по 50 штук
        numberOfItems = 50; 
        itemCost = 1;
    }

    dispenserType(int items, int cost) { // устанавливает стоимость и количество предметов в диспенесере на значения, указанные пользователем
        numberOfItems = items;
        itemCost = cost;
    }

    int getNoOfItems() { // возврат имен товара
        return numberOfItems;
    }

    int getCost() { // возврат стоимости товара
        return itemCost;
    }

    void makeSale() { // уменьшение количества товаров на 1
        if (numberOfItems > 0) {
            numberOfItems--;
        }
        else {
            cout << "Sorry, this item is out of stock." << endl; // нет в наличии товара
        }
    }
};

int main() {
    cashRegister register1;

    dispenserType candy(2, 75);
    dispenserType chips(1, 150);
    dispenserType gum(1, 25);
    dispenserType cookies(3, 75);

    cout << "welcome to the vending machine!" << endl;
    cout << "our products: " << endl;
    cout << "all prices are written in russian rubles: " << endl;
    cout << "1. candy  " << candy.getCost() << endl;
    cout << "2. chips  " << chips.getCost() << endl;
    cout << "3. gum  " << gum.getCost() << endl;
    cout << "4. cookies " << cookies.getCost() << endl;

    int choice;
    cout << "enter the number of the product you want to buy: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "the cost of candy is " << candy.getCost() << endl;
        break;
    case 2:
        cout << "the cost of chips is " << chips.getCost() << endl;
        break;
    case 3:
        cout << "the cost of gum is " << gum.getCost() << endl;
        break;
    case 4:
        cout << "the cost of cookies is " << cookies.getCost() << endl;
        break;
    default:
        cout << "invalid choice." << endl;
        break;
    }

    int amount;
    cout << "please enter the amount of money: ";
    cin >> amount;

    register1.acceptAmount(amount);

    switch (choice) {
    case 1:
        candy.makeSale();
        break;
    case 2:
        chips.makeSale();
        break;
    case 3:
        gum.makeSale();
        break;
    case 4:
        cookies.makeSale();
        break;
    }

    cout << "thank you for your purchase!" << endl;

    return 0;
}

