#ifndef MOVIERENTAL_MOVIE_DIGITAL_H
#define MOVIERENTAL_MOVIE_DIGITAL_H
#include "Movie.h"

class Movie_Digital: public Movie {
public:
    Movie_Digital(const string &title, float price) : Movie{title, price} {}

private:

};
#endif //MOVIERENTAL_MOVIE_DIGITAL_H

