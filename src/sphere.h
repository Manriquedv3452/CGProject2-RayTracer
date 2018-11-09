Intersection * intersection_sphere(Vector *eye, Vector *tVector, Object *sphereOject);
Vector * sphere_normal_vector(Intersection * intersection, Object* object);

Intersection * intersection_sphere(Vector *eye, Vector *direction, Object *sphereOject)
{
  long double intersection_1;
  long double intersection_2;

  double beta; 
  double gamma;

  long double discriminate;


  Vector intersection_point;
  Intersection * intersection;

  Sphere * sphere_object = (Sphere*) sphereOject -> object;
  intersection = (Intersection*) malloc(sizeof(Intersection));


  
  beta = 2*(
            direction -> x * (eye -> x - sphere_object -> center.x) + 
            direction -> y * (eye -> y - sphere_object -> center.y) + 
            direction -> z * (eye -> z - sphere_object -> center.z)
          );

  gamma = power_int(eye -> x - sphere_object -> center.x, 2) + 
          power_int(eye -> y - sphere_object -> center.y, 2) + 
          power_int(eye -> z - sphere_object -> center.z, 2) - 
          power_int(sphere_object -> radius, 2);

  discriminate = beta*beta - 4*gamma;

  if (discriminate < 0.0)
  {
    intersection = NULL;
  }
  else
  {
    discriminate = sqrt(discriminate);
    intersection_1 = (-1 * beta + discriminate)/2;
    intersection_2 = (-1 * beta - discriminate)/2;
    
    if (intersection_2 < intersection_1)
    {
      long double inter_aux = intersection_1;
      intersection_1 =  intersection_2;
      intersection_2 = inter_aux;
    }
    intersection_point.x = eye -> x + intersection_1 * direction -> x;
    intersection_point.y = eye -> y + intersection_1 * direction -> y;
    intersection_point.z = eye -> z + intersection_1 * direction -> z;

    intersection =  new_intersection(sphereOject, intersection_1, intersection_point);
  }

  return intersection;
}

Vector * sphere_normal_vector(Intersection * intersection, Object* object)
{
  Sphere* sphere_object = (Sphere*) object -> object;
  Vector * normal_vector = (Vector*) malloc(sizeof(Vector));

  normal_vector -> x = (intersection -> intersection_point.x - sphere_object -> center.x) / sphere_object -> radius; 
  normal_vector -> y = (intersection -> intersection_point.y - sphere_object -> center.y) / sphere_object -> radius; 
  normal_vector -> z = (intersection -> intersection_point.z - sphere_object -> center.z) / sphere_object -> radius; 

  return normal_vector;
}
