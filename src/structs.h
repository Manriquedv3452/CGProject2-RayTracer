
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
} VectorUV;


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
	Intersection* (*intersection_function) (Vector*, Vector*, struct object*);
	VectorUV * (*mapping_texture_function) (Intersection *);
	Vector * (*normal_vector_function) (Intersection *, struct object*);
	void *object;
	Texture * texture;
	long double diffuse_coefficient;
	long double ambient_lighting_coefficient;
	long double specular_coefficient;
	int stain_level_Kn;
	int mirror_active;

} Object;

struct Intersection
{
  Object * object;
  Vector intersection_point;
  long double t;
  long double m;
};

typedef struct sphere{
    long double radius;
    Vector center;
	Vector vectorG;
} Sphere;

typedef struct plane{
    long double A;
    long double B;
    long double C;
    long double D;
} Plane;

typedef struct points
{
	struct points* next;
	struct points* previous;
	Vector* point;
} Points;

typedef struct rectangle
{
	Vector point0;
	Vector point1;
	Vector point2;
	Vector point3;

	long double length;
	long double height;

	Vector vectorLength;
	Vector vectorHeight;

} Rectangle;

typedef struct polygon{
    Points* points_head;
	Points* points_tail;
	int points_number;
    Plane* plane;
	VectorUV** flat_points;
	Rectangle poly_rectangle;
	Vector* Normal;
} Polygon;

typedef struct cylinder
{
	long double radius;
	long double d1, d2;
	Vector* axis;
	Vector* anchor;
	Vector vectorG;

} Cylinder;

typedef struct cone
{
	long double angle;
	long double d1, d2;
	Vector* axis;
	Vector* anchor;
	Vector vectorG;
} Cone;

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
	Vector *eye;
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
Window window;
RGB **framebuffer;

Vector* actual_point;
//objects
Sphere *sphere;
Polygon *polygon;
Cylinder *cylinder;
Cone *cone;

#define Hresolution 1008
#define Vresolution 567
#define PI 3.141592653589793
#define EPSILON 0.0005
