#ifndef PARSER_H
# define PARSER_H

void	process_map_elements(char **lines_arr, int *i, t_map *map,
			t_data *data);
void	process_map_content(char **lines_arr, int first_line, t_data *data);
void	process_map_elements_line(char *line, t_data *data,
			t_map_elements *elements);
void	process_map(char **lines_arr, t_map *map, t_data *data);
void	free_str_arr(char **str_arr);
t_map	*init_map(t_map *map);

int		find_max_width(char **lines_arr, int current_max_width);
int		calculate_height(char **lines_arr, int first_line, t_data *data);
int		has_only_valid_chars(char *line);
int		is_surrounded_by_walls(char **lines_arr, int current_line,
			int first_line, int last_line);
int		spaces_are_surrounded_by_walls(char **lines_arr, int current_line,
			int first_line, int last_line);
void	print_lines_arr(char **lines_arr);
void	free_lines_arr_and_exit(char **lines_arr, char *error_message);
void	collect_elements_data_rgba(char *line, char *identifier, t_data *data);
int		char_isdigit(char c);
int		str_isdigit(char *str);
int		line_has_not_only_spaces(char *line);
int		has_only_one_player(char *line);
int		is_valid_space_sorrounding_char(char c);
void	define_start_and_end(int *start, int *end, int idx, int line_len);
void	print_map_elements(t_data *data);
void	print_map_final(t_data *data);
void	print_elements_status(t_map_elements *elements);
void	print_texture_paths(t_textures_paths *texture_paths);
void	print_ceiling_and_floor(t_rgba *c, t_rgba *f);

#endif
