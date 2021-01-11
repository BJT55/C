package magazine;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;
import java.io.Serializable;
import java.sql.*;
import java.util.Vector;

import javax.swing.*;

public class Search extends JFrame{
	String driverName="com.microsoft.sqlserver.jdbc.SQLServerDriver";
	String dbURL="jdbc:sqlserver://localhost:1433;DatabaseName=magazine";  // Ϊ���ݿ������˴���д������ݿ���
	String userName="sa";   // Ĭ��Ϊsa,����Ϊ�Լ����õ�SQLServer���
	String userPwd="123456";   // ��д�������

	JLabel jnamel = new JLabel("�ڿ����� ");
	JLabel jnol = new JLabel("�� �� �� ");
	JLabel jthemel = new JLabel("�ڿ�����");
//	JLabel result1=new JLabel("��ѯ���Ϊ��");
//	JLabel result2=new JLabel();

	JTextField jnamet = new JTextField("", 20);
	JTextField jnot = new JTextField("", 20);
	JTextField jthemet = new JTextField("", 20);

	JButton search1 = new JButton("���ڿ����Ʋ�ѯ");
	JButton search2 = new JButton("���ڿ��Ų�ѯ");
	JButton search3 = new JButton("���ڿ������ѯ");
	
	JButton buttonreturn = new JButton("����");
	
	String[][] row=new String[20][5];
	String[] titles={"�ڿ���","�ڿ���","�ڿ����","�ڿ�����","�ڿ��۸�"};
    JTable jt=null;  
    JScrollPane jsp=null;  
	
	public Search(final int i) {
		JPanel jnamep = new JPanel();
		jnamep.setLocation(50,20);
		jnamep.setSize(300,30);
		JPanel jnop = new JPanel();
		jnop.setLocation(50,60);
		jnop.setSize(300,30);
		JPanel jthemep = new JPanel();
		jthemep.setLocation(50,100);
		jthemep.setSize(300,30);
		JPanel jrs = new JPanel();
		jrs.setLocation(50,240);
		jrs.setSize(300,60);

		jnamep.add(jnamel);
		jnamep.add(jnamet);
		
		jnop.add(jnol);
		jnop.add(jnot);

		jthemep.add(jthemel);
		jthemep.add(jthemet);


		this.setTitle("��ѯ�ڿ���Ϣ");
		getContentPane().setLayout(null);
		getContentPane().add(jnop);
		getContentPane().add(jnamep);
		getContentPane().add(jthemep);
//		getContentPane().add(jrs);
		search1.setSize(130,30);
		search1.setLocation(50,150);
		getContentPane().add(search1);
		search2.setSize(130,30);
		search2.setLocation(200,150);
		getContentPane().add(search2);
		search3.setSize(130,30);
		search3.setLocation(50,200);
		getContentPane().add(search3);
		buttonreturn.setSize(130,30);
		buttonreturn.setLocation(200,200);
		getContentPane().add(buttonreturn);
		



		

		buttonreturn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
				if( i==1)
				{
					dispose();
					M_Menu M = new M_Menu();
					M.setVisible(true);
				}
				else{
					dispose();
					 U_Menu U = new U_Menu();
					 U.setVisible(true);
				}
			}
		});

		search1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Connection conn = null;
				ResultSet res = null;
				Statement stat = null;

				StringBuffer strSql=new StringBuffer();
				strSql.append("select * from journal where mag_name=");
				strSql.append("'");
				strSql.append(jnamet.getText());
				strSql.append("'");
				System.out.println(strSql.toString());
				String sql = strSql.toString();
				try {
					Class.forName(driverName);

				} catch (Exception d) {
					System.out.println("����ʧ��");
					d.printStackTrace();
				}
				try {
					conn = DriverManager.getConnection(dbURL, userName, userPwd);
					stat = conn.createStatement();
					res = stat.executeQuery(sql);
					int count=0;
					if(jnamet.getText().trim().equals(""))//�ж��Ƿ�����Ϊ��
					{
						JOptionPane.showMessageDialog(search1, "�ڿ����Ʋ���Ϊ��");
					}
					else{ 
					    while (res.next()) {
		                    row[count][0]=res.getString(1);
		                    row[count][1]=res.getString(2);
		                    row[count][2]=res.getString(3);
		                    row[count][3]=res.getString(4);
		                    row[count][4]=res.getString(5);
		                    count++;
				                    
					    }
					}
					jt.updateUI();
					jnamet.setText("");
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();

				} finally {
					try {
						conn.close();
					} catch (SQLException ar) {
						ar.printStackTrace();
					}
				}
			}
		});
		
		search2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Connection conn = null;
				ResultSet res = null;
				Statement stat = null;
				
				StringBuffer strSql=new StringBuffer();
				strSql.append("select * from journal where mag_num=");
				strSql.append("'");
				strSql.append(jnot.getText());
				strSql.append("'");
				System.out.println(strSql.toString());
				String sql = strSql.toString();
				try {
					Class.forName(driverName);

				} catch (Exception d) {
					System.out.println("����ʧ��");
					d.printStackTrace();
				}
				try {
					conn = DriverManager.getConnection(dbURL, userName, userPwd);
					stat = conn.createStatement();
					res = stat.executeQuery(sql);
					int count=0;
					
					if(jnot.getText().trim().equals(""))//�ж��Ƿ�����Ϊ��
					{
						JOptionPane.showMessageDialog(search2, "�ڿ��Ų���Ϊ��");
					}
					else if(jnot.getText().length()!=6)
					{
						JOptionPane.showMessageDialog(search2, "�ڿ���Ӧ��Ϊ6λ");
					}
					else{
					    while (res.next()) {
			                    row[count][0]=res.getString(1);
			                    row[count][1]=res.getString(2);
			                    row[count][2]=res.getString(3);
			                    row[count][3]=res.getString(4);
			                    row[count][4]=res.getString(5);
			                    count++;
						 
					    }
					}
					jt.updateUI();
					jnot.setText("");
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();

				} finally {
					try {
						conn.close();
					} catch (SQLException ar) {
						ar.printStackTrace();
					}
				}
			}
		});
		
		search3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Connection conn = null;
				ResultSet res = null;
				Statement stat = null;
				
				StringBuffer strSql=new StringBuffer();
				strSql.append("select * from journal where mag_type=");
				strSql.append("'");
				strSql.append(jthemet.getText());
				strSql.append("'");
				System.out.println(strSql.toString());
				String sql = strSql.toString();
				
				try {
					Class.forName(driverName);

				} catch (Exception d) {
					System.out.println("����ʧ��");
					d.printStackTrace();
				}
				try {
					conn = DriverManager.getConnection(dbURL, userName, userPwd);
					stat = conn.createStatement();
					res = stat.executeQuery(sql);
					int count=0;
					
					if(jthemet.getText().trim().equals(""))//�ж��Ƿ�����Ϊ��
					{
						JOptionPane.showMessageDialog(search3, "�ڿ����ⲻ��Ϊ��");
					}
					else{
					    while (res.next()) {
						    row[count][0]=res.getString(1);
		                    row[count][1]=res.getString(2);
		                    row[count][2]=res.getString(3);
		                    row[count][3]=res.getString(4);
		                    row[count][4]=res.getString(5);
		                    count++;
						    
					    }
					}
					jt.updateUI();
					jthemet.setText("");
					
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();

				} finally {
					try {
						conn.close();
					} catch (SQLException ar) {
						ar.printStackTrace();
					}
				}
			}
		});
		
		//��ʼ��Jtable  
        jt = new JTable(row,titles);  
      
        //��ʼ�� jsp  
        jsp = new JScrollPane(jt);  
          
        //��jsp���뵽jframe  
        this.add(jsp);  
        jsp.setSize(370, 300);
        jsp.setLocation(10, 250);

		
		this.setLocation(400, 100);
		this.setSize(400, 600);
		this.setVisible(true);
	}
	
//	
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//
//		Search search = new Search();
//	}

}
