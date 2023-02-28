//  class Point2d representing the class of points in two dimensions

class Point2d
{   
    // This class has two member variables, x and y, that store the x- and y- coordinates.
    public:
        int x, y;
        // a constructor that allows us to initialise the coordinates,
        Point2d(int a, int b)
        {
            x = a;
            y = b;
        }
        // an overloaded “less than” < operator that allows us to order points in two dimensions
        // according to the rules that we discussed earlier
        bool operator<(const Point2d& other) const
        {
            if(x < other.x)
                return true;
            else if (x > other.x)
                return false;
            else if (y < other.y)
            {
                // x == other.x
                return true;
            }
            else
            {
                // x == other.x
                // y >= other.y
                return false;
            }
        }
};