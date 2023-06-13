#ifndef MOVIERENTAL_CLIENT_H
#define MOVIERENTAL_CLIENT_H
#include <string>
#include <iostream>
#include <utility>
using namespace std;

class Rented_Movie {
public:

private:
    string* title;
    int rent_time;
};

class Client {

public:
    explicit Client(string first_name, const string &last_name) : first_name(std::move(first_name)), last_name(last_name) {}

    Client(const Client &object) {
        first_name = object.first_name;
        last_name = object.last_name;
    }

    string get_first_name() {return first_name;}
    string get_last_name() {return  last_name;}

    void set_first_name(string n) {first_name = n;}
    void set_last_name(string l) {last_name = l;}
private:
    string first_name;
    string last_name;
    //Rented_Movie** Rented_Movies;
};


#endif //MOVIERENTAL_CLIENT_H
