/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 09:34:25 by username         #+#    #+#              */
/*   Updated: 2026/11/03 09:52:35 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

typedef struct s_list
{
	int				index;
	int				chiffre;
	struct s_list	*pile;
}	t_list;

#endif
