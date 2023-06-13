#include "Rental_Base.h"

void Rental_Base::create(Movie **&movies, size_t size) { // Create movies table
    movies = new Movie * [size];
}

void Rental_Base::create(Client **&clients, size_t size) { // Create clients table
    clients = new Client * [size];
    for (size_t index = 0; index < size; index++)
        clients[index] = new Client("Steve", "Jovs");
}

void Rental_Base::remove(Movie **&movies, size_t &size) { // Remove movies table
    for (size_t index = 0; index < size; index++)
        delete movies[index];
    delete[] movies;
    movies = nullptr;
    size = 0;
}

void Rental_Base::remove(Client **&clients, size_t &size) { // Remove clients table
    for (size_t index = 0; index < size; index++)
        delete clients[index];
    delete[] clients;
    clients = nullptr;
    size = 0;
}

void Rental_Base::add(Movie **&movies, size_t movie_count, int type, string movie_string) { // Add a new position to the array based on movie type
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
        movies[movie_count-1] = new Movie_Digital(title, price);
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
        movies[movie_count-1] = new Movie_Physical(title, price, quantity);
    }
}

void Rental_Base::resize(Client **&clients, size_t client_count,bool increase ) { // Change clients' table size
    size_t new_size;
    if (!increase){ // Decrease size
        new_size = (client_count - 1);
    }
    else{ // Increase size
        new_size = (client_count + 1);
    }

    auto** temp_clients = new Client*[new_size];
    memcpy(temp_clients, clients, new_size * sizeof(Client));
    set_client_count(new_size);
    clients = temp_clients;

}

void Rental_Base::resize(Movie **&movies, size_t movie_count,bool increase ) { // Change movies' table size
    size_t new_size;
    if (!increase){ // Decrease size
        new_size = (movie_count - 1);
    }
    else{ // Increase size
        new_size = (movie_count + 1);
    }

    auto** temp_movies = new Movie*[new_size];
    memcpy(temp_movies, movies, new_size * sizeof(Movie));
    set_movie_count(new_size);
    movies = temp_movies;

}
//=======================================================================================================

void Rental_Base::client_add() { // Add a new client
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
             << setfill('.') << setw(15) << ptr_clients()[index]->get_first_name()
             << setw(15) << ptr_clients()[index]->get_last_name()
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
            ptr_clients()[index]->set_first_name(buffer);
            seq++;
        }
        else
            ptr_clients()[index]->set_last_name(buffer);
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
    resize(movies,get_movie_count(),true);
    add(movies,get_movie_count(), type, movie_string);

}

void Rental_Base::movie_remove(){ // Remove a movie

}

void Rental_Base::movies_display() { // Display movies
    cout << right
         << setfill(' ') << setw(52) << "INDEX"
         << setw(8) << "TITLE"
         << setw(12) << "QUANTITY"
         << setw(12) << "PRICE"
         << endl;

    for (int index = 0; index < 1; ++index) {
        cout << right
             << setfill(' ') << setw(50) << index
             << setfill('.') << setw(10) << ptr_movies()[index]->get_title()
             //<< setw(10) << ptr_movies()[index]->get_quantity()
             << setw(10) << ptr_movies()[index]->get_price()
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
                ptr_movies()[index]->set_title(buffer);
                count++;
                break;
            case 1:
                ptr_movies()[index]->set_price(stof(buffer));
                count++;
                break;
            case 2:
                //ptr_movies()[index]->set_quantity(stoi(buffer));
                break;
            default:
                break;
        }
    }
}