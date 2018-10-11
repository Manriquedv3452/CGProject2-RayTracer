#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "support_functions.h"
#include "structs.h"

RGB* what_color(Vector a, Vector d);
Intersection * first_intersection (Vector a, Vector d);
Intersection * calculate_intersection(Object* object, Vector eye, Vector tVector);
Intersection * intersection_sphere(Vector eye, Vector tVector, Object *sphereOject);
Vector * sphere_normal_vector(Intersection * intersection, Object* object);
void ray_tracer();
void insert_object(Object *object, Scene * pScene);
Object * push_object_to_scene(Scene *pScene);

Object * push_object_to_scene(Scene *pScene)
{
    Object* temp = (Object*) malloc(sizeof(Object));
	temp -> next = pScene -> objectsHead -> next;

	pScene -> objectsHead -> next = (Object*) malloc(sizeof(Object));
	pScene -> objectsHead -> next -> next = temp -> next;
	pScene -> objectsHead -> next -> next -> previous = pScene -> objectsHead -> next;
	pScene -> objectsHead -> next -> previous = pScene -> objectsHead;

	free(temp);

    pScene -> objects_amount++;
    return pScene -> objectsHead -> next;
}

Intersection * new_intersection(Object * object, long double t, Vector intersection_point)
{
	Intersection *new_intersection = (Intersection*) malloc(sizeof(Intersection));
	new_intersection -> object = object;
	new_intersection -> intersection_point = intersection_point;
    new_intersection -> t = t;

	return new_intersection;
}

Scene * new_scene(Vector eye)
{
    Scene * new_scene = (Scene*) malloc(sizeof(Scene));
    new_scene -> objectsHead = (Object*) malloc(sizeof(Object));
    new_scene -> objectsTail = (Object*) malloc(sizeof(Object));

    new_scene -> objectsHead -> next = new_scene -> objectsTail;
    new_scene -> objectsTail -> previous = new_scene -> objectsHead;

    new_scene -> eye = eye;

    return new_scene;

}

Texture * new_texture(int width, int height)
{
    Texture * texture = (Texture*) malloc(sizeof(Texture));
    texture -> height = height;
    texture -> width = width;

    texture -> texels = calloc(height, sizeof(RGB));
    for (int i = 0; i < height; i++)
    {
        texture -> texels[i] = calloc(width, sizeof(RGB));
    }

    return texture;
}

Ray * new_ray(Vector eye, Vector direction)
{
    Ray *ray = (Ray*) malloc(sizeof(Ray));
    ray -> direction = direction;
    ray ->origin = eye;

    return ray;
}

void insert_object(Object *object, Scene * pScene)
{
  Object *obj_aux = (Object*) malloc(sizeof(Object));
  obj_aux -> next = pScene -> objectsTail -> previous;

  pScene -> objectsTail -> previous = object;
  obj_aux -> next -> next = object;
  object -> previous = obj_aux -> next;
  object -> next = pScene -> objectsTail;
  //pScene -> objectsTail -> previous = pScene -> objectsTail -> previous -> next = (Object*) malloc(sizeof(Object));
  
    free(obj_aux);
}

void insert_light(Light *light, Scene * pScene)
{
  Light *lgh_aux = pScene -> lightsTail -> previous;

  pScene -> lightsTail -> previous = light;
  lgh_aux -> next = light;
  light -> previous = lgh_aux;
  light -> next = pScene -> lightsTail;

  pScene -> lights_amount++;

  //free(obj_aux);

}

