/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blubbers </var/spool/mail/blubbers>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:41 by blubbers          #+#    #+#             */
/*   Updated: 2023/12/22 14:34:41 by blubbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	fill_io(t_parse *parse)
{
	int		i;

	i = 0;
	while (parse->args[i])
	{
		if (parse->args[i] == '>')
		{
			if (parse->args[i + 1] == '>')
				cat_out(parse, ++i);
			else
				out(parse, i);
		}
		if (parse->args[i] == '<')
		{
			if (parse->args[i + 1] == '<')
				heredoc(parse, ++i);
			else
				in(parse, i);
		}
		i++;
	}
}

void	parse_redir(t_parse *parse)
{
	t_parse	*tmp;

	tmp = parse;
	while (tmp)
	{
		fill_io(tmp);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}