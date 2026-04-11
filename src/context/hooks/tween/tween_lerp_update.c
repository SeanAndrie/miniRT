/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tween_lerp_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:30:02 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 15:43:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_bool	tween_lerp_update(t_tween *tw, float t)
{
	vec3_lerp_ip(tw->curr, tw->target, t);
	return (vec3_equal_eps(*tw->curr, tw->target, 1e-4f));
}
