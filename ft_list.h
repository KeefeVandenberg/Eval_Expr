/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:27:35 by kvandenb          #+#    #+#             */
/*   Updated: 2017/07/16 18:53:12 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_put_nbr(int nbr);
int		do_op(int lhs, int rhs, char op);
char	*suppr_spaces(char *str);
int		ft_parse_nbr(char **ps);
int		eval_expr_0(char **ps);
int		eval_expr_1(char **ps);
int		eval_expr(char *str);
#endif
