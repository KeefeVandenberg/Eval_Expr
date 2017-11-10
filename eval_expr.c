/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:15:13 by kvandenb          #+#    #+#             */
/*   Updated: 2017/07/16 14:15:15 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

char		*suppr_spaces(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(str) + 1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j = j + 1;
		}
		i = i + 1;
	}
	str2[j] = '\0';
	return (str2);
}

int			ft_parse_nbr(char **ps)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if ((*ps)[0] == '+' || (*ps)[0] == '-')
	{
		if ((*ps)[0] == '-')
			sign = -1;
		*ps = *ps + 1;
	}
	if ((*ps)[0] == '(')
	{
		*ps = *ps + 1;
		nbr = eval_expr_0(ps);
		if ((*ps)[0] == ')')
			*ps = *ps + 1;
		return (sign * nbr);
	}
	while ('0' <= (*ps)[0] && (*ps)[0] <= '9')
	{
		nbr = (nbr * 10) + (*ps)[0] - '0';
		*ps = *ps + 1;
	}
	return (sign * nbr);
}

int			eval_expr_0(char **ps)
{
	int		lhs;
	int		rhs;
	char	op;

	lhs = ft_parse_nbr(ps);
	while ((*ps)[0] != '\0' && (*ps)[0] != ')')
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		if (op == '+' || op == '-')
			rhs = eval_expr_1(ps);
		else
			rhs = ft_parse_nbr(ps);
		lhs = do_op(lhs, rhs, op);
	}
	return (lhs);
}

int			eval_expr_1(char **ps)
{
	int		lhs;
	int		rhs;
	char	op;

	lhs = ft_parse_nbr(ps);
	while ((*ps)[0] == '*' || (*ps)[0] == '/' || (*ps)[0] == '%')
	{
		op = (*ps)[0];
		*ps = *ps + 1;
		rhs = ft_parse_nbr(ps);
		lhs = do_op(lhs, rhs, op);
	}
	return (lhs);
}

int			eval_expr(char *str)
{
	str = suppr_spaces(str);
	if (str[0] == '\0')
		return (0);
	return (eval_expr_0(&str));
}
