/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:46:30 by slombard          #+#    #+#             */
/*   Updated: 2024/02/02 02:04:00 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

char	**build_lines_arr(int fd, size_t *lines_arr_size, size_t *lines_nbr)
{
	char	*line;
	char	**lines_arr;
	char	**tmp;

	lines_arr = handle_ft_calloc(lines_arr_size, fd);
	while ((line = get_next_line(fd)))
	{
		if (*lines_nbr == *lines_arr_size)
		{
			*lines_arr_size *= 2;
			tmp = handle_ft_easy_realloc(lines_arr, *lines_arr_size / 2
				* sizeof(char *), (*lines_arr_size + 1) * sizeof(char *), fd);
			tmp[*lines_arr_size] = NULL;
			lines_arr = tmp;
		}
		lines_arr[*lines_nbr] = line;
		(*lines_nbr)++;
	}
	lines_arr[*lines_nbr] = NULL;
	close(fd);
	return (lines_arr);
}

// We are using directly the ft_easy_realloc function
// cause we don't need to close the file descriptor in case of failure
char	**resize_lines_arr(char **lines_arr, size_t lines_arr_size,
		size_t lines_nbr)
{
	char	**tmp;

	tmp = ft_easy_realloc(lines_arr, lines_arr_size * sizeof(char *), (lines_nbr
			+ 1) * sizeof(char *));
	if (!tmp)
		free_lines_arr_and_exit(lines_arr, "Malloc failed");
	lines_arr = tmp;
	lines_arr[lines_nbr] = NULL;
	return (lines_arr);
}

void	parse_file(int fd, char ***lines_arr)
{
	size_t	lines_arr_size;
	size_t	lines_nbr;

	lines_nbr = 0;
	lines_arr_size = 10;
	*lines_arr = build_lines_arr(fd, &lines_arr_size, &lines_nbr);
	close(fd);
	*lines_arr = resize_lines_arr(*lines_arr, lines_arr_size, lines_nbr);
}
