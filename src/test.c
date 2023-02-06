#include "minirt.h"


void	print_list(t_list *s)
{
	while (s)
	{
		printf("%s\n", (char *)s->obj);
		s = s->next;
	}
}

void	print_ambient(t_ambient *ambient)
{
	printf("-----ambient-----\n");
	printf("ratio : %f\n", ambient->ratio);
	printf("rgb : %f, %f, %f\n", ambient->rgb.x, ambient->rgb.y, ambient->rgb.z);
	printf("-----------------\n");
}

void	print_camera(t_camera *camera)
{
	printf("-----camera-----\n");
	printf("view_point : %f, %f, %f\n", camera->view_point.x, camera->view_point.y, camera->view_point.z);
	printf("vector : %f, %f, %f\n", camera->vector.x, camera->vector.y, camera->vector.z);
	printf("fov : %f\n", camera->fov);
	printf("-----------------\n");
}

void	print_lights(t_list	*light_list)
{
	int i = 1;

	while (light_list)
	{
		t_light *light = (t_light *)light_list->obj;
		printf("-----light%d-----\n", i);
		printf("point : %f, %f, %f\n", light->point.x, light->point.y, light->point.z);
		printf("rgb : %f, %f, %f\n", light->rgb.x, light->rgb.y, light->rgb.z);
		printf("brightness_ratio : %f\n", light->brightness_ratio);
		printf("-----------------\n");
		light_list = light_list->next;
		i++;
	}
}

void	print_sphere(t_sphere *sphere)
{
	printf("-----sphere-----\n");
	printf("center : %f, %f, %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
	printf("rgb : %f, %f, %f\n", sphere->rgb.x, sphere->rgb.y, sphere->rgb.z);
	printf("diameter : %f\n", sphere->diameter);
	printf("-----------------\n");
}

void	print_plane(t_plane *plane)
{
	printf("-----plane-----\n");
	printf("point : %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
	printf("normal_vector : %f, %f, %f\n", plane->normal_vector.x, plane->normal_vector.y, plane->normal_vector.z);
	printf("rgb : %f, %f, %f\n", plane->rgb.x, plane->rgb.y, plane->rgb.z);
	printf("-----------------\n");
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("-----cylinder-----\n");
	printf("point : %f, %f, %f\n", cylinder->point.x, cylinder->point.y, cylinder->point.z);
	printf("normal_vector : %f, %f, %f\n", cylinder->normal_vector.x, cylinder->normal_vector.y, cylinder->normal_vector.z);
	printf("diameter : %f\n", cylinder->diameter);
	printf("height : %f\n", cylinder->height);
	printf("rgb : %f, %f, %f\n", cylinder->rgb.x, cylinder->rgb.y, cylinder->rgb.z);
	printf("-----------------\n");
}

void	print_obj(t_list *obj_list)
{

	while (obj_list)
	{
		if (obj_list->type == SPHERE)
			print_sphere((t_sphere *)obj_list->obj);
		else if (obj_list->type == PLANE)
			print_plane((t_plane *)obj_list->obj);
		else if (obj_list->type == CYLINDER)
			print_cylinder((t_cylinder *)obj_list->obj);
		obj_list = obj_list->next;
	}
	

	
}

void	print_scene(t_scene scene)
{
	print_ambient(scene.ambient);
	print_camera(scene.camera);
	print_lights(scene.lights);
	print_obj(scene.figures);
}

void	print_arr(char **str)
{
	for (int i = 0; str[i]; i++)
	{
		printf("%s\n", str[i]);
	}
}