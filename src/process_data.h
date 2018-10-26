void create_object(int object_kind);
void load_object_colorR(char* token);
void load_object_colorG(char* token);
void load_object_colorB(char* token);
void load_object_texture(char* file_name);
void process_object(int object_kind);
void add_diffuse_coefficient(char* token);
void add_ambient_lighting_coefficient(char* token);
void add_specular_coefficient(char* token);
void add_object_kn(char* token);

void create_sphere(void);
void add_sphere_center_x(char* token);
void add_sphere_center_y(char* token);
void add_sphere_center_z(char* token);
void add_sphere_radius(char* token);

void create_new_point(void);
void create_polygon(void);
void add_polygon_point_x(char* token);
void add_polygon_point_y(char* token);
void add_polygon_point_z(char* token);
void insert_polygon_point(void);

void create_scene(void);
void add_ambient_lighting(char* token);
void load_scene_eye_x(char* token);
void load_scene_eye_y(char* token);
void load_scene_eye_z(char* token);
void add_background_colorR(char* token);
void add_background_colorG(char* token);
void add_background_colorB(char* token);

void create_light(void);
void add_light_position_x(char* token);
void add_light_position_y(char* token);
void add_light_position_z(char* token);
void add_light_intensity(char* token);
void load_light_colorR(char* token);
void load_light_colorG(char* token);
void load_light_colorB(char* token);
void add_light_c1(char* token);
void add_light_c2(char* token);
void add_light_c3(char* token);
