/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_free.c                                         :::      ::::::::   */
/*                                                    +                     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:+++:+++:+++:+++:++:   */
/*   Created: 2026/03/11 11:47:39 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 01:22:34 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>
#include <stdlib.h>

void	obj_free(t_object **head)
{
	t_object	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}
