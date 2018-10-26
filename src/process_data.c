void end_expression(void){
    if (current_token_code == I_CONSTANT)
        printf("%s\n", current_token);

    printf("%s -%d - %d\n", current_token, current_token_code, SCENE);
}

void create_object(int object_kind){
    current_object = (Object*) malloc(sizeof(Object));
    current_object -> color = (RGB*) malloc(sizeof(RGB));
    load_object_colorR("1");
    load_object_colorG("0");
    load_object_colorB("0");
    current_object -> texture = NULL;
    current_object -> diffuse_coefficient = 1.0;
    current_object -> ambient_lighting_coefficient = 1.0;
    current_object -> specular_coefficient = 1.0;
    current_object -> stain_level_Kn = 5;

    switch (object_kind){
        case SPHERE:
            current_object -> intersection_function = &intersection_sphere;
            current_object -> mapping_texture_function = &map_sphere;
            current_object -> normal_vector_function = &sphere_normal_vector;
            break;

        case POLYGON:
            current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;
            break;

        case CILINDER:
            /*current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;*/
            break;

        case DISC:
            /*current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;*/
            break;

        case CONE:
            /*current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;*/
            break;

        case ELIPSE:
            /*current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;*/
            break;

        case QUADRATIC:
            /*current_object -> intersection_function = &intersection_polygon;
            current_object -> mapping_texture_function = &map_polygon;
            current_object -> normal_vector_function = &polygon_normal_vector;*/
            break;

        default:
            printf("ERROR\n");
            break;
    }
}

void add_object_kn(char* token){
    current_object -> stain_level_Kn = atoi(token);
}

void add_diffuse_coefficient(char* token){
    current_object -> diffuse_coefficient = atof(token);
}

void add_ambient_lighting_coefficient(char* token){
    current_object -> ambient_lighting_coefficient = atof(token);
}
void add_specular_coefficient(char* token){
    current_object -> specular_coefficient = atof(token);
}

void load_object_texture(char* file_name){
    current_object -> texture = load_texture_from_AVS(file_name);
}

void load_object_colorR(char* token){
    current_object -> color -> r = atof(token);
}
void load_object_colorG(char* token){
    current_object -> color -> g = atof(token);
}
void load_object_colorB(char* token){
    current_object -> color -> b = atof(token);
}
_1;
  long double intersection_2;
    switch(object_kind){
        case SPHERE:
            current_object -> object = sphere;
            break;

        case POLYGON:
            current_object -> object = polygon;
            break;

        default:
            printf("ERROR\n");
            break;
    }
}

void create_sphere(void){
    sphere = (Sphere *) malloc(sizeof(Sphere));
    sphere -> center.x = 0;
    sphere -> center.y = 0;
    sphere -> center.z = 0;
    sphere -> radius = 0;
}

void add_sphere_center_x(char* token){
     sphere -> center.x = atof(token);
}
void add_sphere_center_y(char* token){
     sphere -> center.y = atof(token);
}
void add_sphere_center_z(char* token){
     sphere -> center.z = atof(token);
}

void add_sphere_radius(char* token){
    sphere -> radius = atof(token);
}

void create_polygon(void){
    polygon = (Polygon *) malloc(sizeof(Polygon));
    polygon -> point.x = 0;
    polygon -> point.y = 0;
    polygon -> point.z = 0;
}

void add_polygon_point_x(char* token){
     polygon -> point.x = atof(token);
}
void add_polygon_point_y(char* token){
     polygon -> point.y = atof(token);
}
void add_polygon_point_z(char* token){
     polygon -> point.z = atof(token);
}

//LIGHT
void create_light(void){
    light_aux = (Light *) malloc(sizeof(Light));
    light_aux -> intensity = 1.0;
    light_aux -> position.x = 0;
    light_aux -> position.y = 0;
    light_aux -> position.z = 0;

    light_aux -> color = (RGB*) malloc(sizeof(RGB));
    light_aux -> color -> r = 1;
    light_aux -> color -> g = 1;
    light_aux -> color -> b = 1;

    light_aux -> c1 = 1.0;
    light_aux -> c2 = 0.0;
    light_aux -> c3 = 0.0;
}

void add_light_position_x(char* token){
    light_aux -> position.x = atof(token);
}
void add_light_position_y(char* token){
    light_aux -> position.y = atof(token);
}
void add_light_position_z(char* token){
    light_aux -> position.z = atof(token);
}

void add_light_intensity(char* token){
    light_aux -> intensity = atof(token);
}

void load_light_colorR(char* token){
    light_aux -> color -> r = atof(token);
}
void load_light_colorG(char* token){
    light_aux -> color -> g = atof(token);
}
void load_light_colorB(char* token){
    light_aux -> color -> b = atof(token);
}

void add_light_c1(char* token){
    light_aux -> c1 = atof(token);
}
void add_light_c2(char* token){
    light_aux -> c2 = atof(token);
}
void add_light_c3(char* token){
    light_aux -> c3 = atof(token);
}

//SCENE

void add_ambient_lighting(char* token){
    scene -> ambient_lighting = atof(token);
}

void load_scene_eye_x(char* token){
    scene -> eye -> x = atof(token);
}
void load_scene_eye_y(char* token){
    scene -> eye -> y = atof(token);
}
void load_scene_eye_z(char* token){
    scene -> eye -> z = atof(token);
}

void add_background_colorR(char* token){
    scene -> background -> r = atof(token);
}
void add_background_colorG(char* token){
    scene -> background -> g = atof(token);
}
void add_background_colorB(char* token){
    scene -> background -> b = atof(token);
}

void create_scene(void){
    framebuffer = calloc(Vresolution, sizeof(RGB));
    for (int i = 0; i < Vresolution; i++){
        framebuffer[i] = calloc(Hresolution, sizeof(RGB));
    }

    window.xmin = 0;
    window.ymin = 0;
    window.xmax = 1008;
    window.ymax = 567;


    scene = (Scene*) malloc(sizeof(Scene));

    scene -> background = (RGB*) malloc(sizeof(RGB));
    scene -> background -> r = 0.2;
    scene -> background -> g = 0.2;
    scene -> background -> b = 0.2;

    scene -> objectsHead = (Object*) malloc(sizeof(Object));
    scene -> objectsTail = (Object*) malloc(sizeof(Object));

    scene -> objectsHead -> next = scene -> objectsTail;
    scene -> objectsTail -> previous = scene -> objectsHead;

    scene -> lightsHead = (Light*) malloc(sizeof(Light));
    scene -> lightsTail = (Light*) malloc(sizeof(Light));

    scene -> lightsHead -> next = scene -> lightsTail;
    scene -> lightsTail -> previous = scene -> lightsHead;

    scene -> objects_amount = 0;
    scene -> lights_amount = 0;

    scene -> ambient_lighting = 0.0;

    scene -> eye = (Vector*) malloc(sizeof(Vector));
    scene -> eye -> x = 0;
    scene -> eye -> y = 0;
    scene -> eye -> z = 0;
}
