package first;

import java.util.LinkedList;

//һ�����������ڵ����
public class Snake {
	//����
	private static LinkedList<Node> body;
	
	//�����������ڴ���Snake����ʱִ��
	public Snake(){
		//��ʼ������
		initSnake();
	}

	private void initSnake() {
		//��������
		body=new LinkedList<Node>();
		//����6����㣬��ӵ�������
		body.add(new Node (16,20));
		body.add(new Node (17,20));
		body.add(new Node (18,20));
		body.add(new Node (19,20));
		body.add(new Node (20,20));
		body.add(new Node (21,20));
	}
	public static  LinkedList<Node> getBody() {
		return body;
	}
	public void setBody(LinkedList<Node> body){
		Snake.body=body;
	}

}
