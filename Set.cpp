#include <iostream>
#include <set>  // When using the set container, we must include the set header file 
#include "Point2d.hpp"

int main(int argc, char *argv[])
{
    std::set<Point2d> points;   // we create a made up of instances of the class Point2d, we call the set as points
    Point2d origin(0,0);
    // insert four points into the set using the insert method associated with sets
    points.insert(origin);
    points.insert(Point2d(-2,1));
    points.insert(Point2d(-2,-5));
    points.insert(Point2d(0,0)); // the origin and the point (0, 0)—are identical, and so only one is stored.

    std::cout << "Number of points in set = " << points.size() << "\n";

    // An iterator may be used to print the member variables of the class of points
    std::set<Point2d>::const_iterator c;    // Iterator is associated with a set of Point2d objects

    for(c = points.begin(); c !=points.end(); c++)
    {
        std::cout << (*c).x << " " << (*c).y << "\n"; // access the memeber variables of Point2d objects with dot notation
        // std::cout << c->x << " " << c->y << "\n";
    }
    return 0;
}