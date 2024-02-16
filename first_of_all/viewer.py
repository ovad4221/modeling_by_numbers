import gmsh
import sys

gmsh.initialize()

gmsh.open("cube.msh")
if '-nopopup' not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()

