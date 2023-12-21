/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidouiss <yidouiss@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:28:53 by yidouiss          #+#    #+#             */
/*   Updated: 2023/12/20 17:28:53 by yidouiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ioctl.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"

# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define MAXPATHLEN 4096

typedef struct s_parse
{
	char			*args;
	char			*cmd;
	char			*del;
	int				heredoc;
	int				cat;
	int				out;
	int				in;
	struct s_parse	*next;
}	t_parse;

t_parse	*init_parse(t_parse *parse);

#endif
