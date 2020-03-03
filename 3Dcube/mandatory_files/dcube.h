/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dcube.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 19:53:48 by wbarendr       #+#    #+#                */
/*   Updated: 2020/03/03 10:47:01 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCUBE_H
# define DCUBE_H

# define PI 3.14159265359
# define PITWO 1.57079632679
# define PIFOUR 0.78539816339
# define TWOPI 6.28318530718

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_map
{
	char			**map;
	int				rows;
	float			step;
	int				columns;
	int				rows_s;
	int				columns_s;
	char			*str;
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				fred;
	int				fgreen;
	int				fblue;
	unsigned long	floor;
	int				cred;
	int				cgreen;
	int				cblue;
	unsigned long	ceiling;
	long			check;
	int				save;
	int				num;
}					t_map;

typedef struct		s_texture1
{
	void			*mlx_no;
	void			*img_no;
	char			*addr_no;
	int				w_no;
	int				h_no;
	int				bits_per_pixel_no;
	int				ll_no;
	int				endian_no;
	void			*mlx_we;
	void			*img_we;
	char			*addr_we;
	int				w_we;
	int				h_we;
	int				bits_per_pixel_we;
	int				ll_we;
	int				endian_we;
	void			*mlx_gun;
	void			*img_gun;
	char			*addr_gun;
	int				w_gun;
	int				h_gun;
	int				bits_per_pixel_gun;
	int				ll_gun;
	int				endian_gun;
	void			*mlx_met;
	void			*img_met;
	char			*addr_met;
	int				w_met;
	int				h_met;
	int				bits_per_pixel_met;
	int				ll_met;
	int				endian_met;
}					t_texture1;

typedef struct		s_texture2
{
	void			*mlx_ea;
	void			*img_ea;
	char			*addr_ea;
	int				w_ea;
	int				h_ea;
	int				bits_per_pixel_ea;
	int				ll_ea;
	int				endian_ea;
	void			*mlx_so;
	void			*img_so;
	char			*addr_so;
	int				w_so;
	int				h_so;
	int				bits_per_pixel_so;
	int				ll_so;
	int				endian_so;
	void			*mlx_sp;
	void			*img_sp;
	char			*addr_sp;
	int				w_sp;
	int				h_sp;
	int				bits_per_pixel_sp;
	int				ll_sp;
	int				endian_sp;
}					t_texture2;

typedef struct		s_wall
{
	float			xhit;
	float			yhit;
	float			xdist;
	float			ydist;
	int				side;
	int				xstep;
	int				ystep;
	float			deltay;
	float			deltax;
	float			x;
	float			y;
	int				first;
	float			spritehit[10];
	float			on_wall_sprite[10];
	float			angle_l;
	float			angle_r;
	int				savex;
	int				savey;
	int				i;
	int				end;
	int				eq;
}					t_wall;

typedef struct		s_struct
{
	void			*mlx2;
	void			*img1;
	void			*img2;
	void			*win2;
	char			*addr2;
	char			*addr1;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;
	unsigned long	color_location;
	unsigned long	color_flashlight;
	unsigned long	color_walls;
	float			centx;
	float			centy;
	t_wall			*wl;
	t_map			*m;
	t_texture1		*t1;
	t_texture2		*t2;
	float			mid;
	float			len_mid;
	unsigned long	black;
	float			on_wall;
	char			*path_gun;
	char			*path_meteor;
	float			move1;
	float			move2;
	float			turn;
	int				counter;
	int				x3;
	int				y3;
}					t_struct;

int					ft_strlen(char *str);
char				*ft_calloc(int size, int amount);
char				*ft_strjoin(t_map *f, char **str2);
int					ft_atoi(const char *str);
int					compare(char *str, char*str2);
void				ft_putstr(char *str);

char				*read_file(t_map *f, int fd);
void				check_match(char c1, char c2, int *invalid, int *c);
int					check_valid_arr(t_map *f);
int					get_other_values(t_map *f, int map);
int					check_char(char c, t_map *f);
void				check_not_square(t_map *f, int *invalid);
int					map_length(char *str, int i);
void				fill_map_with_walls(t_map *f);
void				make_sprite_map_s(int r, int c, t_struct *w, t_map *f);

int					north(t_map *f, int *i);
int					south(t_map *f, int *i);
int					west(t_map *f, int *i);
int					east(t_map *f, int *i);
int					sprite(t_map *f, int *i);

int					ceiling(t_map *f, int *i);
int					ft_floor(t_map *f, int *i);
int					resolution(t_map *f, int *i);
int					more_values(t_map *f, int *i);

char				*free_willy(t_map *f, char *text);
char				*free_fred(t_map *f, char **str2, char *text);
char				*free_map(t_map *f, int r, char *text);
char				*free_map2(t_map *f, char *text);

void				put_map_to_window(t_map *f);
int					turn(t_struct *w);
void				name(t_struct *w, t_map *f);

void				make_three_d(int x, int distance, t_struct *w);
void				del_make_three_d(int x, int distance, t_struct *w);
void				pixelput_three_d(t_struct *w, int x, int y, int color);
void				make_ceiling_floor(t_struct *w, int y1, int y2, int x);
void				make_map_s(t_struct *w, t_map *f);
void				make_map_s2(t_struct *w, t_map *f);
int					direction(t_struct *w, t_map *f, int y, int x);
void				center_point_s(t_struct *w);
void				light_s(t_struct *w, float mid, unsigned long color);
void				light(t_struct *w, float mid);

void				find_wall(t_struct *w, float mid, int rx);
void				find_total_distance1(t_struct *w, float mid);
void				find_total_distance2(t_struct *w, float mid);
void				side_zero(t_struct *w, float mid, int rx);
void				side_one(t_struct *w, float mid, int rx);
void				hit_sprite(t_struct *w, float mid);
void				hit_sprite2(t_struct *w, float mid);

int					init_textures(t_struct *w);
void				init_data(t_struct *w, t_map *f);
void				make_world_no(t_struct *w, float distance, int x);
void				make_world_we(t_struct *w, float distance, int x);
void				make_world_ea(t_struct *w, float distance, int x);
void				make_world_so(t_struct *w, float distance, int x);
void				make_sprite(t_struct *w, float distance,
					float on_wall, int x);

void				move(t_struct *w);
void				move_crab(t_struct *w);
void				sprite_yhit(t_struct *w, float mid, int sign, int sign2);
void				sprite_west_up(t_struct *w, float mid);
void				sprite_west_down(t_struct *w, float mid);
void				sprite_east_up(t_struct *w, float mid);
void				sprite_east_down(t_struct *w, float mid);

unsigned int		make_shade(unsigned int color, float distance);
void				show_gun(t_struct *w);
void				fire(t_struct *w);
int					release(int key, t_struct *w);
int					peerexit(t_struct *w);
void				export_bmp(char *name, char *addr, int width, int height);
int					lego(int key, t_struct *w);
int					press(int key, t_struct *w);

#endif
