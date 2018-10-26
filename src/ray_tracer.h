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

RGB* what_color(Vector *eye, Vector *distance);
Intersection * first_intersection (Vector *eye, Vector *distance);
void ray_tracer();

