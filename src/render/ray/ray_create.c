/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:    +:    +:  +:     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:25:13 by sgadinga          +:++#+       +:++    */
/*   Updated: 2026/03/31 19:01:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>

t_ray   ray_create(t_vec3 orig, const t_tensr *rdir, int x, int y)
{
    t_vec3  dir;
    size_t  offset;
    
    offset = tensr_offset(&rdir->layout, (size_t[]){y, x, 0});
    dir = *(t_vec3 *)((float *)rdir->data + offset);
    return ((t_ray){.orig = orig, .dir = dir});
}
