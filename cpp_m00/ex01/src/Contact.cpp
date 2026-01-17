/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:22:36 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/28 17:09:19 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include <iomanip>
#include <iostream>

Contact::Contact()
{
	phoneNumber = "";
	firstName = "";
	lastName = "";
	nickName = "";
	darkSecret = "";
}

Contact::~Contact()
{
}

bool Contact::setContact(const std::string &first, const std::string &last,
	const std::string &nick, const std::string &phone,
	const std::string &secret)
{
	if (first.empty() || last.empty() || nick.empty() || phone.empty()
		|| secret.empty())
		return (false);
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkSecret = secret;
	return (true);
}

std::string Contact::formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void Contact::printSummary(int index) const
{
	std::cout << std::setw(10) << index << "|" << formatField(firstName) << "|" << formatField(lastName) << "|" << formatField(nickName) << std::endl;
}

void Contact::print_func() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nick Name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Dark Secret: " << darkSecret << std::endl;
}