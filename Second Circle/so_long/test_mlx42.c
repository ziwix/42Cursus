#include "test_mlx42.h"
#define WIDTH 256
#define HEIGHT 256

static void ft_error(void)
{
	ft_fprintf(2, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

int32_t	main(void)
{
	mlx_t			*mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Test MLX42", true);
	if (!mlx)
		ft_error();
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
