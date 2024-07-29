public class Lab64MaxTest 
{ 
 public static void main(String[] args) 
 { 
 ComparableRectangle rectangle1 = new ComparableRectangle(4, 5); //20 
 ComparableRectangle rectangle2 = new ComparableRectangle(3, 6); //18 
 Rectangle r = (Rectangle)Max.max(rectangle1, rectangle2); 
 System.out.println(r.getArea()); 
 ComparableCircle circle1 = new ComparableCircle(4);
 ComparableCircle circle2 = new ComparableCircle(3); 
 Circle c = (Circle)Max.max(circle1, circle2); 
 System.out.println(c.getArea()); 
 } 
} 