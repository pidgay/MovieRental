#include "validate.h"

bool validate_text(string *str) { // Check if input does not contain digits
    return any_of(str->begin(), str->end(), ::isdigit);
}

bool validate_float(string *str) { // Check if input is a float
    return str->find_first_not_of(".1234567890") == string::npos;
}

bool validate_int(string *str) { // Check if input is an integer
    return str->find_first_not_of("1234567890") == string::npos;
}

bool validate_movie(string* str, int type) {
    string buffer;
    int count = 0;
    bool wrong_input = false;
    stringstream stream(*str);

    if (type == 1) {
        while (getline(stream, buffer, ';')) { // Check if correct input and assign values
            switch (count) {
                case 0:
                    if (validate_text(&buffer)) {
                        wrong_input = true;
                        break;
                    }
                    count++;
                    break;
                case 1:
                    if (!validate_float(&buffer)) {
                        wrong_input = true;
                        break;
                    }
                    count++;
                    break;
                default:
                    break;
            }

            if (wrong_input) {
                cout << "WRONG INPUT PLEASE TRY AGAIN" << endl;
                break;
            }

        }
    }
    else {
        while (getline(stream, buffer, ';')) { // Check if correct input and assign values
            switch (count) {
                case 0:
                    if (validate_text(&buffer)) {
                        wrong_input = true;
                        break;
                    }
                    count++;
                    break;
                case 1:
                    if (!validate_float(&buffer)) {
                        wrong_input = true;
                        break;
                    }
                    count++;
                    break;
                case 2:
                    if (!validate_int(&buffer)) {
                        wrong_input = true;
                        break;
                    }
                    break;
                default:
                    break;
            }

            if (wrong_input) {
                cout << "WRONG INPUT PLEASE TRY AGAIN" << endl;
                break;
            }

        }
    }
}

bool validate_client(string *str){

}