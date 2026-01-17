/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:22:51 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/30 13:05:40 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook()
{
	count = 0;
	nextIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_func(const Contact &c)
{
	cont[nextIndex] = c;
	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		cont[i].printSummary(i + 1);
	}

	std::cout << "Enter index to display: ";
	int idx;
	if (!(std::cin >> idx) || idx <= 0 || idx > count)
	{
		std::cout << "Invalid index!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cont[idx - 1].print_func();
	}
}