/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:27:50 by yidouiss          #+#    #+#             */
/*   Updated: 2023/12/20 17:27:50 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_all(t_parse *parse, char *input)
{
	free(input);
	free(parse->args);
	free(parse);
}

int	main(void)
{
	t_parse	*parse;
	char	*input;

	rl_initialize();
	while(1)
	{
		parse = malloc(sizeof(t_parse));
		parse = init_parse(parse);
		input = readline(BLU"minishell$ "RESET);
		add_history(input);
		parsing(parse, input);
		free_all(parse, input);
		//printf("%s\n", parse->args);
	}
	return (0);
}
