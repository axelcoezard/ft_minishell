/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_addons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:46:52 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 17:06:43 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_flag(int type)
{
	if (type == REDIR_HD_RIGHT)
		return (O_CREAT | O_WRONLY | O_APPEND);
	return (O_CREAT | O_WRONLY | O_TRUNC);
}

int	redirect_out(t_redirection *redirs)
{
	while (redirs->value)
	{
		if (*redirs->value && (redirs->type == REDIR_RIGHT
				|| redirs->type == REDIR_HD_RIGHT))
		{
			redirs->fd = open(redirs->value + 1, get_flag(redirs->type), \
			S_IRWXU);
			if (redirs->fd == -1)
				return (err(redirs->value + 1, "permission denied"));
			dup2(redirs->fd, 1);
		}
		else if (*redirs->value && redirs->type == REDIR_LEFT
			&& access(redirs->value + 1, R_OK))
			return (err(redirs->value + 1, "no such file or directory"));
		redirs++;
	}
	return (0);
}

void	close_out(t_redirection *redirs)
{
	while (redirs->value)
	{
		if ((redirs->type == REDIR_RIGHT || redirs->type == REDIR_HD_RIGHT
				|| redirs->type == REDIR_LEFT) && redirs->fd)
			close(redirs->fd);
		redirs++;
	}
}

void	pipe_parse(t_env *env, char *cmd)
{
	char	**subcmds;
	int		i;

	subcmds = pipe_split(cmd);
	if (subcmds == NULL)
		return ((void)free(cmd));
	i = 0;
	while (subcmds[i] && subcmds[i + 1])
	{
		if (*subcmds[++i] == '\0')
		{
			free_argv(subcmds);
			free(cmd);
			return ((void)err("syntax error near unexpected token", "|"));
		}
	}
	if (*subcmds && **subcmds)
		pipe_execute(env, subcmds, 0);
	free_argv(subcmds);
	free(cmd);
}
