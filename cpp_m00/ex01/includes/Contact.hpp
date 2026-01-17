/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:22:16 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/30 11:52:58 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkSecret;
	static std::string formatField(const std::string &str);

  public:
	Contact();
	~Contact();
	bool setContact(const std::string &first, const std::string &last,
		const std::string &nick, const std::string &phone,
		const std::string &secret);
	void printSummary(int index) const;
	void print_func() const;
};

#endif