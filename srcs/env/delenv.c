/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalta <spalta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:13:16 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/13 17:29:21 by spalta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delenv(char **envp, int j, int flag)
{
	int		i;
	int		k;
	char	**new_envp;

	k = 0;
	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp)));
	while (envp[i])
	{
		if (i == j)
		{
			free(envp[i]);
			i++;
		}
		else
		{
			new_envp[k] = envp[i];
			i++;
			k++;
		}
	}
	new_envp[k] = NULL;
	if (!flag)
		g_data.envp = new_envp;
	else
		g_data.ex_path = new_envp;
	free(envp);
}
