package magazine;


import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;


import java.sql.*;


public class M_Menu extends JFrame {

 
	 JPanel menuPanel;
	

//	public static void main(String[] args) {
//	
//	      M_Menu frame = new M_Menu();
//	      frame.setVisible(true);
//		
//	}
	

//������½ҳ��
	public M_Menu() {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 600, 348);
		menuPanel = new JPanel();
		menuPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(menuPanel);
		menuPanel.setLayout(null);

		JButton btnNewButton = new JButton("���");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Add f = new Add();
			}
		});
		btnNewButton.setBounds(90, 129, 120, 28);
		menuPanel.add(btnNewButton);

		JButton btnNewButton_1 = new JButton("ɾ��");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Delete f = new Delete();
						
			}
		});
		btnNewButton_1.setBounds(382, 129, 120, 28);
		menuPanel.add(btnNewButton_1);

		JButton btnNewButton_2 = new JButton("��ѯ");
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
//				Ask f = new Ask();
//				// f.setSize(400,300);
//				// JLabel label = new JLabel("�����´���");
//				// f.add(label);
//				f.setLocationRelativeTo(null);
//				f.setVisible(true);
			}
		});
		btnNewButton_2.setBounds(90, 181, 120, 28);
		menuPanel.add(btnNewButton_2);

		JButton btnNewButton_3 = new JButton("���");
		btnNewButton_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Scan scan = new Scan(1);

			}
		});
		btnNewButton_3.setBounds(382, 183, 120, 25);
		menuPanel.add(btnNewButton_3);

		JLabel lblNewLabel = new JLabel("����Ա�˵�");
		lblNewLabel.setFont(new Font("����", Font.PLAIN, 24));
		lblNewLabel.setBounds(230, 37, 197, 43);
		menuPanel.add(lblNewLabel);

		JButton btnNewButton_4 = new JButton("�޸���Ϣ");
		btnNewButton_4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				Update up = new Update();
//				f.setLocationRelativeTo(null);
//				f.setVisible(true);
			}
		});
		btnNewButton_4.setBounds(90, 237, 120, 23);
		menuPanel.add(btnNewButton_4);

		
		JButton btnNewButton_5 = new JButton("�˳�");
		btnNewButton_5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//��ť�˳�
				dispose();
				Login login = new Login();
			
			}
		});
		btnNewButton_5.setBounds(382, 238, 120, 25);
		menuPanel.add(btnNewButton_5);
	
	
	}
}

