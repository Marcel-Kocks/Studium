TARGET	= primzahl
OBJECTS	= primz_haupt.o primz_math.o
HEADERS	= primz_math.h
LIBS	= -lm

$(TARGET) : $(OBJECTS)
	gcc $^ $(LIBS) -o $@

primz_%.o: primz_%.c $(HEADERS)
	gcc -c $< -o $@

clean:
	rm -f $(OBJECTS) 
