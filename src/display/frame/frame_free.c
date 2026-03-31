/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:25:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 22:53:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <setup/display.h>

void    frame_free(t_frame *frame)
{
    if (!frame)
        return ;
    if (frame->out)
    {
        tensr_free(frame->out);
        frame->out = NULL;
    }
    if (frame->scaled)
    {
        tensr_free(frame->scaled);
        frame->scaled = NULL;
    }
    if (frame->clamped)
    {
        tensr_free(frame->clamped);
        frame->clamped = NULL;
    }
    if (frame->buffer)
    {
        tensr_free(frame->buffer);
        frame->buffer = NULL;
    }
}
