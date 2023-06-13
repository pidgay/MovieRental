#include "menu.h"

void Menu::main_menu() { // Main menu
    system("cls");
    separator();
    display("M O V I E  R E N T A L");
    separator();
    display("C H O O S E  F U N C T I O N");
    display("1. RENT");
    display("2. RETURN");
    display("3. CHECK RENT STATUS");
    display("4. MOVIE BASE");
    display("5. CLIENT BASE");
    display("9. CLOSE PROGRAM");
    separator();
}

void Menu::menu_rent() { // Menu for renting a movie
    system("cls");

    while (true) {
        int choice = 0;
        system("cls");
        separator();
        display("R E N T  A  M O V I E");
        separator();
        display("C H O O S E  F U N C T I O N");
        display("1. RENT");
        display("8. GO BACK");
        separator();
        choice = get_choice();

        switch (choice) {
            case 8: // Go back
                return;

            case 1: // Rent a movie
                ::system("cls");
                display("CHOOSE A MOVIE TO RENT");
                separator();

                break;

            default:
                break;
        }
    }
}

void Menu::menu_return() { // Menu for returning a movie
    system("cls");

    while (true) {
        int choice = 0;
        system("cls");
        separator();
        display("R E T U R N  A  M O V I E");
        separator();
        display("C H O O S E  F U N C T I O N");
        display("1. RETURN");
        display("8. GO BACK");
        separator();
        choice = get_choice();

        switch (choice) {
            case 8: // Go back
                return;

            case 1: // Return a movie

                break;

            default:
                break;
        }
    }
}

void Menu::menu_check() { // Checking current status of movies rented by a client
    system("cls");
    while (true) {
        int choice = 0;
        system("cls");
        separator();
        display("C H E C K  R E N T  S T A T U S");
        separator();
        display("C H O O S E  F U N C T I O N");
        display("1. CHOOSE CLIENT");
        display("8. GO BACK");
        separator();
        choice = get_choice();

        switch (choice) {
            case 8: // Go back
                return;

            case 1: // Check rent status

                //client_rent_check();
                break;

            default:
                break;
        }
    }
}

void Menu::menu_movies(){ // Managing movie database
    system("cls");
    while (true) {
        int choice = 0;
        system("cls");
        separator();
        display("M O V I E  D A T A B A S E");
        separator();
        display("C H O O S E  F U N C T I O N");
        display("1. ADD A MOVIE");
        display("2. REMOVE A MOVIE");
        display("3. DISPLAY MOVIE DATABASE");
        display("4. EDIT AN EXISTING MOVIE" );
        display("8. GO BACK");
        separator();
        choice = get_choice();

        switch (choice) {
            case 8: // Go back
                return;

            case 1: // Add a new movie
                _rental->movie_add();
                break;
            case 2: // Remove a movie
                _rental->movie_remove();
                break;

            case 3: // Display movie database
                system("cls");
                separator();
                _rental->movies_display();
                separator();
                cout << "Press any key to continue..." << endl;
                getch();
                break;

            case 4: // Edit an existing movie
                system("cls");
                separator();
                display("E D I T  C L I E N T");
                separator();
                display("CHOOSE A MOVIE");
                _rental->movies_display();
                separator();
                _rental->movie_edit();
                separator();
                cout << "Press any key to continue..." << endl;
                getch();
                break;

            default:
                break;
        }
    }
}

void Menu::menu_clients(){ // Manage client database
    system("cls");

    while (true) {
        int choice = 0;
        system("cls");
        separator();
        display("C L I E N T  D A T A B A S E");
        separator();
        display("C H O O S E  F U N C T I O N");
        display("1. COPY FROM A CLIENT");
        display("2. REMOVE A CLIENT");
        display("3. DISPLAY CLIENT DATABASE");
        display("4. EDIT AN EXISTING CLIENT");
        display("8. GO BACK");
        separator();
        choice = get_choice();

        switch (choice) {
            case 8:
                return;

            case 1: // Copy form a client
                system("cls");
                separator();
                display("C O P Y  C L I E N T" );
                separator();
                _rental->clients_display();
                separator();
                _rental->client_copy();
                separator();
                cout << "Press any key to continue..." << endl;
                getch();
                break;

            case 2: // Remove a client

                break;

            case 3: // Display client database
                system("cls");
                separator();
                _rental->clients_display();
                separator();
                cout << "Press any key to continue..." << endl;
                getch();
                break;

            case 4: // Edit an existing client
                system("cls");
                separator();
                display("E D I T  C L I E N T");
                separator();
                display("CHOOSE CLIENT");
                _rental->clients_display();
                separator();
                _rental->client_edit();
                separator();
                cout << "Press any key to continue..." << endl;
                getch();
                break;

            default:
                break;
        }
    }
}

void Menu::close_program(){ // Saving progress and closing the program
    return;
}

void Menu::menu(){ // Main menu body;
    while(true) {
        main_menu();
        int choice = get_choice();
        switch (choice) {
            case 1:
                menu_rent();
                break;
            case 2:
                menu_return();
                break;
            case 3:
                menu_check();
                break;
            case 4:
                menu_movies();
                break;
            case 5:
                menu_clients();
            case 9:
                close_program();
                break;
            default:
                break;
        }
    }
}