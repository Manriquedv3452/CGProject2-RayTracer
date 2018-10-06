#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

struct​ ​ INTERSECTION​ * First_Intersection (​ struct​ ​ VECTOR​ a, ​ struct VECTOR​ d){
  int i, a, b, c, discriminante, t, t1, t2;
  struct​ ​ INTERSECTION​ * interseccion;
  long double​ tmin;
  interseccion = ​ NULL​ ;
  //tmin = + ∞ ;
  //∀ objeto en la escena
  for(i = 0; i < cantObjetos; i++){
    a = xd^2 + yd^2 + zd^2;
    b = 2((xe − xc) + (ye − yc) + (ze − zc));
    c = (xe − xc)^2 + (ye − yc)^2 + (ze − zv)^2 − R^2;
    discriminante = b^2 - 4 * c;
    if (discriminante < 0) {
      printf("No tiene soluciones reales\n");
    }else if (discriminante > 0) {
      printf("Tiene dos soluciones\n");
      t1 = (-b - sqrt(discriminante)) / 2;
      t2 = (-b + sqrt(discriminante)) / 2;
    } else{
      printf("Tiene una solución\n");
      t = (-b + sqrt(discriminante)) / 2;
    }

    //a * t^2 + b * t + c = 0;

    calcular intersección entre rayo y​ objeto;
    //Si​ hay interseccion​ y distancia al objeto < tmin
    if(t || t1 || t2 && ){
      tmin = distancia a intersección;
      if (/* condition */) {
        /* code */
      }
      interseccion = interseccion con objeto;
    }
  }
  return​ (interseccion);
}

struct​ ​ RGB​ * De_que_color (​ struct​ ​ VECTOR​ a, ​ struct ​ VECTOR​ d){
  struct​ RGB​ * color;
  struct​ INTERSECTION​ * interseccion;
  interseccion = ​ First_Intersection​ (a, d);
  if​ (!interseccion)
    color = BACKGROUND
  else
    color = interseccion -> objeto.color;
  return​ (color);
}

for(int​ i = 0; i < ​ Hres​ ; i++){
  for​ (​ int​ j = 0; j < ​ Vres​ ; j++){
    xw = (i + (1/2)) * (xmax - xmin) / Hres + xmin;
    yw = (j + (1/2)) * (ymax - ymin) / Hres + ymin;
    zw = 0.0;
    L = sqrt((xw - xe)^2 + (yw - ye)^2 + (zw - ze)^2);
    xd = (xw - xe) / L;
    yd = (yw - ye) / L;
    zd = (zw - ze) / L;
    color = De_que_color((xe,ye,ze), [xd,yd,zd]);
    FrameBuffer[i][j] = color;
  }
} Save_file​ (FrameBuffer);
