/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:09:59 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/27 02:46:23 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_redir(int status)
{
	char	**redir;
	int		i;

	redir = g_data.redirection;
	i = 0;
	while (redir[i])
	{
		if (ft_strcmp(redir[i], ">"))
		{
			g_data.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(g_data.fd, 1);
			if (g_data.command[0] != NULL && redir[i + 2] == NULL)
				exec_shell(status);
			close(g_data.fd);
		}
		else if (ft_strcmp(redir[i], "<"))
		{
			g_data.fd = open(redir[i + 1], O_RDONLY, 0644);
			printf("%d\n", g_data.fd);
			dup2(g_data.fd, 0);
			if (g_data.command[0] != NULL && redir[i + 2] == NULL)
				exec_shell(status);
			close(g_data.fd);
		}
		if (g_data.fd == -1)
		{
			printf("anan: %s\n", redir[i + 1]);
			exit(1);
		}
		i += 2;
	}
}