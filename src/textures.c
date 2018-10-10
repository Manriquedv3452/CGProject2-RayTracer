RGB * get_texel(Texel_Coord * point, Texture * texture);
RGB *  get_texture_RGB(Intersection * intersection);
Texel_Coord * map_sphere (Intersection * intersection);

RGB * get_texel(Texel_Coord * point, Texture * texture){

    return &texture -> texels[llroundl(point -> v * texture -> height)][llroundl(point -> u * texture -> width)];
}

RGB *  get_texture_RGB(Intersection * intersection){
    //UV (*functionPoint) (Object*, Vector) = object -> texture;
    Texel_Coord * mapped_texel = intersection -> object -> mapping_texture(intersection);
    return get_texel(mapped_texel, intersection -> object -> texture);
}


Texel_Coord * map_sphere (Intersection * intersection){
    Sphere* sphere = (Sphere*) intersection -> object -> object;
    Texel_Coord  *uv = (Texel_Coord*) malloc(sizeof(Texel_Coord));

    Vector normal_vector = {intersection -> intersection_point.x - sphere->center.x,
                        0,
                        intersection -> intersection_point.z - sphere->center.z};

    normalize_vector(&normal_vector);

    uv -> u = acos(normal_vector.z) / (2 * PI);
    uv -> v = (intersection -> intersection_point.y - sphere->center.y + sphere->radius)/ (2 * sphere->radius);


    return uv;
}

