RGB * get_texel(VectorUV * point, Texture * texture);
RGB *  get_texture_RGB(Intersection * intersection);
VectorUV * map_sphere (Intersection * intersection);

RGB * get_texel(VectorUV * point, Texture * texture){

    return &texture -> texels[llroundl(point -> v * texture -> height)][llroundl(point -> u * texture -> width)];
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


