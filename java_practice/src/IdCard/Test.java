package IdCard;

public class Test {

	public static void main(String[] args){
		
		String num="42327620000122486X";
		char ch=num.charAt(16);
		int sex=Integer.parseInt(String.valueOf(ch));
		if(sex%2==0)
		{
			System.out.println("�������Ů��.....");
		}
		else   System.out.println("�����������.....");
		
		String str1=num.substring(10,12);        //������
		String str2=num.substring(12,14);        //������
		if(str1.startsWith("0"))
		{
			str1=num.substring(11,12);
		}
		if(str2.startsWith("0"))
		{
			str2=num.substring(13,14);
		}
		System.out.println("���������ǣ�"+num.substring(6, 10)+"��"+str1+"��"+str2+"��");	
		
		
		try 
		{
			IdCard id1=new IdCard("42327620000122486");
		} 
		catch (IdCardException e) 
		{
			System.out.println(e.getMessage());
		}

		try 
		{
			IdCard id2=new IdCard("42327620000122486a");
		} 
		catch (IdCardException e) 
		{
			System.out.println(e.getMessage());
		}
		try 
		{
			IdCard id3=new IdCard("4232762000012268X7");
		} 
		catch (IdCardException e) 
		{
			System.out.println(e.getMessage());
		}

	}
}

