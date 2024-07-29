class Quadrilateral
{
    private Point endpoint[];
    Quadrilateral(Point p0, Point p1, Point p2, Point p3) 
    {
        endpoint = new Point[]{p0,p1,p2,p3};
    }
    public double getArea()
    {
        return 0.0;
    }
    public Point getEndpoint(int index)
    {
        return endpoint[index];
    }
}