void create_object(int object_kind);
void load_object_colorR(char* token);
void load_object_colorG(char* token);
void load_object_colorB(char* token);
void load_object_texture(char* file_name);
void process_object(int object_kind);
void add_diffuse_coefficient(char* token);

void create_sphere(void);
void add_sphere_center_x(char* token);
void add_sphere_center_y(char* token);
void add_sphere_center_z(char* token);
void add_sphere_radius(char* token);

void create_scene(void);
void load_scene_eye_x(char* token);
void load_scene_eye_y(char* token);
void load_scene_eye_z(char* token);

void create_light(void);
void add_light_position_x(char* token);
void add_light_position_y(char* token);
void add_light_position_z(char* token);
void add_light_intensity(char* token);
void load_light_colorR(char* token);
void load_light_colorG(char* token);
void load_light_colorB(char* token);