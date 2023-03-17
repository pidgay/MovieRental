#ifndef MOVIERENTAL_MOVIE_H
#define MOVIERENTAL_MOVIE_H
#include <string>
#include <iostream>

struct Movie {
    std::string title;
    float price;
    int quantity;
};

void generate_movies(Movie movie[], int size);
void display_movies(Movie movies[], int size);
void delete_movies(Movie movies[]);

#endif //MOVIERENTAL_MOVIE_H
