/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:22:44 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/31 13:35:11 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>

void	add_func(PhoneBook &phonebook)
{
	Contact	val;

	std::string phoneNumber;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkSecret;
	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter your nick name: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter your phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter your dark secret: ";
	std::getline(std::cin, darkSecret);
	if (!val.setContact(firstName, lastName, nickName, phoneNumber, darkSecret))
	{
		std::cout << "Error: empty fields not allowed!" << std::endl;
		return ;
	}
	phonebook.add_func(val);
}

void	search_func(void)
{
}

int	main(void)
{
	std::string cmds;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmds))
		{
			std::cout << "\nExiting program..." << std::endl;
			break ;
		}

		if (cmds == "ADD")
			add_func(phonebook);
		else if (cmds == "SEARCH")
			phonebook.searchContact();
		else if (cmds == "EXIT")
		{
			std::cout << "Goodbye! Your Contact are lost forever..." << std::endl;
			break ;
		}
	}
}