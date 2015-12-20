/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 15:13:06 by mguesner          #+#    #+#             */
/*   Updated: 2015/06/03 15:43:27 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define WIDTH 1920
# define HEIGHT 1080
# define TOTAL_PIX WIDTH * HEIGHT
# define EPSILON 0.1E-7
# define N1 1.0
# define BPP 32
# define PLANES 1
# define COMPRESSION 0
# define PBS HEIGHT*WIDTH*BPP/8
# define FILESIZE PBS+sizeof(t_bitmap)
# define XPPM 0x130B
# define YPPM 0x130B

# include <vecteur.h>
# include <color.h>
# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

# pragma pack(push,1)

typedef struct				s_fileheader
{
	uint8_t					signature[2];
	uint32_t				filesize;
	uint32_t				reserved;
	uint32_t				fileoffset_to_pixelarray;
}							t_fileheader;

typedef struct				s_bitmapinfoheader
{
	uint32_t				dibheadersize;
	uint32_t				width;
	uint32_t				height;
	uint16_t				planes;
	uint16_t				bitsperpixel;
	uint32_t				compression;
	uint32_t				imagesize;
	uint32_t				ypixelpermeter;
	uint32_t				xpixelpermeter;
	uint32_t				numcolorspallette;
	uint32_t				mostimpcolor;
}							t_bitmapinfoheader;

typedef struct				s_bitmap
{
	t_fileheader			fileheader;
	t_bitmapinfoheader		bitmapinfoheader;
}							t_bitmap;

# pragma pack(pop)

typedef enum				e_obj_type
{
	CAM,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
	CONE,
	INTERSECTION,
	TRIANGLE,
	NBOBJTYPE
}							t_obj_type;

typedef struct				s_texture
{
	int						exist;
	void					*imgv;
	char					*data;
	int						width;
	int						height;
	int						bpp;
	int						size_line;
	int						endian;
}							t_texture;

typedef struct				s_obj
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
}							t_obj;

typedef struct				s_camera
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	int						ambient;
	t_point					pix_hg;
	t_point					pix_bg;
	t_point					pix_hd;
	t_point					dir;
}							t_camera;

typedef struct				s_light
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
}							t_light;

typedef struct				s_plane
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	t_vec					norm;
}							t_plane;

typedef struct				s_sphere
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	double					radius;
}							t_sphere;

typedef struct				s_cylinder
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	double					radius;
	t_vec					dir;
}							t_cylinder;

typedef struct				s_cone
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	double					angle;
	t_vec					dir;
}							t_cone;

typedef struct				s_triangle
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	double					transparence;
	double					refraction;
	double					limite1;
	double					limite2;
	t_vec					u;
	t_vec					v;

}							t_triangle;

typedef struct				s_obj_list
{
	t_obj					*obj;
	struct s_obj_list		*next;
}							t_obj_list;

typedef struct				s_obj_list_begin
{
	t_obj_list				*begin;
	t_obj_list				*end;
	int						size;
}							t_obj_list_begin;

typedef struct				s_intersection
{
	t_obj_type				type;
	t_point					coord;
	t_color					color;
	double					rot[3][3];
	t_texture				texture;
	double					specular;
	double					reflection;
	int						nb_obj;
	t_obj_list_begin		*objs;
}							t_intersection;

typedef struct				s_pix
{
	t_obj					*cur_obj;
	int						pix_x;
	int						pix_y;
	int						debug;
	double					dist;
	double					light_dist;
	double					shadow_dist;
	t_vec					pos_pix_vec;
	t_point					inter;
	t_point					inter2;
	t_color					*color;
	t_color					*color_specular;
	t_obj					*in_shadow;
	t_vec					normale;
	t_vec					reflex_vec;
	int						is_in_shadow;
	t_obj					*first_obj;
	t_obj					*shadow_obj;
	t_obj					*map_first_obj;

}							t_pix;

typedef struct				s_list
{
	char					*file;
	int						type;
	struct s_list			*next;
}							t_list;

typedef struct				s_libx
{
	int						state;
	t_list					*files;
	char					current_dir[PATH_MAX];
	void					*window;
	void					*mlx;
	void					*img;
	char					*data;
	int						bpp;
	int						size_line;
	int						endian;
	int						ambient;
	int						width;
	int						height;
	int						current_pix;
	pthread_mutex_t			mutex;
	int						superint;
	t_camera				*cam;
	t_obj_list_begin		spots;
	t_obj_list_begin		obj;
	t_pix					**pix;
	int						antialia;
	int						cshade;
	int						mblur;
	int						sepia;
	double					ref_dist_mblur;
	double					ref_maxdist_mblur;
}							t_libx;

void						menu_rt(t_libx *mlx);
void						cd_custom(t_libx *mlx, char *file);
void						clean_mlx(t_libx *mlx);
void						error(int errno);
void						mlx_struct_init(int width, int height
	, char *win_name, t_libx *mlx);
void						texture_func(t_pix *vec_dir);
void						start(t_libx *mlx);
double						touch(t_obj *obj, t_vec *vec, t_point *origine);
double						touch2(t_obj *obj, t_vec vec, t_point origine);
double						touch4(t_obj *obj, t_vec vec, t_point origine);
double						dist_sphere(t_sphere *sphere
	, t_vec *vec, t_point *o);
double						dist_plane(t_plane *plane, t_vec *vec, t_point *o);
double						dist_cone(t_cone *cone, t_vec *vec, t_point *o);
double						dist_cone2(t_cone *cone, t_vec vec, t_point o);
double						dist_cylinder(t_cylinder *cylinder
	, t_vec *vec, t_point *o);
double						dist_cylinder2(t_cylinder *cylinder
	, t_vec *vec, t_point o);
double						dist_cylinder4(t_cylinder *cylinder
	, t_vec *v, t_point o);
void						set_color_light(t_obj *light, t_pix *pix
	, t_point inter, int nb_spots);

double						dist_triangle(t_triangle *triangle, t_vec *vec
	, t_point *o);
void						calc_lum(t_libx *mlx, t_pix *vec_dir);
t_pix						**precalc_vec_cam(t_camera *cam);
void						inters(t_libx *mlx, int pix, int pix_x, int pix_y);
t_vec						get_normale(t_pix *pix, t_point inter);
void						set_color(t_libx *m, t_pix *pix, int spec_or_not);
void						antialiasing(t_libx *m);
void						apply_specular(t_libx *mlx, t_pix *pix);
void						vec_reflex(t_pix *pix);
void						key_rotate_cam(int keycode, t_libx *mlx);
void						key_translate_cam(int keycode, t_libx *mlx);
void						set_finish_reflection_one(t_pix *vec_dir);
void						set_finish_transparence_one(t_pix *vec_dir);
void						set_finish_transparence(t_pix *vec_dir);
void						set_finish_reflection(t_pix *vec_dir);
void						set_original(t_pix *vec_dir);
void						shadow_subfunc(t_pix **vec_dir,
	double d[3], t_obj_list *tmp);
void						do_raytracing();
void						antialiasing(t_libx *m);
void						cshade(t_libx *m);
void						blur(t_libx *m);
void						sepia(t_libx *m);
void						damier(t_pix *vec_dir);
void						screenshot(t_libx *m);

#endif
