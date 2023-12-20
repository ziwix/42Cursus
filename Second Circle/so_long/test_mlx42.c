#include "test_mlx42.h"
#define WIDTH 1920
#define HEIGHT 1024

typedef struct fence_img
{
	mlx_image_t	*fence;
} fence_img_t;

typedef struct game
{
	mlx_t	*mlx;
	fence_img_t	*player;
} game_t;


static void ft_error(void)
{
	ft_fprintf(2, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static int	ft_key_hook(void *param)
{

	game_t	*params = (game_t *)param;

	if (mlx_is_key_down(params->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(params->mlx);
	if (mlx_is_key_down(params->mlx, MLX_KEY_W))
		params->player->fence->instances[0].y -= 128;
	if (mlx_is_key_down(params->mlx, MLX_KEY_A))
		params->player->fence->instances[0].x -= 128;
	if (mlx_is_key_down(params->mlx, MLX_KEY_S))
		params->player->fence->instances[0].y += 128;
	if (mlx_is_key_down(params->mlx, MLX_KEY_D))
		params->player->fence->instances[0].x += 128;

	return (0);
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	fence_img_t		*player;
	mlx_texture_t	*texture;
	game_t 			game_params;

	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(WIDTH, HEIGHT, "Test MLX42", false);
	if (!mlx)
		ft_error();
	player = malloc(sizeof(fence_img_t));
	if (!player)
    	ft_error();
	texture = mlx_load_png("./textures/fence_tiles.png");
	if (!texture)
		ft_error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error();
	player->fence = img;
	if (mlx_image_to_window(mlx, player->fence, 128, 128) < 0)
		ft_error();
	game_params.mlx = mlx;
	game_params.player = player;
	mlx_loop_hook(game_params.mlx, (void *)ft_key_hook, &game_params);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(player);
	return (EXIT_SUCCESS);
}
