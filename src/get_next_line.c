/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:48:29 by gmichaud          #+#    #+#             */
/*   Updated: 2018/03/19 18:32:05 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** GET_NEXT_LINE :
**
** int get_next_line(int fd, char **line)
**
** get_next_line reads from a file descriptor and forms a line.
** A line ends if a \n is encountered. You can get all the lines of
** a file descriptor by successive calls to get_next_line.
**
** Return values :
** get_next_line returns 1 if a line was read, 0 if there is nothing
** to be read, or -1 if an error occured.
*/

/*
** stocktoline processes whatever is in the stock to create a new line and
** adjust the stock for the next get_next_line call.
** Forms a new line and returns 1 if a \n was found,
** 0 if no \n has been found, or -1 if an error occured.
*/

static int	stocktoline(char **stock, char **line)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while ((*stock)[len] && (*stock)[len] != '\n')
		len++;
	if (!(*line = ft_strnew(sizeof(**line) * len)))
		return (-1);
	*line = ft_strncpy(*line, *stock, len);
	if (((*stock)[len] && !(*stock)[len + 1]) || !(*stock)[len])
	{
		ft_strdel(stock);
		return (1);
	}
	if (!(tmp = ft_strnew(sizeof(*tmp) * (ft_strlen(*stock) - len - 1))))
		return (-1);
	tmp = ft_strcpy(tmp, *stock + len + 1);
	free(*stock);
	*stock = tmp;
	return (1);
}

/*
** bufftostock copies the content from buffer into stock.
** Returns 1 if everything went well or
** -1 if an error occured.
*/

static int	bufftostock(char *buff, char **stock, size_t size)
{
	size_t	o_len;

	buff[size] = '\0';
	o_len = (*stock ? ft_strlen(*stock) : 0);
	if (!(*stock = ft_realloc(*stock, o_len, o_len + size + 1)))
		return (-1);
	while (size--)
	{
		(*stock)[o_len++] = *buff;
		buff++;
	}
	(*stock)[o_len] = '\0';
	return (ft_strchr(*stock, '\n') ? 1 : 0);
}

/*
** getstock checks if a file struct has been created in the chained list
** corresponding to the fd.
** If it finds one, the char *stock is returned, if not, it returns NULL.
*/

char		*getstock(t_list *file_lst, int fd)
{
	while (file_lst)
	{
		if (((t_file*)file_lst->content)->fd == fd)
			return (((t_file*)file_lst->content)->stock);
		file_lst = file_lst->next;
	}
	return (NULL);
}

/*
** manage_lst replaces the stock in chained list file corresponding
** to the fd. If the reading is over, it deletes the file from the
** list. If no file was found in the list, it creates a new file
** containing the fd and the stock.
*/

void		manage_lst(t_list **file_lst, int fd, char *stock, int ret)
{
	t_file	file;
	t_list	*prec;
	t_list	*tmp;

	file.fd = fd;
	file.stock = stock;
	prec = *file_lst;
	tmp = *file_lst;
	while (tmp && ((t_file*)tmp->content)->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		ft_lstadd(file_lst, ft_lstnew(&file, sizeof(file)));
	else
	{
		((t_file*)tmp->content)->stock = stock;
		while (prec != tmp && prec->next != tmp)
			prec = prec->next;
		if (!stock && !ret)
		{
			prec->next = prec ? tmp->next : prec->next;
			*file_lst = (prec == *file_lst) ? (*file_lst)->next : *file_lst;
			free(tmp->content);
			free(tmp);
		}
	}
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	static t_list	*file_lst = NULL;
	char			*stock;
	ssize_t			ret;
	int				flg;

	if (fd < 0 || BUFF_SIZE == 0)
		return (-1);
	stock = getstock(file_lst, fd);
	flg = (stock && ft_strchr(stock, '\n')) ? 1 : 0;
	if (!(buff = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = 1;
	while (!flg && (ret = read(fd, buff, BUFF_SIZE)) > 0)
		flg = bufftostock(buff, &stock, ret);
	ft_memdel((void**)&buff);
	if (flg == -1 || ret == -1)
		return (-1);
	if (stock)
		flg = stocktoline(&stock, line);
	manage_lst(&file_lst, fd, stock, ret);
	if (flg == 0 && ret == 0)
		return (0);
	return (1);
}
