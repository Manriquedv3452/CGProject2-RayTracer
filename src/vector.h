void normalize_vector(Vector *vector);
long double calculate_magnitude(Vector vector);
long double dot_product(Vector a, Vector b);
Vector* substract(Vector* a, Vector* b);
Vector* cross_product(Vector *destiny, Vector *origin);

long double calculate_magnitude(Vector vector)
{
  return sqrt( 
              vector.x * vector.x +
              vector.y * vector.y +
              vector.z * vector.z
            );
}

void normalize_vector(Vector *vector)
{
  long double mag = calculate_magnitude(*vector);

  vector -> x = vector -> x / mag;
  vector -> y = vector -> y / mag;
  vector -> z = vector -> z / mag;
}

long double dot_product(Vector a, Vector b)
{
    //printf("%.2f\n", (double) a.x);
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector* substract(Vector *destiny, Vector *origin){
    Vector* result = (Vector*) malloc(sizeof(Vector));
    result -> x = destiny -> x - origin -> x;
    result -> y = destiny -> y - origin -> y;
    result -> z = destiny -> z - origin -> z;

    //printf("%.2f\n", (double) result -> x);
    return result;
}

Vector* cross_product(Vector *a, Vector *b){
    Vector* product = (Vector*) malloc(sizeof(Vector));
    product -> x = (a -> y * b -> z) - (a -> z * b -> y);
    product -> y = (a -> z * b -> x) - (a -> x * b -> z);
    product -> z = (a -> x * b -> y) - (a -> y * b -> x);

    //printf("%.2f * %.2f - %.2f * %.2f\n", 
     //s   (double) a -> x, (double) b ->y, (double) a -> y, (double) b -> x);

    return product;
}
