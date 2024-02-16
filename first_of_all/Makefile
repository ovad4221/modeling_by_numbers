GMSH_INCLUDE_PATH=/usr/include
GMSH_LIB_PATH=/usr/lib


samples:
	for number in 1 2 3 4; do \
		g++ -I$(GMSH_INCLUDE_PATH) -L$(GMSH_LIB_PATH) sample0$$number.cpp -lgmsh -o sample0$$number; \
	
	done

cube:
	g++ -I$(GMSH_INCLUDE_PATH) -L$(GMSH_LIB_PATH) cube.cpp -lgmsh -o cube; \
	done

circle:
	g++ -I$(GMSH_INCLUDE_PATH) -L$(GMSH_LIB_PATH) cube.cpp -lgmsh -o cube; \
	done

clean:
	rm -f *msh
