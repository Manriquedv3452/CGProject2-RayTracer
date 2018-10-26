#include "vector.h"

Intersection * intersection_polygon(Vector *eye, Vector *tVector, Object *polygonOject);
Vector * polygon_normal_vector(Intersection * intersection, Object* object);

Intersection * intersection_polygon(Vector *eye, Vector *direction, Object *polygonOject){
  long double intersection_1;

  Vector

  double numerator;
  double denominator;
  double norm;

  Vector intersection_point;
  Intersection * intersection;

  Polygon * polygon_object = (Polygon*) polygonOject -> object;
  intersection = (Intersection*) malloc(sizeof(Intersection));

  A = cross_product().x;
  B = cross_product().y;
  C = cross_product().z;

  D = -(A * point.x + B * point.y + C * point.z);

  norm = sqrt(power_int(A, 2) + power_int(B, 2) + power_int(C, 2))

  numerator = (A * eye -> x + B * eye -> y + C * eye -> z + D);
  denominator = (A * direction -> x + B * direction -> y + C * direction -> z);

  if (denominator == 0) {
      intersection = NULL;
  }
  else{
      intersection_1 = -(numerator / denominator);

      intersection_point.x = eye -> x + intersection_1 * direction -> x;
      intersection_point.y = eye -> y + intersection_1 * direction -> y;
      intersection_point.z = eye -> z + intersection_1 * direction -> z;

      intersection =  new_intersection(polygonOject, intersection_1, intersection_point);
  }

  if (A > B && A > C) {
      point.x = 0;
  } else {
    if (B > A && B > C) {
      point.y = 0;
    } else {
      if (C > A && C > B) {
          point.z = 0;
      }
    }
  }

  return intersection;
}

Vector * Polygon_normal_vector(Intersection * intersection, Object* object){
  Polygon* polygon_object = (Polygon*) object -> object;
  Vector * normal_vector = (Vector*) malloc(sizeof(Vector));

  normal_vector -> x = (intersection -> intersection_point.x - polygon_object -> center.x) / polygon_object -> radius;
  normal_vector -> y = (intersection -> intersection_point.y - polygon_object -> center.y) / polygon_object -> radius;
  normal_vector -> z = (intersection -> intersection_point.z - polygon_object -> center.z) / polygon_object -> radius;

  return normal_vector;
}
