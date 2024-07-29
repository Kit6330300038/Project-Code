public class Rectangle extends Quadrilateral
{
    Rectangle(Point p0,Point p1,Point p2,Point p3)
    {
        super(p0, p1, p2, p3);
    }
    public double getArea() 
    {
        return (this.getEndpoint(0).getX()-this.getEndpoint(1).getX())*
        (this.getEndpoint(0).getY()-this.getEndpoint(3).getY());
    }
}
