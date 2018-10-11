void end_expression(void)
{
    if (current_token_code == I_CONSTANT)
        printf("%s\n", current_token);
    
    printf("%s -%d - %d\n", current_token, current_token_code, SCENE);
}

void create_object(int object_kind)
{
    current_object = (Object*) malloc(sizeof(Object));
    current_object -> color = (RGB*) malloc(sizeof(RGB));
    load_object_colorR("1");
    load_object_colorG("0");
    load_object_colorB("0");
    current_object -> texture = NULL;
    switch (object_kind)
    {
        case SPHERE:
            current_object -> intersection_function = &intersection_sphere;
            current_object -> mapping_texture_function = &map_sphere;
            current_object -> normal_vector_function = &sphere_normal_vector;
            break;

        default:
            printf("ERROR\n");
            break;      
    }
}

void add_diffuse_coefficient(char* token)
{
    current_object -> diffuse_coefficient = atof(token);
}

void load_object_texture(char* file_name)
{
    current_object -> texture = load_texture_from_AVS(file_name);
}

void load_object_colorR(char* token)
{
    current_object -> color -> r = atof(token);
}
void load_object_colorG(char* token)
{
    current_object -> color -> g = atof(token);
}
void load_object_colorB(char* token)
{
    current_object -> color -> b = atof(token);
}

void process_object(int object_kind)
{
    switch(object_kind)
    {
        case SPHERE:
               current_object -> object = sphere;
               break;
        default:
            printf("ERROR\n");
            break;
    }
}
void create_sphere(void)
{
    sphere = (Sphere *) malloc(sizeof(Sphere));
    sphere -> center.x = 0;
    sphere -> center.y = 0;
    sphere -> center.z = 0;
    sphere -> radius = 0;
}


void add_sphere_center_x(char* token)
{
     sphere -> center.x = atof(token);
}
void add_sphere_center_y(char* token)
{
     sphere -> center.y = atof(token);
}
void add_sphere_center_z(char* token)
{
     sphere -> center.z = atof(token);
}

void add_sphere_radius(char* token)
{
    sphere -> radius = atof(token);
}

//LIGHT
void create_light(void)
{
    light_aux = (Light *) malloc(sizeof(Light));
    light_aux -> intensity = 0.0;
    light_aux -> position.x = 0;
    light_aux -> position.y = 0;
    light_aux -> position.z = 0;

    light_aux -> color = (RGB*) malloc(sizeof(RGB));    
    light_aux -> color -> r = 1;
    light_aux -> color -> g = 1;
    light_aux -> color -> b = 1;
}

void add_light_position_x(char* token)
{
    light_aux -> position.x = atof(token);
}

void add_light_position_y(char* token)
{
    light_aux -> position.y = atof(token);
}

void add_light_position_z(char* token)
{
    light_aux -> position.z = atof(token);
}

void add_light_intensity(char* token)
{
    light_aux -> intensity = atof(token);
}

void load_light_colorR(char* token)
{
    light_aux -> color -> r = atof(token);
}
void load_light_colorG(char* token)
{
    light_aux -> color -> g = atof(token);
}
void load_light_colorB(char* token)
{
    light_aux -> color -> b = atof(token);
}

//SCENE
void load_scene_eye_x(char* token)
{
    scene -> eye.x = atof(token);
}

void load_scene_eye_y(char* token)
{
    scene -> eye.y = atof(token);
}

void load_scene_eye_z(char* token)
{
    scene -> eye.z = atof(token);
}

void create_scene(void)
{
    framebuffer = calloc(Vresolution, sizeof(RGB));
    for (int i = 0; i < Vresolution; i++)
    {
        framebuffer[i] = calloc(Hresolution, sizeof(RGB));
    }

    window.xmin = 0;
    window.ymin = 0;
    window.xmax = 1008;
    window.ymax = 567;

    BACKGROUND = (RGB*) malloc(sizeof(RGB));
    BACKGROUND -> r = 0.1;
    BACKGROUND -> g = 0.1;
    BACKGROUND -> b = 0.1;

    scene = (Scene*) malloc(sizeof(Scene));
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
}