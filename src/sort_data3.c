int	sort_data(char *file)
{
	int		fd;
	char	**tmp;
	char	*map_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (msg_error("\e[1;91mError\nCould not open file.\n\e[0m"));
	vars()->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (vars()->lines + 1));
	initialize_matrix(tmp);
	map_line = get_next_line(fd);
	tmp = sort_loop(map_line, tmp, fd);
	if (vars()->six_elems != 6)
	{
		if (map_line)
			free(map_line);
		if (tmp)
			free_matrix(tmp);
		return (msg_error("\e[1;91mError\nWrong number of elements\n\e[0m"));
	}
	return (put_elems(tmp));
}

int sort_checks(char *map_line, int option)
{
    if (option == 1)
        if (map_line[0] && (map_line[0] == 1 || map_line[0] == 0
                || map_line[0] == ' ' || map_line[0] == '\t'))
            return (1);
    else if (option == 2)
        if (map_line[0] != '1' && map_line[0] != '0' && map_line[0] != '\n')
            if (map_line[0] == 'N' || map_line[0] == 'S'
                || map_line[0] == 'W' || map_line[0] == 'E'
                || map_line[0] == 'F' || map_line[0] == 'C')
                return (1);
    else if (option == 3)
        if (map_line[0] == 'N' || map_line[0] == 'S'
            || map_line[0] == 'W' || map_line[0] == 'E')
            return (1);
    return (0);
}

void    **assign_tmp(char ***tmp, int i, char *map_line, int map_flag)
{
    if (map_flag == 1 && vars()->lines > 0)
    {
        *tmp[++i] = ft_strdup_cub(map_line, map_flag);
        vars()->lines--;
    }
    else if (map_line[0] != '\n' && vars()->lines > 0)
    {
        *tmp[++i] = ft_strdup_cub(map_line, map_flag);
        vars()->lines--;
    }
}

char    **sort_loop(char *map_line, char **tmp, int fd, int i)
{
    int map_flag;
    int i;

    i = -1;
    map_flag = 0;
    while (map_line)
	{
		map_flag = sort_checks(map_line, 1);
		vars()->six_elems += sort_checks(map_line, 2);
		if (sort_checks(map_line, 3) == 1)
			if (check_image(map_line))
			{
				if (map_line)
					free(map_line);
				free_matrix(tmp);
				return (msg_error("\e[1;91mError\nInvalid images.\n\e[0m"));
			}
		assign_tmp(&tmp, i, map_line, map_flag);
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (tmp);
}
