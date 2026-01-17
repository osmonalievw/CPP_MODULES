/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raosmona <raosmona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:05:48 by raosmona          #+#    #+#             */
/*   Updated: 2025/08/31 12:34:44 by raosmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int j = 1; j < ac; j++)
		{
			std::string str(av[j]);
			for (size_t i = 0; i < str.length(); i++)
				std::cout << static_cast<char>(std::toupper(str[i]));
		}
		std::cout << std::endl;
	}
	return (0);
}
