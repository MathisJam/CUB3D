/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:58:09 by jchen             #+#    #+#             */
/*   Updated: 2025/02/04 16:33:38 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *buffer, char *reading)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, reading);
	free(buffer);
	return (tmp);
}
