/*
 * created by Danil Kireev, PFUR NFI-201, 25.10.18, 09:00
 */
#include <vector>
#include "tel_record.h"

/*
 *  №17
 *  На междугородной телефонной станции картотека абонентов,
 *  содержащая сведения о телефонах и их владельцах,
 *  организованно как линейный список.
 *  Программа должна обеспечивать диалог с помощью меню и контроль ошибок при вводе.
 */

int main() {
    std::vector<tel_record> list;
    int r;
    do {
        std::cout << "выберите одну из опций: " << std::endl;
        std::cout << "\tдобавить контакт: 1" << std::endl;
        std::cout << "\tвывести все контакты: 2" << std::endl;
        std::cout << "\tпосчитать счёт для контакта: 3" << std::endl;
        std::cin >> r;
        std::cin.clear();
        switch (r) {
            case 1: {
                tel_record tmp;
                tmp.user_input();
                tmp.print_information();
                list.push_back(tmp);
                }
                break;
            case 2:
                for(int i = 0; i < list.size(); ++i) {
                    std::cout << "элемент " << i+1 << " : " << std::endl;
                    list[i].print_information();
                }
                break;
            case 3: {
                std::string name_info;
                int res, price;
                std::cout << "введите информацию об имене владельце: ";
                getline(std::cin, name_info);
                std::cin.clear();
                std::cout << "введите цену в рублях за минуту: ";
                std::cin >> price;
                for (auto &i : list) if(i.getOwner() == name_info) res += i.getTime_min()*price +
                                i.getTime_hour()*60*price;
                std::cout << "счёт абонента " << name_info << " равен " << res << " рублей";
                }
                break;
            default:
                std::cout << "ОШИБКА";
                __throw_exception_again;
                break;
        }
    } while ((r > 0) and (r < 4));

    return 0;
}