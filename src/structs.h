typedef struct {
  double r;
  double g;
  double b;
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


typedef struct Intersection Intersection;

typedef struct object{
	struct object *next;
	struct object *previous;
	RGB *color;
	Intersection* (*intersection_function) (Vector, Vector, struct object*);
	void *object;
	

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
	Object* objectsHead;
	Object* objectsTail;
	int amountObjects;

} Scene;

typedef enum token_types{
	CONSTANT = 203
} TokenType;

typedef enum {
	SPHERE = 1
} ObjectKind;



RGB *BACKGROUND;
Scene *scene;
Window window;
RGB **framebuffer;

#define Hresolution 1008
#define Vresolution 1008
