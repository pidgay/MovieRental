#include <iostream>
#include "movie.h"

int random_one_to_ten() {
    srand(time(0));
    return (rand()%10)+1;
}

using namespace std;
int main() {
    int size = random_one_to_ten();
    Movie* movies = new Movie[size]();
    generate_movies(movies, size);
    display_movies(movies, size);
    delete_movies(movies);
    return 0;
}
