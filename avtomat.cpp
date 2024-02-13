#include <iostream>
#include <map>

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
    int cashOnHand;
public:
    dispenserType() {  // устанавливает стоимость и кол-во предметов в диспенсере по 50 штук
        dispenserType::numberOfItems = 50;
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
            std::cout << "Sorry, this item is out of stock." << std::endl; // нет в наличии товара
        }
    }
    bool isAvailable() const // проверяет наличие товара?
    {
        return numberOfItems > 0;
    }

};
std::map<int, int> calculateChange(int total, int payment) {
    int denominations[] = { 100, 50, 20, 10, 5, 2, 1 };  // номиналы монет или купюр
    std::map<int, int> changeMap; // контейнер для хранения количества монет разного номинала

    int change = payment - total; // вычисляем сдачу

    for (int denom : denominations) {
        int numDenom = change / denom;
        if (numDenom > 0) {
            changeMap[denom] = numDenom;
            change -= numDenom * denom;
        }
    }

    return changeMap;
};

int main() {
    cashRegister register1;

    dispenserType candy(2, 75);
    dispenserType chips(1, 150);
    dispenserType gum(1, 25);
    dispenserType cookies(3, 75);

    std::cout << "welcome to the vending machine!" << std::endl;
    std::cout << "our products: " << std::endl;
    std::cout << "all prices are written in russian rubles: " << std::endl;
    std::cout << "1. candy  " << candy.getCost() << std::endl;
    std::cout << "2. chips  " << chips.getCost() << std::endl;
    std::cout << "3. gum  " << gum.getCost() << std::endl;
    std::cout << "4. cookies " << cookies.getCost() << std::endl;

    int choice;
    std::cout << "enter the number of the product you want to buy: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "the cost of candy is " << candy.getCost() << std::endl;
        break;
    case 2:
        std::cout << "the cost of chips is " << chips.getCost() << std::endl;
        break;
    case 3:
        std::cout << "the cost of gum is " << gum.getCost() << std::endl;
        break;
    case 4:
        std::cout << "the cost of cookies is " << cookies.getCost() << std::endl;
        break;
    default:
        std::cout << "invalid choice." << std::endl;
        break;
    }
    int amount1;
    int amount;
    std::cout << "please enter the amount of money: ";
    std::cin >> amount;

    register1.acceptAmount(amount);
    int change;
    switch (choice) {
    case 1:
        if (amount = candy.getCost()) {
            candy.makeSale();
        }
        else {
            std::cout << "insufficient funds. transaction canceled." << std::endl; // // недостаточно средств
            std::cout << "top up your deposit." << std::endl;
        }
        break;
        case 2:
        if (amount >= chips.getCost()) {
            chips.makeSale();
            amount -= chips.getCost();
        }
        else {
            std::cout << "insufficient funds. transaction canceled." << std::endl; // // недостаточно средств
            std::cout << "top up your deposit." << std::endl;
        }
        
        break;
    case 3:
        if (amount >= gum.getCost()) {
            gum.makeSale();
            amount -= gum.getCost();
        }
        else {
            std::cout << "insufficient funds. transaction canceled." << std::endl; // // недостаточно средств
            std::cout << "top up your deposit." << std::endl;
        }
       break;
    case 4:
        if (amount >= cookies.getCost()) {
            cookies.makeSale();
            amount -= cookies.getCost();
        }
        else {
            std::cout << "insufficient funds. transaction canceled." << std::endl; // // недостаточно средств
            std::cout << "top up your deposit." << std::endl;
        }
        break;
    
           

    }
    
   
         
        

    std::cout << "thank you for your purchase!" << std::endl;
    return 0;
}

