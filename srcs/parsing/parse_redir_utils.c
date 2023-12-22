/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blubbers </var/spool/mail/blubbers>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:34:08 by blubbers          #+#    #+#             */
/*   Updated: 2023/12/22 16:34:08 by blubbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc(t_parse *parse, int s)
{
	char	*del;
	int		i;

	file = malloc(sizeof(char) * 255);
	i = 0;
	while (parse->args[s] == '<' || parse->args[s] == ' ')
		s++;
	while (parse->args[s] != ' ' && parse->args[s] != '\0' && parse->args[s] != '>' && parse->args[s] != '<')
	{
		file[i] = parse->args[s];
		i++;
		s++;
	}
	file[i] = '\0';
	printf("heredoc\n");
}

void	in(t_parse *parse, int s)
{
	char	*file;
	int		i;

	file = malloc(sizeof(char) * 255);
	i = 0;
	while (parse->args[s] == '<' || parse->args[s] == ' ')
		s++;
	while (parse->args[s] != ' ' && parse->args[s] != '\0' && parse->args[s] != '>' && parse->args[s] != '<')
	{
		file[i] = parse->args[s];
		i++;
		s++;
	}
	file[i] = '\0';
	parse->in = file;
	printf("in: %s\n", file);
}

void	out(t_parse *parse, int s)
{
	char	*file;
	int		i;

	file = malloc(sizeof(char) * 255);
	i = 0;
	while (parse->args[s] == '>' || parse->args[s] == ' ')
		s++;
	while (parse->args[s] != ' ' && parse->args[s] != '\0' && parse->args[s] != '>' && parse->args[s] != '<')
	{
		file[i] = parse->args[s];
		i++;
		s++;
	}
	file[i] = '\0';
	parse->out = file;
	printf("out: %s\n", file);
}

void	cat_out(t_parse *parse, int s)
{
	char	*file;
	int		i;

	file = malloc(sizeof(char) * 255);
	i = 0;
	while (parse->args[s] == '>' || parse->args[s] == ' ')
		s++;
	while (parse->args[s] != ' ' && parse->args[s] != '\0' && parse->args[s] != '>' && parse->args[s] != '<')
	{
		file[i] = parse->args[s];
		i++;
		s++;
	}
	file[i] = '\0';
	parse->out = file;
	parse->cat = 1;
	printf("out cat: %s\n", file);
}
