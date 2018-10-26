Intersection * intersection_polygon(Vector *eye, Vector *tVector, Object *polygonOject);
Vector * polygon_normal_vector(Intersection * intersection, Object* object);
Plane* calculate_polygon_plane(Polygon* polygon_object);
void create_flat_points(Polygon * polygon);
int ray_through_polygon(VectorUV intersection, Polygon* polygonObject);

Intersection * intersection_polygon(Vector *eye, Vector *direction, Object *polygonOject){
  long double intersection_1;

  long double numerator;
  long double denominator;
  long double norm;

  Vector intersection_point;
  VectorUV intersectionUV;
  Intersection * intersection;
  intersection = (Intersection*) malloc(sizeof(Intersection));

  Polygon * polygon_object = (Polygon*) polygonOject -> object;


  numerator = (polygon_object -> plane -> A * eye -> x + 
                polygon_object -> plane -> B * eye -> y + 
                polygon_object -> plane -> C * eye -> z + 
                polygon_object -> plane -> D);

  denominator = (polygon_object -> plane -> A * direction -> x + 
                polygon_object -> plane -> B * direction -> y + 
                polygon_object -> plane -> C * direction -> z);

    
  //printf("%.2f\n",  (double) (polygon_object -> plane -> C));
  if (double_is_equal(denominator, 0.0)) {
      intersection = NULL;
      return intersection;
  }
  else{
      intersection_1 = -(numerator / denominator);

      intersection_point.x = eye -> x + intersection_1 * direction -> x;
      intersection_point.y = eye -> y + intersection_1 * direction -> y;
      intersection_point.z = eye -> z + intersection_1 * direction -> z;

      intersection =  new_intersection(polygonOject, intersection_1, intersection_point);

  }

  long double A = fabs(polygon_object -> plane -> A);
  long double B = fabs(polygon_object -> plane -> B);
  long double C = fabs(polygon_object -> plane -> C);

  if (A > B && A > C)
  {
    intersectionUV.u = intersection -> intersection_point.y;
    intersectionUV.v = intersection -> intersection_point.z;
  }
  else if (B > A && B > C)
  {
    intersectionUV.u = intersection -> intersection_point.x;
    intersectionUV.v = intersection -> intersection_point.z;
  }
  else 
  {
    intersectionUV.u = intersection -> intersection_point.x;
    intersectionUV.v = intersection -> intersection_point.y;
  }

  int has_inter = ray_through_polygon(intersectionUV, polygon_object);

  if (has_inter == 1)
  {
    return intersection;
  }
  else
  {
    return NULL;
  }
}

int ray_through_polygon(VectorUV intersection, Polygon* polygonObject)
{
	VectorUV * aux_flatpoints = (VectorUV*) calloc(polygonObject -> points_number,sizeof(VectorUV));

	for (int i = 0; i < polygon ->  points_number; i++) 
  {
		aux_flatpoints[i].u = polygon -> flat_points[i] -> u - intersection.u;
		aux_flatpoints[i].v = polygon -> flat_points[i] -> v - intersection.v;

	}

  //printf("%.2f\n", (double) aux_flatpoints[0].u);
	int wallCounter = 0;
	for (int a = 0; a < polygonObject -> points_number; a++) 
  {
		int b = (a + 1) % (polygon -> points_number);

		if ((aux_flatpoints[a].v > 0 && aux_flatpoints[b].v < 0) || (aux_flatpoints[a].v < 0 && aux_flatpoints[b].v > 0)) 
    {

			if (aux_flatpoints[a].u > 0 && aux_flatpoints[b].u > 0) 
      {
				wallCounter++;

			} else if (aux_flatpoints[a].u > 0 || aux_flatpoints[b].u > 0)
      {
					if ((aux_flatpoints[a].u -aux_flatpoints[a].v * (aux_flatpoints[b].u - aux_flatpoints[a].u)/(aux_flatpoints[b].v-aux_flatpoints[a].v)) >= 0) 
          {
						wallCounter++;
					}
			}
		}
	}

	free (aux_flatpoints);

  return (wallCounter % 2);
}

Plane* calculate_polygon_plane(Polygon* polygon_object)
{

  Plane* new_plane = (Plane*) malloc(sizeof(Plane));

  Vector* point0 = polygon_object -> points_head -> next -> point;
  Vector* point1 = polygon_object -> points_head -> next -> next -> point;
  Vector* point2 = polygon_object -> points_head -> next -> next -> next -> point;

  Vector* vector1 = substract(point1, point0);
  Vector* vector2 = substract(point2, point0);


  Vector* cross_product_result = cross_product(vector1, vector2);
  long double mag = calculate_magnitude(*cross_product_result);


  new_plane -> A = cross_product_result -> x/mag;
  new_plane -> B = cross_product_result -> y/mag;
  new_plane -> C = cross_product_result -> z/mag;


  new_plane -> D = -(new_plane -> A * point0 -> x + 
                    new_plane -> B * point0 -> y +
                    new_plane -> C * point0 -> z);


  free(vector1);
  free(vector2);
  free(cross_product_result);

  return new_plane;
}

Vector * polygon_normal_vector(Intersection * intersection, Object* object){
  Polygon* polygon_object = (Polygon*) object -> object;
  Vector * normal_vector = (Vector*) malloc(sizeof(Vector));

  normal_vector -> x = polygon_object -> plane -> A;
  normal_vector -> y = polygon_object -> plane -> B;
  normal_vector -> z = polygon_object -> plane -> C;

  return normal_vector;
}

void create_flat_points(Polygon * polygon)
{
  polygon -> flat_points = calloc(polygon -> points_number, sizeof(VectorUV));
  
  long double A = fabs(polygon -> plane -> A);
  long double B = fabs(polygon -> plane -> B);
  long double C = fabs(polygon -> plane -> C);

  Points* head = polygon -> points_head;
  Points* tail = polygon -> points_tail;
  Points* current = head;


  if (A > B && A > C)
  {
    for (int i = 0; i < polygon -> points_number; i++, current = current -> next)
    {
      polygon -> flat_points[i] = create_vectorUV(current -> next -> point -> y, 
                                                  current -> next -> point -> z);
    }
  }
  else if (B > A && B > C)
  {
    for (int i = 0; i < polygon -> points_number; i++, current = current -> next)
    {
      polygon -> flat_points[i]= create_vectorUV(current -> next -> point -> x,
                                              current -> next -> point -> z);

    }
  }
  else 
  {
    for (int i = 0; i < polygon -> points_number; i++, current = current -> next)
    {
      polygon -> flat_points[i] = create_vectorUV(current -> next -> point -> x,
                                    current -> next -> point -> y);
    }
  }

}
