#include <stdio.h>
#include <stdlib.h>

int is_numeric(char character);
int verify_argument(char *argument);

extern int scanner(char* fileName);

int main(int argc, char *argv[])
{
  /*framebuffer = calloc(Vresolution, sizeof(RGB));
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
  new_object -> texture = load_texture_from_AVS("textures/darkLight.avs");
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
  new_object2 -> texture = load_texture_from_AVS("textures/eyeElliptical.avs");
  new_object2 -> mapping_texture = &map_sphere;

  scene = new_scene(eye);
  insert_object(new_object, scene);
  insert_object(new_object2, scene);*/

  scanner("description.txt");

  //ray_tracer();

	return 1;
}

//return -1 if the argument is invalid
//else return the integer value.
int verify_argument(char *argument){

    for (int i = 0; argument[i] != '\0'; i++){
        if (!is_numeric(argument[i]))
            return -1;
    }
    return atoi(argument);
}

//return 0 (False) if a char is not numeric.
int is_numeric(char character){
	if (character >= 48 && character <= 57)
		return 1;

	return 0;
}
