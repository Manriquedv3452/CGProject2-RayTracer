#include "ray_tracer.h"
#include "vector.h"
#include "image.c"
#include "textures.c"

long double mag_aux;

RGB* what_color(Vector eye, Vector parametric)
{
  RGB * color;
  RGB *new_color = (RGB*) malloc(sizeof(RGB));
  Intersection * intersection = first_intersection(eye, parametric);
  Vector *L;
  Vector *N;
  Vector intersection_point;
  long double I;
  Object* object;
  Vector light_intersection;
  long double L_point_N;
  Light* current_light;
  long double light_distance;

  long double Fatt; //atenation factor

  L = (Vector*) malloc(sizeof(Vector));
  N = (Vector*) malloc(sizeof(Vector));

  if (intersection == NULL)
    return BACKGROUND;
  else 
  {
    object = intersection -> object;  
    intersection_point = intersection -> intersection_point;

    I = 0.0;
    N = object -> normal_vector_function(intersection, object);

    normalize_vector(N);
    for (current_light = scene -> lightsHead; current_light -> next != scene -> lightsTail; current_light = current_light -> next)
    {
      
      L -> x = current_light -> next -> position.x - intersection_point.x;
      L -> y = current_light -> next -> position.y - intersection_point.y;
      L -> z = current_light -> next -> position.z - intersection_point.z;

      light_distance = calculate_magnitude(*L);
      normalize_vector(L);
      
      L_point_N = dot_product(*L, *N);


      if (L_point_N > 0.0)
      {
        Fatt = min(1.0, 1/(current_light -> next -> c1 + (current_light -> next -> c2 * light_distance) + (current_light -> next -> c3 * pow(light_distance, 2))));
        I += (L_point_N * object -> diffuse_coefficient * Fatt * current_light -> next -> intensity);
      }
    
    }

    I += scene -> ambient_lighting * object -> ambient_lighting_coefficient;
    I = min(I, 1.0);

    if (intersection -> object -> texture == NULL)
      color = intersection -> object -> color;
    else
      color = get_texture_RGB(intersection);

    new_color -> r = color -> r * I;
    new_color -> g = color -> g * I;
    new_color -> b = color -> b * I;

    return new_color;
  }

}

Intersection * first_intersection (Vector eye, Vector parametricEye)
{
  Intersection* intersection;
  long double tmin;
  Intersection * first_intersection;
  Object* current;
  Object* object;

  intersection = NULL;
  tmin = INFINITY;

  for (current = scene -> objectsHead; current -> next != scene -> objectsTail; current = current -> next)
  {
    object = current -> next;
    first_intersection = object -> intersection_function(eye, parametricEye, object);

    if (first_intersection != NULL && first_intersection -> t < tmin)
    {

      tmin = first_intersection -> t;
      intersection = first_intersection;
    }
  }

  return intersection;
}


Intersection * intersection_sphere(Vector eye, Vector tVector, Object *sphereOject)
{
  long double intersection_1;
  long double intersection_2;

  double beta; 
  double gamma;

  long double discriminate;

  long double distance = mag_aux;

  Vector intersection_point;
  Intersection * intersection;

  Sphere * sphere_object = (Sphere*) sphereOject -> object;
  intersection = (Intersection*) malloc(sizeof(Intersection));

  
  beta = 2*(
            tVector.x * (eye.x - sphere_object -> center.x) + 
            tVector.y * (eye.y - sphere_object -> center.y) + 
            tVector.z * (eye.z - sphere_object -> center.z)
          );

  gamma = pow(eye.x - sphere_object -> center.x, 2) + 
          pow(eye.y - sphere_object -> center.y, 2) + 
          pow(eye.z - sphere_object -> center.z, 2) - 
          pow(sphere_object -> radius, 2);

  //printf("%.2f\n", beta*beta - 4*gamma);

  discriminate = beta*beta - 4*gamma;
  //printf("%.2f - %.2f\n",  beta, gamma);
  if (discriminate < 0.0)
  {
    intersection = NULL;
  }
  else
  {
    discriminate = sqrt(discriminate);
    intersection_1 = (-beta + discriminate)/2;
    intersection_2 = (-beta - discriminate)/2;
    
    if (intersection_2 < intersection_1)
    {
      long double inter_aux = intersection_1;
      intersection_1 =  intersection_2;
      intersection_2 = inter_aux;
    }
    intersection_point.x = eye.x + intersection_1 * tVector.x;
    intersection_point.y = eye.y + intersection_1 * tVector.y;
    intersection_point.z = eye.z + intersection_1 * tVector.z;

    intersection =  new_intersection(sphereOject, intersection_1, intersection_point);
    //printf("NTRA");
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


Vector map_framebuffer_to_window(long double x, long double y)
{
  Vector window_point;

  window_point.x = (x + 0.5) * (window.xmax - window.xmin) / Hresolution + window.xmin;
  window_point.y = (y + 0.5) * (window.ymax - window.ymin) / Vresolution + window.ymin;
  window_point.z = 0.0;

  return window_point;
}

void ray_tracer()
{

  Vector window_point;
  Vector tVector;
  RGB * color;  
  for (int i = 0; i < Vresolution; i++)
  {
    for (int j = 0; j < Hresolution; j++)
    {
     window_point = map_framebuffer_to_window(j, i);


      tVector.x = window_point.x - scene -> eye.x;
      tVector.y = window_point.y - scene -> eye.y;
      tVector.z = window_point.z - scene -> eye.z;
     
      normalize_vector(&tVector);
      color = what_color(scene -> eye, tVector);
      framebuffer[i][j] = *color;
      
    }
  }

  write_AVS(framebuffer, "Imagen.avs", Vresolution, Hresolution);
  system("convert Imagen.avs PNG:Imagen.png");
  system("display Imagen.avs");
}



