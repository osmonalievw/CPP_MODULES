#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void    Harl::debug(void){
    std::cout << MAGENTA << "[DEBUG]\n" << DEFAULT << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void    Harl::info(void){
    std::cout << GRAY << "[INFO]\n" << DEFAULT<< "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void    Harl::warning(void){
    std::cout << YELLOW << "[WARNING]\n" << DEFAULT << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void    Harl::error(void){
    std::cout << RED << "[ERROR]\n" << DEFAULT << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level){
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i = 0;
    while (i < 4 && levels[i] != level)
        i++;
    switch (i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
}
