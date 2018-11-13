Intersection * intersection_cone(Vector *eye, Vector *tVector, Object *coneObject);
Vector * cone_normal_vector(Intersection * intersection, Object* object);

Intersection * intersection_cone(Vector *eye, Vector *direction, Object *coneObject)
{
    long double intersection_1;
    long double intersection_2;

    double alpha;
    double beta; 
    double gamma;
        
    long double discriminate;

    Vector intersection_point;
    Intersection * intersection;

    Cone * cone_object = (Cone*) coneObject -> object;
    intersection = (Intersection*) malloc(sizeof(Intersection));

    
    Vector x;
    x.x = eye -> x - cone_object -> anchor -> x;
    x.y = eye -> y - cone_object -> anchor -> y;
    x.z = eye -> z - cone_object -> anchor -> z;

    alpha = power_int(direction -> x, 2) +
            power_int(direction -> y, 2) +
            power_int(direction -> z, 2) -
            ((1 + cone_object -> angle * cone_object -> angle)*
            pow(dot_product(*direction, *cone_object -> axis), 2));

       
    //printf("%.2f\n", (float) cone_object ->  axis -> x);

    beta = 2.0*(
                dot_product(*direction, x) - 
                ((1 + cone_object -> angle * cone_object -> angle)*
                dot_product(*direction, *cone_object -> axis) * dot_product(x, *cone_object -> axis))

            );

   gamma = dot_product(x, x) - 
    ((1 + cone_object -> angle * cone_object -> angle)*
   power_int(dot_product(x, *cone_object -> axis), 2));


    discriminate = (beta*beta - 4*alpha*gamma);
    if (discriminate < EPSILON)
    {
        intersection = NULL;
    }
    else
    {
        discriminate = sqrt(discriminate);
        intersection_1 = (-1 * beta + discriminate)/2;
        intersection_2 = (-1 * beta - discriminate)/2;
        
        if (intersection_2 < intersection_1)
        {
        long double inter_aux = intersection_1;
        intersection_1 =  intersection_2;
        intersection_2 = inter_aux;
        }
        intersection_point.x = eye -> x + intersection_1 * direction -> x;
        intersection_point.y = eye -> y + intersection_1 * direction -> y;
        intersection_point.z = eye -> z + intersection_1 * direction -> z;

        intersection =  new_intersection(coneObject, intersection_1, intersection_point);

        Vector edge;
        edge.x = intersection_point.x - cone_object -> anchor -> x;
        edge.y = intersection_point.y - cone_object -> anchor -> y;
        edge.z = intersection_point.z - cone_object -> anchor -> z;

        double distance = dot_product(edge, *cone_object -> axis);

        double m = distance / calculate_magnitude(*cone_object -> axis);

        intersection -> m = m;
        if (m >= cone_object -> d1 && m <= cone_object -> d2)
        {
            intersection -> t = intersection_1;

        }
        else
        {
            intersection_point.x = eye -> x + intersection_2 * direction -> x;
            intersection_point.y = eye -> y + intersection_2 * direction -> y;
            intersection_point.z = eye -> z + intersection_2 * direction -> z;
            intersection -> intersection_point = intersection_point;

            edge.x = intersection_point.x - cone_object -> anchor -> x;
            edge.y = intersection_point.y - cone_object -> anchor -> y;
            edge.z = intersection_point.z - cone_object -> anchor -> z;


            double distance = dot_product(edge, *cone_object -> axis);

            m = distance / calculate_magnitude(*cone_object -> axis);

            if (m >= cone_object -> d1 && m <=  cone_object -> d2)
            {
                intersection -> t = intersection_2;
                intersection -> m = m;
            }
            else
            {
                intersection = NULL;
            }
        }

    }

    return intersection;
}

Vector * cone_normal_vector(Intersection * intersection, Object* object)
{
   
    Vector *normal_vector = (Vector*) malloc(sizeof(Vector));

    Cone * cone_object = (Cone*) object -> object;

    normal_vector -> x = intersection -> intersection_point.x - cone_object -> anchor -> x -
                    (1 + cone_object -> angle * cone_object -> angle) * cone_object -> axis -> x *
                    intersection -> m;

    normal_vector -> y = intersection -> intersection_point.y - cone_object -> anchor -> y -
                (1 + cone_object -> angle * cone_object -> angle) * cone_object -> axis -> y *
                intersection -> m;

    normal_vector -> z = intersection -> intersection_point.z - cone_object -> anchor -> z -
                    (1 + cone_object -> angle * cone_object -> angle) * cone_object -> axis -> z *
                    intersection -> m;

    return normal_vector;
}
