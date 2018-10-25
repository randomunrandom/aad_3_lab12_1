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
        std::cout << "\tпосчитать счёт для контакта(по имени): 3" << std::endl;
        std::cout << "\tпосчитать счёт для контакта(по номеру): 4" << std::endl;
        std::cin >> r;
        switch (r) {
            case 1: {
                std::cin.clear();
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            case 3:
                {
                    std::string name_info;
                    int res = 0, price;
                    std::cout << "введите информацию об имене владельце: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(std::cin, name_info);
                    std::cout << "введите цену в рублях за минуту: ";
                    std::cin >> price;
                    for (auto &i : list) if(i.getOwner() == name_info) res += i.getTime_min() +
                                    i.getTime_hour()*60;
                    std::cout << "счёт абонента " << name_info << ":" << std::endl;
                    std::cout << "количество минут равено " << res;
                    std::cout << ", счёт равен " << res*price << " рублей" << std::endl;
                }
                break;
            case 4:
                {
                    std::string s_number;
                    int res = 0, price;
                    std::cout << "введите номер телефона в формате \"+7**********\": ";
                    std::cin >> s_number;
                    if (s_number.size() == 10) s_number = "+7" + s_number;
                    if ((s_number.size() == 11) and (s_number.front() == '8')) {
                        s_number.erase(0, 1);
                        s_number = "+7" + s_number;
                    }
                    while ((s_number.size() < 12) or (s_number.size() > 12)) {
                        std::cout << "введите номер телефона в формате \"+7**********\": ";
                        std::cin >> s_number;
                        if (s_number.size() == 10) s_number = "+7" + s_number;
                    }
                    std::cout << "введите цену в рублях за минуту: ";
                    std::cin >> price;
                    for (auto &i : list) if(i.getNumber() == s_number) res += i.getTime_min()*price +
                                    i.getTime_hour()*60*price;
                    std::cout << "счёт абонента с номером" << s_number << ":" << std::endl;
                    std::cout << "количество минут равено " << res;
                    std::cout << ", счёт равен " << res*price << " рублей" << std::endl;
                }
                break;
            default:
                std::cout << "Ошибка, выбрана неверная опция";
                break;
        }
    } while ((r > 0) and (r < 5));

    return 0;
}
