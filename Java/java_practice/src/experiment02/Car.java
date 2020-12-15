package experiment02;

public class Car {
	private String num;
	private String brand;
	private String color;
	private int price;
	private double weight;

	public Car(String num,String brand,String color,int price,double weight){
		this.num = num;
		this.brand = brand;
		this.color = color;
		this.price = price;
		this.weight = weight;
	}

	public String getNum() {
		return num;
	}

	public void setNum(String num) {
		this.num = num;
	}

	public String getBrand() {
		return brand;
	}

	public void setBrand(String brand) {
		this.brand = brand;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public double getWeight() {
		return weight;
	}

	public void setWeight(float weight) {
		this.weight = weight;
	}
	
	public void carRun(){
		System.out.println("����������ʻ");
	}
	public void carStop(){
		System.out.println("����ֹͣǰ��");
	}
	public static void carStar(){
		System.out.println("����׼������");
	}	
	public static void carLife(){
		System.out.println("��������Ϊ����");
	}	
	public static void carPeople(){
		System.out.println("�����ؿ���Ϊ����");
	}
	
	public static void main (String[] args){
		Car car=new Car("��A37Q86","����","��ɫ",300000,1.4);
		System.out.println("�����ƺţ�"+car.num);
		System.out.println("����Ʒ�ƣ�"+car.brand);
		System.out.println("������ɫ��"+car.color);
		System.out.println("�����۸�Ԫ����"+car.price);
		System.out.println("�����������֣���"+car.weight);
		car.carRun();
		car.carStop();
		carStar();
		carLife();
		carPeople();
	}
    
}

