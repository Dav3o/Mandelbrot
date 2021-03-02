CC := g++ 
FILES := Mandelbrotset Complex_numbers Imag
Obj := $(addsuffix .o,$(FILES))

prog: $(Obj)
	$(CC) -o prog $(Obj)

clean: $(Obj)
	rm -f $(Obj) 

$(Obj): %.o : %.cpp 
	g++ -c $< -o $@



