/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:22:24 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/28 17:12:39 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
  private:
	Contact cont[8];
	int count;
	int nextIndex;

  public:
	PhoneBook();
	~PhoneBook();

	void add_func(const Contact &c);
	void searchContact();
};

#endif