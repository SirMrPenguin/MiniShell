/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 03:43:03 by anisabel          #+#    #+#             */
/*   Updated: 2026/03/15 02:44:10 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool parse_export(char *str, int len) // valida um argumento de cada vez
{
	int i;

	if (!str || !*str)
		return (false);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (false);
	i = 1;
	while (str[i] && i < len)
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			return (false);
	}
	return (true);
}

static void export_no_args(char **env)
{
	int i;
	int len;
	char *var;
	char *value;

	i = 0;
	while (env[i])
	{
		len = ft_len_till_equal(env[i]);
		var = ft_substr(env[i], 0, len);
		value = ft_substr(env[i], len + 1, ft_strlen(env[i]) - len - 1);
		if (!var || !value)
			return (free(var), free(value));
		ft_printf("declare -x %s=\"%s\"\n", var, value);
		free(var);
		free(value);
		i++;
	}
}

static void found_in_env(char **new_env, char *job, int *i)
{
	int j;
	int len;
	char *dup;

	j = 0;
	len = ft_len_till_equal(job);
	while (new_env[j])
	{
		if (!ft_strncmp(new_env[j], job, len) && (new_env[j][len] == '=' || new_env[j][len] == '\0')) // se a str antes do = for igual e a seguir tem um = no env ou um null
		{
			dup = ft_strdup(job);
			if (!dup)
				return;
			free(new_env[j]);
			new_env[j] = dup;
			return;
		}
		j++;
	}
	new_env[*i] = ft_strdup(job);
	if (!new_env[*i])
		return;
	(*i)++;
}

static char **add_to_env(char **env, int *status, char **job, char **new_env) // pq status
{
	int i;
	int j;

	i = -1;
	j = 1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	while (job[j])
	{
		if (!parse_export(job[j], ft_len_till_equal(job[j])))
		{
			ft_printf("export: not an identifier: %s \n", job[j]);
			*status = 1;
		}
		else
			found_in_env(new_env, job[j], &i);
		j++;
	}
	new_env[i] = NULL;
	return (new_env);
}

int export(t_jobs *job, t_env *env)
{
	char **new_env;
	int i;
	int invalid;

	env->status = 0;
	invalid = 0;
	if (!job->job[1])
		return (export_no_args(env->env), 0);
	i = 1;
	while (job->job[i])
	{
		if (!parse_export(job->job[i], ft_len_till_equal(job->job[i]))) // verificar quais sao validos
			invalid++;
		i++;
	}
	new_env = calloc(count_strings(job->job) + count_strings(env->env) -
						 invalid, sizeof(char *));
	if (!new_env)
		return (1); // Alocar num array memória para as strings já presentes em env + aquelas a adicionar de job,, não é necessário +1 pois já contou com o export
	new_env = add_to_env(env->env, &env->status, job->job, new_env);
	if (!new_env)
		return (1); // adiciona as variaveis de env e depois de job
	free_array(env->env);
	env->env = new_env;
	return (env->status);
}

static void	print_env(char **env)
{
	int	i;

	i = 0;
	printf("---- ENV ----\n");
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	printf("-------------\n");
}

static void	run_test(t_env *env, char **cmd, char *title)
{
	t_jobs	job;
	int		ret;

	job.job = cmd;
	printf("\n=== %s ===\n", title);
	ret = export(&job, env);
	printf("return = %d\n", ret);
	print_env(env->env);
}

int	main(void)
{
	t_env	env;

	env.env = malloc(sizeof(char *) * 4);
	env.env[0] = strdup("PATH=/bin");
	env.env[1] = strdup("USER=anisabel");
	env.env[2] = strdup("HOME=/home/anisabel");
	env.env[3] = NULL;
	env.status = 0;

	print_env(env.env);

	{
		char *cmd[] = {"export", NULL};
		run_test(&env, cmd, "sem args");
	}

	{
		char *cmd[] = {"export", "VAR=42", NULL};
		run_test(&env, cmd, "adicionar variavel nova");
	}

	{
		char *cmd[] = {"export", "PATH=/usr/bin", NULL};
		run_test(&env, cmd, "atualizar variavel existente");
	}

	{
		char *cmd[] = {"export", "1ABC=99", NULL};
		run_test(&env, cmd, "identificador invalido a comecar por numero");
	}

	{
		char *cmd[] = {"export", "=abc", NULL};
		run_test(&env, cmd, "identificador invalido sem nome antes do =");
	}

	{
		char *cmd[] = {"export", "A-B=12", NULL};
		run_test(&env, cmd, "identificador invalido com '-'");
	}

	{
		char *cmd[] = {"export", "_OK=123", NULL};
		run_test(&env, cmd, "identificador valido com underscore");
	}

	{
		char *cmd[] = {"export", "A1=99", NULL};
		run_test(&env, cmd, "identificador valido com numero depois");
	}

	{
		char *cmd[] = {"export", "A=1", "B=2", "C=3", NULL};
		run_test(&env, cmd, "varias validas");
	}

	{
		char *cmd[] = {"export", "OK=1", "2NO=2", "ALSO=3", NULL};
		run_test(&env, cmd, "mistura de validas e invalidas");
	}

	free_array(env.env);
	return (0);
}
