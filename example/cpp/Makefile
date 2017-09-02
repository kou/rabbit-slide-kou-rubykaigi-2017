fibonacci: fibonacci.cpp
	g++ -o $@ $<

tensor: tensor.cpp
	g++ -o $@ $(pkg-config --cflags --libs xtensor) $<
