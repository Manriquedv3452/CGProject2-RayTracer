#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structs.h"
#include "support_functions.h"
#include "vector.h"
#include "structs_operations.h"
#include "image.c"
#include "textures.c"
#include "sphere.h"
#include "polygon.h"
#include "cylinder.h"
#include "cone.h"

#define ANTIALIASING 0
#define REFLEX_LEVEL 6
#define ACTIVE_MIRROS 0

RGB* what_color(Vector *eye, Vector *distance, int reflex_level);
Intersection * first_intersection (Vector *eye, Vector *distance);
void ray_tracer();
RGB* antialiasing(int i, int j, Vector* direction);
RGB* one_ray(int i, int j, Vector *direction);
Vector* calculate_reflex_vector(Vector* direction, Vector* N, Vector* V);

