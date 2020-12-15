package Shape;

class Triangle extends Shape{
	private double a;   //�ȱ�������һ��

	public void setHi(double a) {
		this.a = a;
	}
	public double getA() {
		return a;
	}
	
	public Triangle(double a){
		this.a= a;
	}
	public double calculateS() {
		return a*a*0.25*Math.sqrt(3);
	}
	public double calculateC() {
		return 3*a;
	}

}
