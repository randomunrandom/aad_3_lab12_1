#include <utility>

#include <utility>

#include <utility>

//
// Created by danai on 10/25/18.
//

#include "tel_record.h"

void tel_record::user_input() {
    char c;
    std::cout << "введите информацию об имене владельце: ";
    std::cin.clear();
    getline(std::cin, owner);
    std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "введите номер телефона в формате \"+7**********\": ";
    std::cin >> number;
    if (number.size() == 10) number = "+7" + number;
    if ((number.size() == 11) and (number.front() == '8')) {
        number.erase(0, 1);
        number = "+7" + number;
    }
    while ((number.size() < 12) or (number.size() > 12)) {
        std::cout << "введите номер телефона в формате \"+7**********\": ";
        std::cin >> number;
        if (number.size() == 10) number = "+7" + number;
    }
    std::cout << "введите время разговора в формате \"ЧЧ:ММ\": ";
    std::cin >> time_hour >> c >> time_min;
    //std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while ((c != ':') or (time_hour <= 0) or (time_min <= 0) or (time_min >= 60)) {
        std::cout << "введите время разговора в формате \"ЧЧ:ММ\": ";
        std::cin >> time_hour >> c >> time_min;
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void tel_record::print_information() {
    std::cout << "информация об имене владельце: " << owner << std::endl;
    std::cout << "номер телефона: " << number << std::endl;
    std::cout << "время разговора(ЧЧ:ММ): " << time_hour << ":" << time_min << std::endl;
}
