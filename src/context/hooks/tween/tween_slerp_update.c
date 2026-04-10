/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tween_slerp_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:31:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 15:43:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_bool tween_slerp_update(t_tween *tw, float t)
{
	vec3_slerp_ip(tw->curr, tw->target, t);
	return (vec3_equal_eps(*tw->curr, tw->target, 1e-4f));
}
