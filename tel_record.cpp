#include <utility>

#include <utility>

#include <utility>

//
// Created by danai on 10/25/18.
//

#include "tel_record.h"

void tel_record::user_input() {
    std::cout << "введите информацию об имене владельце: ";
    getline(std::cin, owner);
    std::cout << "введите номер телефона в формате \"+7**********:\"";
    std::cin >> number;
    if (number.size() == 10) number = "+7" + number;
    while ((number.size() < 12) || (number.size() > 12)) {
        std::cout << "введите номер телефона в формате \"+7**********:\"";
        std::cin >> number;
        if (number.size() == 10) number = "+7" + number;
    }
    std::cout << "введите время разговора в формате \"**:**\": ";
    std::cin >> time;
    while ((time.size() < 5) || (time.size() > 5)) {
        std::cout << "введите время разговора в формате \"**:**\": ";
        std::cin >> time;
    }
}

void tel_record::print_information() {
    std::cout << "информация об имене владельце: " << owner << std::endl;
    std::cout << "номер телефона: " << number << std::endl;
    std::cout << "время разговора: " << time << std::endl;
}
