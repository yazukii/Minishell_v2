/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:45:21 by yidouiss          #+#    #+#             */
/*   Updated: 2023/12/21 14:45:21 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_parse	*init_parse(t_parse *parse)
{
	parse->args = NULL;
	parse->cmd = NULL;
	parse->del = NULL;
	parse->out = NULL;
	parse->in = NULL;
	parse->heredoc = 0;
	parse->cat = 0;
	parse->next = NULL;
	return (parse);
}