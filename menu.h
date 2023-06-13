#ifndef MOVIERENTAL_MENU_H
#define MOVIERENTAL_MENU_H
#include <string>
#include <iostream>
#include <conio.h>
#include "Rental_Base.h"
#include "text_processing.h"
using namespace std;

class Menu {
    public:
        explicit Menu() = default;
        void menu();

    private:
        static Rental_Base* _rental;
private:
        void main_menu();
        void menu_rent();
        void menu_return();
        void menu_check();
        void menu_movies();
        void menu_clients();
        void close_program();
};

#endif //MOVIERENTAL_MENU_H
