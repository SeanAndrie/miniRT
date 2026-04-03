/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tween_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:28:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 15:24:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_tween tween_translation(t_vec3 *pos)
{
    return ((t_tween){
        .curr = pos,
        .target = *pos,
        .update = tween_lerp_update
    });
}
