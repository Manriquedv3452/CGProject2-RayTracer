#include "ray_tracer.h"

RGB* what_color(Vector *eye, Vector *direction)
{
  RGB * color;
  RGB *new_color = (RGB*) malloc(sizeof(RGB));
  Intersection * intersection = first_intersection(eye, direction);
  Intersection* obstacle;
  Vector *L;
  Vector *N;
  Vector *V;
  Vector *R;
  Vector intersection_point;
  long double I;
  long double E;
  Object* object;
  Vector light_intersection;
  long double N_dot_L;
  long double V_dot_R;
  Light* current_light;
  long double light_distance;

  long double Fatt; //atenation factor

  L = (Vector*) malloc(sizeof(Vector));
  N = (Vector*) malloc(sizeof(Vector));
  V = (Vector*) malloc(sizeof(Vector));
  R = (Vector*) malloc(sizeof(Vector));


  if (intersection == NULL)
    return scene -> background;
  else 
  {
    V -> x = -direction -> x;
    V -> y = -direction -> y;
    V -> z = -direction -> z;
 
    object = intersection -> object;  
    intersection_point = intersection -> intersection_point;

    I = 0.0;
    E = 0.0;
    N = object -> normal_vector_function(intersection, object);
  

    normalize_vector(N);
    for (current_light = scene -> lightsHead; current_light -> next != scene -> lightsTail; current_light = current_light -> next)
    {
      
      L -> x = current_light -> next -> position.x - intersection_point.x;
      L -> y = current_light -> next -> position.y - intersection_point.y;
      L -> z = current_light -> next -> position.z - intersection_point.z;

      light_distance = calculate_magnitude(*L);

      normalize_vector(L);
      
      N_dot_L = dot_product(*N, *L);
      if (N_dot_L < 0.0)
      {
        N -> z = -N -> z;
        N_dot_L = dot_product(*N, *L);
      }


      
      if (N_dot_L > 0.0)
      {
        Fatt = min(1.0, 1/(
                          current_light -> next -> c1 + 
                          (current_light -> next -> c2 * light_distance) + 
                          (current_light -> next -> c3 * (light_distance * light_distance))
                          )
                  );
        obstacle = first_intersection(&intersection_point, L);
        R -> x = 2 * (N -> x * N_dot_L) - L -> x;
        R -> y = 2 * (N -> y * N_dot_L) - L -> y;
        R -> z = 2 * (N -> z * N_dot_L) - L -> z;

        if (!obstacle || obstacle -> t > light_distance)
        {
          I += (N_dot_L * object -> diffuse_coefficient * Fatt * current_light -> next -> intensity);

          V_dot_R = dot_product(*V, *R);

          if (V_dot_R > 0.0)
          { 
            E += (power_int(V_dot_R, object -> stain_level_Kn) * object -> specular_coefficient * Fatt * current_light -> next -> intensity);
          }
        }
      }
    
    }

    I += scene -> ambient_lighting * object -> ambient_lighting_coefficient;
    I = min(I, 1.0);
    E = min(E, 1.0);

    if (intersection -> object -> texture == NULL)
      color = intersection -> object -> color;
    else
      color = get_texture_RGB(intersection);

    new_color -> r = (color -> r * I) + E * (1.0 - color -> r);
    new_color -> g = (color -> g * I) + E * (1.0 - color -> g);
    new_color -> b = (color -> b * I) + E * (1.0 - color -> b);

    return new_color;
  } 

}

Intersection * first_intersection (Vector *eye, Vector *direction)
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
    first_intersection = object -> intersection_function(eye, direction, object);

    if (first_intersection != NULL && first_intersection -> t < tmin 
          && first_intersection -> t > EPSILON)
    {

      tmin = first_intersection -> t;
      intersection = first_intersection;
    }
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
  Vector *direction;
  RGB * color;  

  direction = (Vector*) malloc(sizeof(Vector));
  for (int i = 0; i < Vresolution; i++)
  {
    for (int j = 0; j < Hresolution; j++)
    {
     window_point = map_framebuffer_to_window(j, i);


      direction -> x = window_point.x - scene -> eye -> x;
      direction -> y = window_point.y - scene -> eye -> y;
      direction -> z = window_point.z - scene -> eye -> z;
     
      normalize_vector(direction);
      color = what_color(scene -> eye, direction);
      framebuffer[i][j] = *color;
      
    }
  }

  write_AVS(framebuffer, "Imagen.avs", Vresolution, Hresolution);
  printf("Done!\n");
  system("convert Imagen.avs PNG:Imagen.png");
  system("display Imagen.avs");
}



