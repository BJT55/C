package Shape;

public class Test {

	public static void main(String[] args) {
		Circle circle = new Circle (4);
		Triangle triangle = new Triangle (3);
		Rectangle rectangle=new Rectangle (2.4,4.0);
		System.out.println("Բ�ε��ܳ�Ϊ��"+circle.calculateC());
		System.out.println("Բ�ε����Ϊ��"+circle.calculateS());
		System.out.println("�����ε��ܳ�Ϊ��"+rectangle.calculateC());
		System.out.println("�����ε����Ϊ��"+rectangle.calculateS());
		System.out.println("�ȱ������ε��ܳ�Ϊ��"+triangle.calculateC());
		System.out.println("�ȱ������ε����Ϊ��"+triangle.calculateS());
	}

}
