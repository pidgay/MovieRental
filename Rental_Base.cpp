#include "Rental_Base.h"

void Rental_Base::add(int type, string movie_string) { // Add a new position to the array based on movie type
    int count = 0, quantity;
    string buffer, title;
    float price;
    stringstream ss(movie_string);
    if (type == 1) {
        while(getline(ss,buffer,';')) {
            switch (count) {
                case 0:
                    title = buffer;
                    count++;
                    break;
                case 1:
                    price = stof(buffer);
                    break;
                default:
                    break;
            }
        }
        auto movie = new Movie_Digital(title, price);
        movies.push_back(movie);

    }
    else {
        while(getline(ss, buffer, ';')){
            switch (count) {
                case 0:
                    title = buffer;
                    count++;
                    break;
                case 1:
                    price = stof(buffer);
                    count++;
                    break;
                case 2:
                    quantity = stoi(buffer);
                    break;
                default:
                    break;
            }
        }
        auto movie = new Movie_Physical(title, price, quantity);
        movies.push_back(movie);

    }
}

//=======================================================================================================

void Rental_Base::client_add() { // Add a new client
}

void Rental_Base::client_remove() {
    size_t index;
    system("cls");
    separator();
    display("CHOOSE A CLIENT");
    separator();
    clients_display();
    separator();
    cin >> index;
    clients.erase(clients.begin() + index);
}

void Rental_Base::client_copy() { // Copy data from one client to another
    size_t index_from, index_to;
    cout << "                                            CHOOSE CLIENT TO COPY FROM" << endl;
    cin >> index_from;
    system("cls");
    cout << "                                            CHOOSE CLIENT TO COPY TO" << endl;
    clients_display();
    cin >> index_to;
}

void Rental_Base::clients_display(){ // Display clients
    cout << right
         << setfill(' ') << setw(52) << "INDEX"
         << setfill(' ') << setw(15) << "FIRST_NAME"
         << setfill(' ') << setw(15) << "LAST_NAME"
         << endl;

    for (size_t index = 0; index < client_count; ++index) {
        cout << right
             << setfill(' ') << setw(50) << index
             << setfill('.') << setw(15) << clients[index]->get_first_name()
             << setw(15) << clients[index]->get_last_name()
             << endl;
    }
}

void Rental_Base::client_edit(){ // Edit existing client
    size_t index;
    string client_name, buffer;
    cin >> index;
    cout << "TYPE IN NAME AND LAST NAME (USE ';' AS A SEPARATOR)" << endl;

    while(true){ // Check for correct input
        cin >> client_name;
        if(validate_text(&client_name)) {
            cout << "INCORRECT CHARACTERS IN INPUT, TRY AGAIN" << endl;
        }
        else
            break;
    }

    stringstream ss(client_name);
    int seq = 0;

    while(getline(ss, buffer, ';')) { // Assign values
        if(seq == 0) {
            clients[index]->set_first_name(buffer);
            seq++;
        }
        else
            clients[index]->set_last_name(buffer);
    }
}

void Rental_Base::movie_add() { // Add a new movie
    string movie_string;
    int type;
    system("cls");
    display("WHAT TYPE OF MOVIE");
    separator();
    display("1.Digital");
    display("2.Physical Copy");
    separator();
    type = get_choice();

    switch (type) {
        case 1:
            system("cls");
            display("DIGITAL MOVIE");
            separator();
            display("TYPE IN MOVIE TITLE AND PRICE");
            cin >> movie_string;
            if (!validate_movie(&movie_string, type)) {
                display("WRONG INPUT");
            }
            break;

        case 2:
            system("cls");
            display("PHYSICAL MOVIE");
            separator();
            display("TYPE IN MOVIE TITLE, PRICE AND QUANTITY(USE ';' AS A SEPARATOR)");
            cin >> movie_string;
            if (!validate_movie(&movie_string, type)) {
              display("WRONG INPUT");
            }
            break;

        default:
            break;
    }
    add(type, movie_string);
}

void Rental_Base::movie_remove(){ // Remove a movie
    size_t index;
    system("cls");
    separator();
    display("CHOOSE A MOVIE");
    separator();
    movies_display();
    separator();
    cin >> index;
    movies.erase(movies.begin() + index);
}

void Rental_Base::movies_display() { // Display movies
    cout << right
         << setfill(' ') << setw(52) << "INDEX"
         << setw(8) << "TITLE"
         << setw(12) << "QUANTITY"
         << setw(12) << "PRICE"
         << endl;

    for (int index = 0; index < movies.size(); ++index) {
        cout << right
             << setfill(' ') << setw(50) << index
             << setfill('.') << setw(10) << movies[index]->get_title()
             //<< setw(10) << movies[index].get_quantity()
             << setw(10) << movies[index]->get_price()
             << endl;
    }
}

void Rental_Base::movie_edit(){ // Edit an existing movie
    size_t index;
    string movie_string, buffer;

    cin >> index;
    cout << "TYPE IN MOVIE TITLE, PRICE FOR RENTING AND STOCK (USE ';' AS A SEPARATOR)" << endl;
    cin >> movie_string;
    stringstream ss(movie_string);

    int count = 0;
    while(getline(ss, buffer, ';')) { // Check if correct input and assign values
        switch (count) {
            case 0:
                movies[index]->set_title(buffer);
                count++;
                break;
            case 1:
                movies[index]->set_price(stof(buffer));
                count++;
                break;
            case 2:
                //movies[index].set_quantity(stoi(buffer));
                break;
            default:
                break;
        }
    }
}