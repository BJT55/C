package first;

import java.util.Random;

//ÿһ���������ɸ��ڵ���ɵģ�ÿһ������к�������
public class Node {
	private int x;
	private int y;
	
	public Node(int x,int y){
		this.x = x;
		this.y = y;
	}
	public int getX() {
		return x;
	}
	public void setX(int x) {
		this.x = x;
	}
	public int getY() {
		return y;
	}
	public void setY(int y) {
		this.y = y;
	}
	
	//�������λ�õķ���
	public void random(){
		//����random����
		Random r=new Random();
		this.x=r.nextInt(40);   //������ɺ�����
		this.y=r.nextInt(40);   //�������������
		
	}
}
