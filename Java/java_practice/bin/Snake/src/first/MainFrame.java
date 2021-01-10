package first;
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class MainFrame extends JFrame{

	
	private static boolean ture;
	public MainFrame() throws HeadlessException {
		//��ʼ�����ڲ���
		initFrame();
		//��ʼ����Ϸ����
		initGamePanel();
		//��ʼ����
		initSnake();
	}

	private void initSnake() {
	}
	
	private void initGamePanel() {
		JPanel JPanel= new JPanel(){
			//������Ϸ���̵�����
			public void paint(Graphics g){    //Graphics�൱�ڻ���
				//���ƺ���
				for(int i=0;i<40;i++){
					g.drawLine(0, i*15, 600, i*15);
				}
				//���ƺ���
				for(int j=0;j<40;j++){
					g.drawLine(j*15, 0, j*15, 600);
				}
				//������
				LinkedList<Node> body =Snake.getBody();
				for(Node node:body){
					g.fillRect(node.getX()*15, node.getY()*15, 15, 15);
				}
				//����ʳ��
			}
		};
		//��������ӵ�������
		add(JPanel);
	}
	//��ʼ��
	private void initFrame(){
		
		setTitle("̰������Ϸ");
		setSize(610,640);  //���ô�����
		setLocation(400,400);   //���ô���λ��
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//���ô��ڹر�
		setResizable(false);//���ô����С���ɱ�
	}
	public static void main(String[] args){
		//����������󣬲���ʾ

		new MainFrame().setVisible(ture);
	}
}