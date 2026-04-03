/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tween_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:29:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 15:24:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_tween tween_rotation(t_vec3 *dir)
{
    return ((t_tween){
        .curr = dir,
        .target = *dir,
        .update = tween_slerp_update
    });
}
