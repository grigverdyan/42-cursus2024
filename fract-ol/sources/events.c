#include "events.h"
#include "mlx.h"
#include "fractal.h"

#include <stdlib.h>

int	on_destroy(t_engine *engine)
{
	mlx_destroy_image(engine->mlx, engine->image.p_img);
	mlx_destroy_window(engine->mlx, engine->window);
	exit(EXIT_SUCCESS);
}
