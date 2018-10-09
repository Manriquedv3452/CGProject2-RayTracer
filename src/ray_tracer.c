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

void ray_tracer(void)
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


int main(int argc, char *argv[])
{
  framebuffer = calloc(Vresolution, sizeof(RGB));
  for (int i = 0; i < Vresolution; i++)
  {
    framebuffer[i] = calloc(Hresolution, sizeof(RGB));
  }

  window.xmin = 0;
  window.ymin = 0;
  window.xmax = 1008;
  window.ymax = 567;

  BACKGROUND = (RGB*) malloc(sizeof(RGB));
  BACKGROUND -> r = 0.2;
  BACKGROUND -> g = 0.2;
  BACKGROUND -> b = 0.2;

     Vector eye;
  eye.x = 504;
  eye.y = 283;
  eye.z = -2000;

  Vector s_center;
  s_center.x = 504;
  s_center.y = 283;
  s_center.z = 1600;

  Sphere *sphere = (Sphere*) malloc(sizeof(Sphere));
  sphere -> center = s_center;
  sphere -> radius = 300;

  RGB*color = (RGB*) malloc(sizeof(RGB));
  color -> r = 0;
  color -> g = 1;
  color -> b = 0;

  Object *new_object = (Object*) malloc(sizeof(Object));
  new_object -> color = color;
  new_object -> intersection_function = &intersection_sphere;
  new_object -> object = sphere;
  new_object -> texture = load_texture_from_AVS("textures/bright.avs");
  new_object -> mapping_texture = &map_sphere;


  Vector s_center2;
  s_center2.x = 252;
  s_center2.y = 283;
  s_center2.z = 1000;

  Sphere *sphere2 = (Sphere*) malloc(sizeof(Sphere));
  sphere2 -> center = s_center2;
  sphere2 -> radius = 60;

  RGB*color2 = (RGB*) malloc(sizeof(RGB));
  color2 -> r = 1;
  color2 -> g = 0;
  color2 -> b = 0;

  Object *new_object2 = (Object*) malloc(sizeof(Object));
  new_object2 -> color = color2;
  new_object2 -> intersection_function = &intersection_sphere;
  new_object2 -> object = sphere2;
  new_object2 -> texture = load_texture_from_AVS("textures/fireEyeElliptical.avs");
  new_object2 -> mapping_texture = &map_sphere;

  scene = new_scene(eye);
  insert_object(new_object);
  insert_object(new_object2);

  ray_tracer();

	return 1;
}

void insert_object(Object *object)
{
  Object *obj_aux = scene -> objectsTail -> previous;

  scene -> objectsTail -> previous = object;
  obj_aux -> next = object;
  object -> previous = obj_aux;
  object -> next = scene -> objectsTail;

  //free(obj_aux);

}

