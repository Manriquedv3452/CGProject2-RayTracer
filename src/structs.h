typedef struct {
  double r;
  double g;
  double b;
} COLOR;

typedef struct objectArray
{
	struct objectArray *next;
	struct objectArray *previous;
	struct object *object;
} objectArray;

typedef struct object
{
	struct object *next;
	struct object *previous;
	void* objectKind;

} Object;

typedef struct sphere
{
	
} Sphere;




typedef enum token_types
{
	CONSTANT = 203
} TokenType;


