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
	if (!tmp->args)
	{
		tmp->args = cont;
		return;
	}
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

int sep_cmd(t_parse *parse, char *input)
{
	char **final;
	int i = 0;

	final = ft_split(input, '|');
	while (final[i])
	{
		parse_add_new(parse, ft_strtrim(final[i], " "));
		i++;
	}
	return (0);
}


int	parsing(t_parse *parse, char *input)
{
	sep_cmd(parse, input);
	parse_redir(parse);
	return (0);
}
