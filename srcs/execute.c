/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:28:23 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/05 18:21:43 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	t_arg	*temp;
	int		status;

	status = 0;
	temp = g_data.list;
	if (g_data.redirection[0] != NULL)
		exec_redir(status);
	else if (g_data.command[0] != NULL)
		ft_execve();
	if (ft_strcmp(g_data.command[0], "echo"))
		ft_echo();
}

void	execute(void)
{
	int	status;

	ft_command_line();
	if (builtin() == -1 && g_data.command[0] != NULL)
		status = fork();
	else
		return ;
	if (status == 0)
		check_way();
	else
		waitpid(status, NULL, 0);
}