RGB * get_texel(VectorUV * point, Texture * texture);
RGB *  get_texture_RGB(Intersection * intersection);
VectorUV * map_sphere (Intersection * intersection);
VectorUV * map_cylinder(Intersection * intersection);
VectorUV * map_cone(Intersection * intersection);
VectorUV * map_rectangle(Intersection * intersection);

RGB * get_texel(VectorUV * point, Texture * texture){

    return &texture -> texels[llroundl(point -> v * (texture -> height - 1))][llroundl(point -> u * (texture -> width - 1))];
}

RGB *  get_texture_RGB(Intersection * intersection){
    //VectorUV (*functionPoint) (Object*, Vector) = object -> texture;
    VectorUV * mapped_texel = intersection -> object -> mapping_texture_function(intersection);
    return get_texel(mapped_texel, intersection -> object -> texture);
}


VectorUV * map_sphere (Intersection * intersection){
    Sphere* sphere = (Sphere*) intersection -> object -> object;
    VectorUV *vectorUV = (VectorUV*) malloc(sizeof(VectorUV));

    Vector normal_vector = {intersection -> intersection_point.x - sphere->center.x,
                        0,
                        intersection -> intersection_point.z - sphere->center.z};

    normalize_vector(&normal_vector);

    vectorUV -> u = acos(normal_vector.z) / (2 * PI);
    vectorUV -> v = (intersection -> intersection_point.y - sphere->center.y + sphere->radius)/ (2 * sphere->radius);


    return vectorUV;
}

VectorUV * map_cylinder(Intersection * intersection)
{
    Cylinder * cylinder_obj = (Cylinder*) intersection -> object -> object;

    VectorUV *vectorUV = (VectorUV*) malloc(sizeof(VectorUV));

    Vector *d = substract(&intersection -> intersection_point, cylinder_obj -> anchor);
    normalize_vector(d);

    vectorUV -> u = 0.5 + atan2(d -> z, d -> y) / PI * 0.5;
    vectorUV -> v = d -> x / PI;
    vectorUV -> v = vectorUV -> v - floor(vectorUV -> v);

    
    free(d);

    return vectorUV;
}

VectorUV * map_cone(Intersection * intersection)
{
    Cone * cone_obj = (Cone*) intersection -> object -> object;
    VectorUV *vectorUV = (VectorUV*) malloc(sizeof(VectorUV));

    Vector *d = substract(&intersection -> intersection_point, cone_obj -> anchor);
    normalize_vector(d);
    
    vectorUV -> u = 0.5 + atan2(d -> z, d -> y) / PI * 0.5;
    vectorUV -> v = d -> x / PI;
    vectorUV -> v = vectorUV -> v - floor(vectorUV -> v);
    
    if (vectorUV -> v < 0)
        vectorUV -> v *= -1;

    free(d);
    //free(normal_vector);

    return vectorUV;
}

VectorUV * map_rectangle(Intersection * intersection)
{
    Polygon* polygon_obj = (Polygon*) intersection -> object -> object;
    Rectangle rect = polygon_obj -> poly_rectangle;
    Vector inter_point = intersection -> intersection_point;
    VectorUV *vectorUV = (VectorUV*) malloc(sizeof(VectorUV));

    Vector distance = {inter_point.x - rect.point0.x, inter_point.y - rect.point0.y, inter_point.z - rect.point0.z};
  
    vectorUV -> u = dot_product(distance, rect.vectorLength) / rect.length;
    vectorUV -> v = dot_product(distance, rect.vectorHeight) / rect.height;


    return vectorUV;
}
