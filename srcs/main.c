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

int	main(void)
{
	t_parse *parse;

	parse = NULL;
	parse = init_parse(parse);
	rl_initialize();
	while(1)
	{
		parse->args = readline(BLU"minishell$ "RESET);
		printf("%s\n", parse->args);
	}
	return (0);
}
