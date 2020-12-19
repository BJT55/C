package ProvinceCity;

import javax.swing.*;
import java.awt.event.*;


public class ItemTest extends JFrame implements ItemListener{

	JComboBox province;   //һ��ѡ����ʡ��
	JComboBox city;     //����ѡ���ų�����
	
	public  ItemTest(){
	
		JLabel label1 = new JLabel("��ѡ��ʡ�ݣ�");
		label1.setSize(130, 30);
		label1.setLocation(20, 60);
		this.add(label1);
		
		JLabel label2 = new JLabel("��ѡ����У�");
		label2.setSize(130, 30);
		label2.setLocation(20, 130);
		this.add(label2);
	
		province = new JComboBox();    //����ʡ��
		String[] pro = getProvinceNames();
		for( int i = 0; i < pro.length; i++){
			province.addItem(pro[i]);
		}
		province.setSize(200, 30);
		province.setLocation(130,60);
		province.addItemListener((ItemListener) this);
		this.add(province);
		
		city = new JComboBox();   //���ó���
		city.setSize(200, 30);
		city.setLocation(130, 130);
		this.add(city);
		
		this.setSize(450,350);
		this.setLayout(null);
		this.setVisible(true);
	}
	
	public void itemStateChanged(ItemEvent e){
		JComboBox com =(JComboBox)e.getSource();
		String str = com.getSelectedItem().toString();
		String[] province = getCityByProvince(str);
		city.removeAllItems();
		for( int i = 0; i < province.length; i++){
			city.addItem(province[i]);
		}
	}
	
    //��ȡѧԺ����
	private String[] getProvinceNames(){
		String[] province = {"�ӱ�ʡ","����ʡ","ɽ��ʡ","����ʡ","����ʡ"};
		return province;
	}
	
    //��ȡ��ѧԺƥ���רҵ����
	private String[] getCityByProvince(String str) {
		String[] city = new String[10];
		if( str.equals("�ӱ�ʡ")){
			city[0] = "ʯ��ׯ";
			city[1] = "�ػʵ�";
			city[2] = "������";
			city[3] = "��ɽ��";
			city[4] = "�żҿ�";
			city[5] = "������";
			city[6] = "�е���";
		}
		if( str.equals("����ʡ")){
			city[0] = "������";
			city[1] = "������";
			city[2] = "������";
			city[3] = "������";
			city[4] = "�����";
			city[5] = "ͭ����";
			city[6] = "μ����";
			city[7] = "������";
		}
		if( str.equals("ɽ��ʡ")){
			city[0] = "Ϋ����";
			city[1] = "������";
			city[2] = "��ׯ��";
			city[3] = "������";
			city[4] = "��̨��";
			city[5] = "������";
			city[6] = "������";
		}
		if( str.equals("����ʡ")){
			city[0] = "֣����";
			city[1] = "������";
			city[2] = "������";
			city[3] = "������";
			city[4] = "������";
			city[5] = "������";
			city[6] = "����Ͽ";
			city[7] = "�ܿ���";
			city[8] = "פ���";
			city[9] = "������";
		}
		if( str.equals("����ʡ")){
			city[0] = "������";
			city[1] = "ͨ����";
			city[2] = "�׳���";
			city[3] = "��ƽ��";
			city[4] = "��Դ��";
			city[5] = "��ԭ��";
			city[6] = "��ɽ��";
		}
		return city;
	}

}
