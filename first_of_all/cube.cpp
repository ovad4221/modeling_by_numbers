#include <set>
#include "gmsh.h"

int main(int argc, char **argv) {
    gmsh::initialize();

    gmsh::model::add("cube");

    double lc = 1e-1;
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(1, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(0, 1, 0, lc, 3);
    gmsh::model::geo::addPoint(0, 0, 1, lc, 4);
    gmsh::model::geo::addPoint(0, 1, 1, lc, 5);
    gmsh::model::geo::addPoint(1, 0, 1, lc, 6);
    gmsh::model::geo::addPoint(1, 1, 0, lc, 7);
    gmsh::model::geo::addPoint(1, 1, 1, lc, 8);


    gmsh::model::geo::addLine(1, 2, 12);
    gmsh::model::geo::addLine(1, 3, 13);
    gmsh::model::geo::addLine(1, 4, 14);

    gmsh::model::geo::addLine(2, 6, 26);
    gmsh::model::geo::addLine(2, 7, 27);

    gmsh::model::geo::addLine(3, 7, 37);
    gmsh::model::geo::addLine(3, 5, 35);

    gmsh::model::geo::addLine(4, 6, 46);
    gmsh::model::geo::addLine(4, 5, 45);
    
    gmsh::model::geo::addLine(8, 6, 86);
    gmsh::model::geo::addLine(8, 5, 85);
    gmsh::model::geo::addLine(8, 7, 87);


    gmsh::model::geo::addCurveLoop({12, 27, -37, -13}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::addCurveLoop({12, 26, -46, -14}, 2);
    gmsh::model::geo::addPlaneSurface({2}, 2);

    gmsh::model::geo::addCurveLoop({-14, 13, 35, -45}, 3);
    gmsh::model::geo::addPlaneSurface({3}, 3);

    gmsh::model::geo::addCurveLoop({45, -85, 86, -46}, 4);
    gmsh::model::geo::addPlaneSurface({4}, 4);

    gmsh::model::geo::addCurveLoop({-85, 87, -37, 35}, 5);
    gmsh::model::geo::addPlaneSurface({5}, 5);

    gmsh::model::geo::addCurveLoop({86, -26, 27, -87}, 6);
    gmsh::model::geo::addPlaneSurface({6}, 6);


    gmsh::model::geo::addSurfaceLoop({1, 2, 3, -4, 5, -6}, 1);
    gmsh::model::geo::addVolume({1});

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("cube.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}