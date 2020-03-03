/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 14:45:43 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/03 11:14:46 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dcube.h"

int			init_textures3(t_struct *w)
{
	w->t2->mlx_sp = mlx_init();
	w->t2->img_sp = mlx_xpm_file_to_image(w->t2->mlx_sp,
	w->m->s, &w->t2->w_sp, &w->t2->h_sp);
	if (w->t2->w_sp <= 0 || w->t2->h_sp <= 0)
	{
		write(1, "\nno wait -- SPRITE texture incorrect\n\n", 38);
		return (-1);
	}
	w->t2->addr_sp = mlx_get_data_addr(w->t2->img_sp,
	&w->t2->bits_per_pixel_sp, &w->t2->ll_sp, &w->t2->endian_sp);
	w->mlx2 = mlx_init();
	w->img2 = mlx_new_image(w->mlx2, w->m->rx, w->m->ry);
	w->img1 = mlx_new_image(w->mlx2, w->m->rx, w->m->ry);
	w->addr2 = mlx_get_data_addr(w->img2, &w->bits_per_pixel,
	&w->line_length, &w->endian);
	w->addr1 = mlx_get_data_addr(w->img1, &w->bits_per_pixel,
	&w->line_length, &w->endian);
	w->win2 = mlx_new_window(w->mlx2, w->m->rx, w->m->ry,
	"just wait for the bonus");
	make_map_s(w, w->m);
	return (1);
}

int			init_textures2(t_struct *w)
{
	w->t2->mlx_ea = mlx_init();
	w->t2->img_ea = mlx_xpm_file_to_image(w->t2->mlx_ea, w->m->ea,
	&w->t2->w_ea, &w->t2->h_ea);
	if (w->t2->w_ea <= 0 || w->t2->h_ea <= 0)
	{
		write(1, "\nno wait -- Wall texture EAST incorrect\n\n", 40);
		return (-1);
	}
	w->t2->addr_ea = mlx_get_data_addr(w->t2->img_ea,
	&w->t2->bits_per_pixel_ea, &w->t2->ll_ea, &w->t2->endian_ea);
	w->t2->mlx_so = mlx_init();
	w->t2->img_so = mlx_xpm_file_to_image(w->t2->mlx_so, w->m->so,
	&w->t2->w_so, &w->t2->h_so);
	if (w->t2->w_so <= 0 || w->t2->h_so <= 0)
	{
		write(1, "\nno wait -- Wall texture SOUTH incorrect\n\n", 41);
		return (-1);
	}
	w->t2->addr_so = mlx_get_data_addr(w->t2->img_so,
	&w->t2->bits_per_pixel_so, &w->t2->ll_so, &w->t2->endian_so);
	w->turn = 0;
	w->move1 = 0;
	w->move2 = 0;
	return (init_textures3(w));
}

int			init_textures(t_struct *w)
{
	w->t1->mlx_no = mlx_init();
	w->t1->img_no = mlx_xpm_file_to_image(w->t1->mlx_no, w->m->no,
	&w->t1->w_no, &w->t1->h_no);
	if (w->t1->w_no <= 0 || w->t1->h_no <= 0)
	{
		write(1, "\nno wait -- Wall texture NORTH incorrect\n\n", 41);
		return (-1);
	}
	w->t1->addr_no = mlx_get_data_addr(w->t1->img_no,
	&w->t1->bits_per_pixel_no, &w->t1->ll_no, &w->t1->endian_no);
	w->t1->mlx_we = mlx_init();
	w->t1->img_we = mlx_xpm_file_to_image(w->t1->mlx_we, w->m->we,
	&w->t1->w_we, &w->t1->h_we);
	if (w->t1->w_we <= 0 || w->t1->h_we <= 0)
	{
		write(1, "\nno wait -- Wall texture WEST incorrect\n\n", 40);
		return (-1);
	}
	w->t1->addr_we = mlx_get_data_addr(w->t1->img_we,
	&w->t1->bits_per_pixel_we, &w->t1->ll_we, &w->t1->endian_we);
	return (init_textures2(w));
}

void		init_data(t_struct *w, t_map *f)
{
	mlx_get_screen_size(w->mlx2, &w->x3, &w->y3);
	if (f->rx > w->x3 && f->save != 1)
		f->rx = w->x3;
	if (f->ry > w->y3 && f->save != 1)
		f->ry = w->y3;
	if (f->rx < 50)
		f->rx = 50;
	if (f->ry < 50)
		f->ry = 50;
	w->len_mid = 1 / (tan((1.0 / 6) * PI));
	if (f->ry % 2 == 0 && f->ry != f->num)
		f->ry++;
	if (f->ry == f->num)
		f->ry -= 3;
	f->columns = f->rx / f->columns;
	f->rows = f->ry / f->rows;
	if (f->columns > f->rows)
		f->columns = f->rows;
	else
		f->rows = f->columns;
	f->rows_s = f->rows / 3;
	f->columns_s = f->columns / 3;
	w->wl->eq = f->ry / 2;
}
