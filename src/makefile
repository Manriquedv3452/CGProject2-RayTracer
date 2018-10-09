OBJECTS=rayTracer.o
OUTPUT=rayTracer
FNAME=main.c
FLEXNAME=flex.l
FLEXOUTPUT=lex.yy.c
BISONNAME=bison.y
BISONOUTPUT=y.tab.c

SCANNER=scanner.c
GETTOKEN = getToken.c

CFLAGS=-I/usr/local/Mesa-18.1.5/include
#LDLIBS=-lX11 -lglut -lMesaGLU -lMesaGL -lm -lXext -lXmu
#LDLIBS=-lX11-lglut -lGLU -lGL -lm -lXext -lXmu
LDLIBS =  -lm -lfl -ly -ll
LDFLAGS=-L/usr/local/Mesa-18.1.5/lib -L/usr/include/X11/Xlib.h
#cc $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OUTPUT) $(OBJECTS)

$(OUTPUT): $(OBJECTS)
	flex $(FLEXNAME)
	bison -yd $(BISONNAME)
	cc  $(FNAME) $(SCANNER) $(GETTOKEN) $(FLEXOUTPUT) $(BISONOUTPUT) $(LDLIBS) -o $(OUTPUT)

$(OBJECTS): structs.h

clean:
	rm -f *.o
	rm -f $(OUTPUT)
