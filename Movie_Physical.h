#ifndef MOVIERENTAL_MOVIE_PHYSICAL_H
#define MOVIERENTAL_MOVIE_PHYSICAL_H
#include "Movie.h"

class Movie_Physical: public Movie{
public:
    Movie_Physical(const string &title, float price, int quantity)
    : Movie{title, price}, quantity(quantity) {}

    void set_quantity(int q) override   { quantity = q;}
    int get_quantity() const  { return quantity;}

private:
    int quantity;
};

#endif //MOVIERENTAL_MOVIE_PHYSICAL_H
