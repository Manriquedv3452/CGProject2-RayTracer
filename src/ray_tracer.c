#include "ray_tracer.h"
#include "vector.h"
#include "image.c"
#include "textures.c"

long double mag_aux;

RGB* what_color(Vector eye, Vector parametric)
{
  RGB * color;
  Intersection * intersection = first_intersection(eye, parametric);

  if (intersection == NULL)
    color = BACKGROUND;
  else
  {
   if (intersection -> object -> texture == NULL)
      color = intersection -> object -> color;
   else
     color = get_texture_RGB(intersection);
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


  Sphere * sphere = (Sphere*) sphereOject -> object;
  intersection = (Intersection*) malloc(sizeof(Intersection));

  beta = 2*(
            tVector.x * (eye.x - sphere -> center.x) + 
            tVector.y * (eye.y - sphere -> center.y) + 
            tVector.z * (eye.z - sphere -> center.z)
          );

  gamma = pow(eye.x - sphere -> center.x, 2) + 
          pow(eye.y - sphere -> center.y, 2) + 
          pow(eye.z - sphere -> center.z, 2) - 
          pow(sphere -> radius, 2);

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
}

void insert_object(Object *object, Scene * pScene)
{
  Object *obj_aux = pScene -> objectsTail -> previous;

  pScene -> objectsTail -> previous = object;
  obj_aux -> next = object;
  object -> previous = obj_aux;
  object -> next = pScene -> objectsTail;

  //free(obj_aux);

}

