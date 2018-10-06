typedef struct {
  double r;
  double g;
  double b;
} COLOR;

typedef struct objectList{
	struct objectArray *next;
	struct objectArray *previous;
	struct object *object;
} objectList;

typedef struct object{
	struct object *next;
	struct object *previous;
	void* objectKind;

} Object;

typedef struct sphere{
    float radio;
    POINT centro;
    COLOR color;
} Sphere;

typedef enum token_types{
	CONSTANT = 203
} TokenType;
