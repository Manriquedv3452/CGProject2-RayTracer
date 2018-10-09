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
    return (a.x * b.x + a.y*b.y + a.z * b.z);
}