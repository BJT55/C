package magazine;


import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;


import java.sql.*;


public class U_Menu extends JFrame {

     static String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	 static String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=magazine";  

	  static final String userName="sa";   // Ĭ��Ϊsa,����Ϊ�Լ����õ�SQLServer���
	  static final String userPwd="123456";   // ��д�������
	private JPanel menuPanel;

	/**
	 * Launch the application.
	 */
//	public static void main(String[] args) {
//		
//     	           U_Menu frame = new U_Menu();
//					frame.setVisible(true);
//		
//	}

//������½ҳ��
	public U_Menu() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 348);
		menuPanel = new JPanel();
		menuPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(menuPanel);
		menuPanel.setLayout(null);


		JButton btnNewButton_1 = new JButton("��ѯ");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				//Ask f = new Ask();

			}
		});
		btnNewButton_1.setBounds(220, 100, 120, 28);
		menuPanel.add(btnNewButton_1);

		JButton btnNewButton_2 = new JButton("���");
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Scan scan = new Scan(2);

			}
		});
		btnNewButton_2.setBounds(220, 150, 120, 25);
		menuPanel.add(btnNewButton_2);

		JLabel lblNewLabel = new JLabel("�û��˵�");
		lblNewLabel.setFont(new Font("����", Font.PLAIN, 24));
		lblNewLabel.setBounds(230, 37, 197, 43);
		menuPanel.add(lblNewLabel);

		JButton btnNewButton_3 = new JButton("�˳�");
		btnNewButton_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//��ť���ص�¼����
				dispose();
				Login login = new Login();
			}
		});
		btnNewButton_3.setBounds(220, 200, 120, 25);
		menuPanel.add(btnNewButton_3);
	}
}


