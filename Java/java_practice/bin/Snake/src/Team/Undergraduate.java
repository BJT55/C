package Team;

public class Undergraduate extends People {

	public Undergraduate(String name, String sex, int age) {
		super(name, sex, age);
	}
	public void collect(){
		System.out.println(getName()+"(������)���������ռ�");
	}

}
