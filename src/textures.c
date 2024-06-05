/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/28 20:23:24 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/03/17 16:30:15 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_textures(t_texture *textures)
{
	textures -> wall_texture = mlx_load_png("./images/wall.png");
	if (!textures -> wall_texture)
		return (1);
	textures -> player_texture = mlx_load_png("./images/player.png");
	if (!textures -> player_texture)
		return (1);
	textures -> exit_texture = mlx_load_png("./images/exit.png");
	if (!textures -> exit_texture)
		return (1);
	textures -> coin_texture = mlx_load_png("./images/coin.png");
	if (!textures -> coin_texture)
		return (1);
	textures -> background_texture = mlx_load_png("./images/background.png");
	if (!textures -> background_texture)
		return (1);
	return (0);
}

int	create_images(mlx_t *mlx, t_texture *textures)
{
	textures -> wall_image
		= mlx_texture_to_image(mlx, textures -> wall_texture);
	if (!textures -> wall_image)
		return (1);
	textures -> player_image
		= mlx_texture_to_image(mlx, textures -> player_texture);
	if (!textures -> player_image)
		return (1);
	textures -> exit_image
		= mlx_texture_to_image(mlx, textures -> exit_texture);
	if (!textures -> exit_image)
		return (1);
	textures -> coin_image
		= mlx_texture_to_image(mlx, textures -> coin_texture);
	if (!textures -> coin_image)
		return (1);
	textures -> background_image
		= mlx_texture_to_image(mlx, textures -> background_texture);
	if (!textures -> background_image)
		return (1);
	return (0);
}

int	resize_images(t_texture *textures)
{
	int	size;

	size = textures -> img_size;
	mlx_resize_image(textures -> wall_image, size, size);
	if (!textures -> wall_image)
		return (1);
	mlx_resize_image(textures -> player_image, size * 0.7, size * 0.7);
	if (!textures -> player_image)
		return (1);
	mlx_resize_image(textures -> exit_image, size, size);
	if (!textures -> exit_image)
		return (1);
	mlx_resize_image(textures -> coin_image, size * 0.7, size * 0.7);
	if (!textures -> coin_image)
		return (1);
	mlx_resize_image(textures -> background_image,
		textures -> window_width, textures -> window_height);
	if (!textures -> background_image)
		return (1);
	return (0);
}
