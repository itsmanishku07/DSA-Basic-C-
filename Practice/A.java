import java.util.Scanner;
class Rectangle{
    int width;
    int height;
    void display() {
        System.out.println(width + " " + height);
    }
}
class RectangleArea extends Rectangle {
    void read_input() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter width");
        width = scanner.nextInt();
        System.out.println("Enter Height");
        height = scanner.nextInt();
        scanner.close();
    }
    @Override
    void display() {
        super.display();
        int area = width * height;
        System.out.println("Output");
        System.out.println(area);
    }
}
public class A {
    public static void main(String[] args) {
        RectangleArea rectangle = new RectangleArea();
        rectangle.read_input();
        rectangle.display();
    }
}