/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:45:21 by yidouiss          #+#    #+#             */
/*   Updated: 2023/12/21 18:38:20 by blubbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_parse	*init_parse(t_parse *parse)
{
	parse->heredoc = 0;
	parse->cat = 0;
	parse->out = 0;
	parse->in = 0;
	return (parse);
}