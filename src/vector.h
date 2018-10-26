void normalize_vector(Vector *vector);
long double calculate_magnitude(Vector vector);
long double dot_product(Vector a, Vector b);

long double calculate_magnitude(Vector vector)
{
  return sqrt(
              pow(vector.x, 2) +
              pow(vector.y, 2) +
              pow(vector.z, 2)
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

Vector substract(Vector a; Vector b){
    Vector product;
    product.x = a.x - b.x;
    product.y = a.y - b.y;
    product.z = a.z - b.z;
    return product;
}

Vector cross_product(Vector a; Vector b){
    Vector product;
    product.x = a.y * b.z - a.z * b.y;
    product.y = a.z * b.x - a.x * b.z;
    product.z = a.x * b.y - a.y * b.x;
    return product;
}
