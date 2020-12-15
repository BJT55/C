package IdCard;

public class IdCard {
	private String num;
	
	public String getNum() {
		return num;
	}
	
	public void setNum(String num) throws IdCardException{
		char[] charArray=num.toCharArray();
		if(num.length()!=18)
		{
			throw new IdCardException("���֤��λ������18λ......");
		}
		else 
		{
			for(int i=0;i<18;i++)
			{
				if( i<=16 && !numIsAllDigit(charArray[i]) )
				{
					throw new IdCardException("���֤��ǰ17λ�з����ַ���......");
				}
				else  
				{
					if(i==17&&!numIsNotDigitOrXx(charArray[i]))
					{
						throw new IdCardException("���֤�ŵ�18λ�з����ֻ���ĸX/x����ķ���......");
					}
					else this.num=num;
				}
			}
			
		}
	}
	
	public boolean numIsAllDigit(char ch)
	{
		boolean result=true;
		if((ch<'0')||(ch>'9'))
		{
			result=false;
		}
		return result;
	}
	public boolean numIsNotDigitOrXx(char ch)
	{
		boolean result=true;
		if(   (ch<'0')||(ch>'9') || ch!='X' || ch!='x')
		{
			result=false;
		}
		return result;
	}
	public IdCard(String num) throws IdCardException{
		setNum(num);
	}
}
