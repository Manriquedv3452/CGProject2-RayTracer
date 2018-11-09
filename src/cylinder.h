Intersection * intersection_cylinder(Vector *eye, Vector *tVector, Object *cylinderOject);
Vector * cylinder_normal_vector(Intersection * intersection, Object* object);

Intersection * intersection_cylinder(Vector *eye, Vector *direction, Object *cylinderOject)
{
    long double intersection_1;
    long double intersection_2;

    double alpha;
    double beta; 
    double gamma;
    double p1;
    double p2;
        
    long double discriminate;

    Vector intersection_point;
    Intersection * intersection;

    Cylinder * cylinder_object = (Cylinder*) cylinderOject -> object;
    intersection = (Intersection*) malloc(sizeof(Intersection));

    
    Vector x;
    x.x = eye -> x - cylinder -> anchor -> x;
    x.y = eye -> y - cylinder -> anchor -> y;
    x.z = eye -> z - cylinder -> anchor -> z;


    alpha = power_int(direction -> x, 2) +
            power_int(direction -> y, 2) +
            power_int(direction -> z, 2) -
            power_int((direction -> x * cylinder -> axis -> x + direction -> y * cylinder -> axis -> y + direction -> z * cylinder -> axis -> z), 2);

    beta = 2.0*(
                dot_product(*direction, x) - dot_product(*direction, *cylinder -> axis) * dot_product(x, *cylinder -> axis)

            );

   gamma = dot_product(x, x) - power_int(dot_product(x, *cylinder -> axis), 2) - cylinder -> radius * cylinder -> radius;

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

        intersection =  new_intersection(cylinderOject, intersection_1, intersection_point);

        Vector edge;
        edge.x = intersection_point.x - cylinder -> anchor -> x;
        edge.y = intersection_point.y - cylinder -> anchor -> y;
        edge.z = intersection_point.z - cylinder -> anchor -> z;

        double distance = dot_product(edge, *cylinder -> axis);

        double m = distance / calculate_magnitude(*cylinder -> axis);

        if (m >= cylinder -> d1 && m <= cylinder -> d2)
        {
            intersection -> t = intersection_1;

        }
        else
        {
            intersection_point.x = eye -> x + intersection_2 * direction -> x;
            intersection_point.y = eye -> y + intersection_2 * direction -> y;
            intersection_point.z = eye -> z + intersection_2 * direction -> z;
            intersection -> intersection_point = intersection_point;

            edge.x = intersection_point.x - cylinder -> anchor -> x;
            edge.y = intersection_point.y - cylinder -> anchor -> y;
            edge.z = intersection_point.z - cylinder -> anchor -> z;


            double distance = dot_product(edge, *cylinder -> axis);

            double m = distance / calculate_magnitude(*cylinder -> axis);

            if (m >= cylinder -> d1 && m <=  cylinder -> d2)
            {
                intersection -> t = intersection_2;

            }
            else
            {
                intersection = NULL;
            }
        }

    }

    return intersection;
}

Vector * cylinder_normal_vector(Intersection * intersection, Object* object)
{
   
    Vector *normal_vector = (Vector*) malloc(sizeof(Vector));

    Cylinder * cylinder_object = (Cylinder*) object -> object;

    long double p, px, py, pz;

    p = (intersection -> intersection_point.x - cylinder_object -> anchor -> x) * cylinder_object -> axis -> x + 
        (intersection -> intersection_point.y - cylinder_object -> anchor -> y) * cylinder_object -> axis -> y +
        (intersection -> intersection_point.z - cylinder_object -> anchor -> z) * cylinder_object -> axis -> z;

    px = 2 * ((cylinder_object -> anchor -> x * cylinder_object -> axis -> x) -
            intersection -> intersection_point.x);

    py = 2 * ((cylinder_object -> anchor -> y * cylinder_object -> axis -> y) -
            intersection -> intersection_point.y);

    pz = 2 * ((cylinder_object -> anchor -> z * cylinder_object -> axis -> z) -
            intersection -> intersection_point.z);


    normal_vector -> x = px * (power_int(cylinder_object -> axis -> x, 2) - 1) +
                        py * (cylinder_object -> axis -> x * cylinder_object -> axis -> y) + 
                        pz * (cylinder_object -> axis -> x * cylinder_object -> axis -> z);


    normal_vector -> y = px * (cylinder_object -> axis -> y * cylinder_object -> axis -> x) +
                py * (power_int(cylinder_object -> axis -> y, 2) - 1) + 
                pz * (cylinder_object -> axis -> y * cylinder_object -> axis -> z);



    normal_vector -> z =  px * (cylinder_object -> axis -> z * cylinder_object -> axis -> x) +
                py * (cylinder_object -> axis -> z * cylinder_object -> axis -> y) + 
                pz * (power_int(cylinder_object -> axis -> z, 2) - 1);

            

    return normal_vector;
}
