public class TestQuadrilateral 
{
    public static void main(String[] args) 
    {
        Trapezoid tepa = new Trapezoid(new Point(0,0),new Point(6,0),
        new Point(4,4),new Point(0,4));
        Parallelogram para = new Parallelogram(new Point(0,0),new Point(8,0),
        new Point(12,4),new Point(4,4));
        Rectangle rekt = new Rectangle(new Point(0,0),new Point(3,0),new Point(3,1)
        ,new Point(0,1));
        Square sq = new Square(new Point(0,0),new Point(5,0),new Point(5,5),
        new Point(0,5));
        System.out.println(tepa.getArea());
        System.out.println(para.getArea());
        System.out.println(rekt.getArea());
        System.out.println(sq.getArea());
    }    
}
