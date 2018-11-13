void create_object(int object_kind);
void load_object_colorR(char* token);
void load_object_colorG(char* token);
void load_object_colorB(char* token);
void load_object_texture(char* file_name);
void process_object(int object_kind);
void add_diffuse_coefficient(char* token);
void add_ambient_lighting_coefficient(char* token);
void add_specular_coefficient(char* token);
void add_mirror_level(char* token);
void activate_object_mirror(void);

void add_object_kn(char* token);
void add_object_radius(char* token);
void add_object_d1(char* token);
void add_object_d2(char* token);

void add_object_anchor_x(char* token);
void add_object_anchor_y(char* token);
void add_object_anchor_z(char* token);
void add_object_axis_x(char* token);
void add_object_axis_y(char* token);
void add_object_axis_z(char* token);

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


void create_cylinder(void);
void add_cylinder_anchor_x(char* token);
void add_cylinder_anchor_y(char* token);
void add_cylinder_anchor_z(char* token);
void add_cylinder_axis_x(char* token);
void add_cylinder_axis_y(char* token);
void add_cylinder_axis_z(char* token);
void add_cylinder_radius(char* token);
void add_cylinder_d1(char* token);
void add_cylinder_d2(char* token);

void create_cone(void);
void add_cone_anchor_x(char* token);
void add_cone_anchor_y(char* token);
void add_cone_anchor_z(char* token);
void add_cone_axis_x(char* token);
void add_cone_axis_y(char* token);
void add_cone_axis_z(char* token);
void add_cone_angle(char* token);
void add_cone_d1(char* token);
void add_cone_d2(char* token);


void create_scene(void);
void add_ambient_lighting(char* token);
void activate_antialiasing(void);
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


int current_object_type;
