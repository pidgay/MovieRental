#ifndef MOVIERENTAL_MOVIE_H
#define MOVIERENTAL_MOVIE_H
#include <string>
#include <iostream>
using namespace std;

class Movie { // Abstract class
public:
    Movie(const string &title, float price) : title(title), price(price) {}

    string get_title(){ return title;}
    float get_price(){ return price;}
    virtual void get_quantity(){}

    void set_title(string t){ title = t;}
    void set_price(float p){ price = p;}
    virtual void set_quantity(int q){}

    virtual void movie_rent();
    virtual void movie_return();
private:
    string title;
    float price;
};

#endif //MOVIERENTAL_MOVIE_H
