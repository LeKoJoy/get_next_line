/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrii <andrii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:30:56 by andrii            #+#    #+#             */
/*   Updated: 2024/12/19 21:43:52 by andrii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buffer_process(int fd, char *temp_reader, char *stat_buffer)
{
	int		reader;
	char	*char_temp;

	reader = 1;
	while (reader != '\0')
	{
		reader = read(fd, temp_reader, BUFFER_SIZE);
		if (reader == -1)
			return (0);
		else if (reader == 0)
			break ;
		temp_reader[reader] = '\0';
		if (!stat_buffer)
			stat_buffer = ft_strdup("");
		char_temp = stat_buffer;
		stat_buffer = ft_strjoin(char_temp, temp_reader);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (temp_reader, '\n'))
			break ;
	}
	return (stat_buffer);
}

static char	*extractor(char *temp_buffer)
{
	char	*stat_buffer;
	size_t	len;
	size_t	total_len;

	len = 0;
	while (temp_buffer[len] && temp_buffer[len] != '\n')
		len++;
	if (temp_buffer[len] == '\0')
		return (NULL);
	total_len = ft_strlen(temp_buffer);
	if (total_len - len <= 1)
		return (NULL);
	stat_buffer = ft_strjoin("", temp_buffer + len + 1);
	if (!stat_buffer || *stat_buffer == '\0')
	{
		free(stat_buffer);
		stat_buffer = NULL;
	}
	temp_buffer[len + 1] = '\0';
	return (stat_buffer);
}

char	*get_next_line(int fd)
{
    static char	*stat_buffer;
    char		*temp_buffer;
    char		*temp_reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_reader = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_reader)
		return (0);
	temp_buffer = buffer_process(fd, temp_reader, stat_buffer);
	free(temp_reader);
	temp_reader = NULL;
	if (!temp_buffer)
		return (NULL);
	stat_buffer = extractor(temp_buffer);
	return (temp_buffer);
}
int main(void)
{
    int     fd;
    char    *temp_buffer;

	printf("%d\n", BUFFER_SIZE);
    fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
    temp_buffer = get_next_line(fd);
    printf("%s\n ", temp_buffer);
    free(temp_buffer);

    temp_buffer = get_next_line(fd);
    printf("%s ", temp_buffer);
    free(temp_buffer);

    temp_buffer = get_next_line(fd);
    printf("%s ", temp_buffer);
    free(temp_buffer);

    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);

    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    temp_buffer = get_next_line(fd);
    printf("%s \n", temp_buffer);
    free(temp_buffer);
    
    close(fd);
    return (0);
}