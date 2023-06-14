#ifndef MOVIERENTAL_RENTAL_BASE_H
#define MOVIERENTAL_RENTAL_BASE_H
#include "Movie.h"
#include "Movie_Digital.h"
#include "Movie_Physical.h"
#include "Client.h"
#include "validate.h"
#include <string>
#include <iomanip>
#include <conio.h>
#include <vector>
#include "text_processing.h"

using namespace std;

class Rental_Base {
public:

   // Movie** ptr_movies() {return movies;}
    //Client** ptr_clients() {return clients;}

    Rental_Base(){

    }

    ~Rental_Base(){
       movies.clear();
       clients.clear();
    }

    void client_add();
    void client_remove();
    void client_copy();
    void clients_display();
    void client_edit();

    void movie_add();
    void movie_remove();
    void movies_display();
    void movie_edit();

    size_t get_movie_count(){return movie_count;}
    void set_movie_count(size_t cnt){ movie_count = cnt;}

    size_t get_client_count(){return client_count;}
    void set_client_count(size_t cnt ){client_count = cnt;}

private:
    vector <Movie*> movies;
    vector <Client*> clients;

    size_t movie_count{0};
    size_t client_count{0};

    static void create(Movie**& movies, size_t size);
    static void create(Client**& clients, size_t size);
    static void remove(Movie**& movies, size_t& size);
    static void remove(Client**& clients, size_t& size);

    void add(int type, string movie_string);
    //void resize(Client**& clients, size_t client_count, bool increase);
    //void resize(Movie**& movies, size_t movie_count,bool increase );
};




#endif //MOVIERENTAL_RENTAL_BASE_H
