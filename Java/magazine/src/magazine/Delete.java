package magazine;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class Delete extends JFrame {

	String driverName = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
	// ����JDBC����
	String dbURL = "jdbc:sqlserver://localhost:1433; DatabaseName=magazine";
	// ���ӷ����������ݿ�
	String userName = "sa"; // Ĭ���û���
	String userPwd = "123456"; // ����
	
    JLabel magLaNum = new JLabel("�ڿ��ţ�");
    JTextField magTextNum = new JTextField("",20);
    JButton buDelete = new JButton("ɾ��");
    JButton buReturn = new JButton("����");
    JPanel magPanel = new JPanel();

    public Delete(){
    	magLaNum.setLocation(200,50);
    	magLaNum.setSize(100,50);
    	this.add(magLaNum);
    	
        magTextNum.setLocation(250,55);
        magTextNum.setSize(200,30);
        this.add(magTextNum);
        
        buReturn.setLocation(200,200);
        buReturn.setSize(100,50);
        this.add(buReturn);

        buDelete.setLocation(350,200);
        buDelete.setSize(100,50);
        this.add(buDelete);
        
        buDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String number = magTextNum.getText();

                Connection conn = null;
                ResultSet res = null;
				Statement stat = null;
				String sql = "delete from journal where mag_num='" + number + "'";   
				
				try {
					Class.forName(driverName);
				} catch (Exception a) {
					a.printStackTrace();
				}
				try {
					conn = DriverManager.getConnection(dbURL, userName, userPwd);
					stat = conn.createStatement();
					stat.executeUpdate(sql);
				} catch (SQLException h) {
					h.printStackTrace();

				} finally {
					try {
						conn.close();
						System.out.println("�رճɹ�!");
					} catch (SQLException j) {
						System.out.println("�ر�ʧ��!");
						j.printStackTrace();
					}
				}
            }
        });
        
		buReturn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				M_Menu M = new M_Menu();
				M.setVisible(true);
			}
		});
		

		this.setTitle("ɾ���ڿ���Ϣ");
		this.add(magPanel);
		this.setLocation(500, 200);
		this.setSize(700, 500);
		this.setVisible(true);
		this.setLayout(null);
    }
    

}