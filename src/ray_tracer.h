#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "support_functions.h"
#include "structs.h"

RGB* what_color(Vector a, Vector d);
Intersection * first_intersection (Vector a, Vector d);
Intersection * calculate_intersection(Object* object, Vector eye, Vector tVector);
Intersection * intersection_sphere(Vector eye, Vector tVector, Object *sphereOject);
void ray_tracer(void);
void insert_object(Object *object);

void writeAVS(RGB** pBuffrer, char* pName, int pFileHeight, int pFileWidth);

void normalize_vector(Vector *vector);
long double calculate_magnitude(Vector vector);

Intersection * new_intersection(Object * object, long double t)
{
	Intersection *new_intersection = (Intersection*) malloc(sizeof(Intersection));
	new_intersection -> object = object;
	//new_intersection -> distance = distance;
	//new_intersection -> intersection_point = intersection_point;
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

Ray * new_ray(Vector eye, Vector direction)
{
    Ray *ray = (Ray*) malloc(sizeof(Ray));
    ray -> direction = direction;
    ray ->origin = eye;

    return ray;
}
