/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:55:10 by yidouiss          #+#    #+#             */
/*   Updated: 2023/12/21 21:38:13 by blubbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_add_new(t_parse *parse, char *cont)
{
	t_parse *next;
	t_parse *tmp;

	tmp = parse;
	while (tmp->next)
		tmp = tmp->next;
	next = malloc(sizeof(t_parse));
	next = init_parse(next);
	next->args = cont;
	tmp->next = next;
}

void	print_list(t_parse *parse)
{
	t_parse *tmp = parse;

	while (tmp->args)
	{
		printf("%s\n", tmp->args);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

int sep_cmd(t_parse *parse)
{
	char **final;
	int i = 0;

	final = ft_split(parse->args, '|');
	while (final[i])
	{
		parse_add_new(parse, ft_strtrim(final[i], " "));
		i++;
	}
	print_list(parse);
	return (0);
}


int	parsing(t_parse *parse)
{
	sep_cmd(parse);
	return (0);
}
