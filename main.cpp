#include <iostream>
#include <random>
#include "menu.h"
using namespace std;

Rental_Base* Menu::_rental = new Rental_Base();

int main() {
    auto* menu = new Menu();
    menu->menu();
    return 0;
}