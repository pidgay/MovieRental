#include "movie.h"

void generate_movies(Movie movie[], int size) {
    for (int i = 0; i < size; i++) {
        movie[i].title = "Movie" + std::to_string(i);
        movie[i].price = static_cast<float> (i)/100;
        movie[i].quantity = i;
    }
}

void display_movies(Movie movies[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << movies[i].title << "\t" << movies[i].price << "\t" << movies[i].quantity << "\t\n";
    }
}

void delete_movies(Movie movies[]) {
    delete[] movies;
}

