#include <set>
#include "gmsh.h"

typedef gmsh::model::geo gmsh_geo;

int main(int argc, char **argv) {
    gmsh::initialize();

    gmsh::model::add("cube");

    double lc = 1e-1;

    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(1, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(0, 1, 0, lc, 3);

    gmsh_geo::addCircleArc(1, 2, 3);

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("cube.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}