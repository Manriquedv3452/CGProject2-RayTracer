typedef struct {
  long double r;
  long double g;
  long double b;
} RGB;

typedef struct 
{
	long double x;
	long double y;
	long double z;
} Vector;

typedef struct objectList{
	struct objectArray *next;
	struct objectArray *previous;
	struct object *object;
} objectList;

typedef struct
{
	long double u;
	long double v;
} Texel_Coord;

typedef struct 
{
	int width;
	int height;
	RGB** texels;

} Texture;


typedef struct Intersection Intersection;

typedef struct object{
	struct object *next;
	struct object *previous;
	RGB *color;
	Intersection* (*intersection_function) (Vector, Vector, struct object*);
	Texel_Coord * (*mapping_texture_function) (Intersection *);
	Vector * (*normal_vector_function) (Intersection *, struct object*);
	void *object;
	Texture * texture;
	long double diffuse_coefficient;
	long double ambient_lighting_coefficient;

} Object;

struct Intersection 
{
  Object * object;
  Vector intersection_point;
  long double t;
};

typedef struct sphere{
    long double radius;
    Vector center;
} Sphere;

typedef struct 
{
	Vector origin;
	Vector direction;
} Ray;

typedef struct light
{
	struct light *next;
	struct light *previous;
	Vector position;
	long double intensity;
	RGB* color;
	long double c1, c2, c3;
} Light;

typedef struct
{
	long double xmin;
	long double ymin;
	long double xmax;
	long double ymax;
} Window;

typedef struct 
{
	Vector eye;
	RGB* background;
	
	Light *lightsHead;
	Light *lightsTail;

	Object* objectsHead;
	Object* objectsTail;

	int objects_amount;
	int lights_amount;
	long double ambient_lighting;
} Scene;

typedef enum token_types{
	CONSTANT = 203
} TokenType;


Scene *scene;
Object *current_object;
Light *light_aux; 
Sphere *sphere;
Window window;
RGB **framebuffer;

#define Hresolution 1008
#define Vresolution 567
#define PI 3.141592653589793
