package Book;

public class Book {
	private String num;  //ISBN���
	private String press;  //������
	private String author;   //����
	private float price;    //�۸�
	private int page;    //ҳ��
	
	public String getNum() {
		return num;
	}
	public void setNum(String num) throws BookExeception{
		if(num.length()!=13){
			throw new BookExeception("ISBN��Ų���13λ");
		}
		else  
		{
			if(!numIsAllDigit(num))
			{
				throw new BookExeception("ISBN������з������ַ�");
			}
			else
			{
				this.num = num;
			}
		}
	}
	public boolean numIsAllDigit(String num)
	{
		boolean result=true;
		for(int i=0;i<num.length();i++)
		{
			char ch=num.charAt(i);
			if((ch<'0')||(ch>'9'))
			{
				result=false;
				break;
			}
		}
		return result;
	}
	
	public String getPress() {
		return press;
	}
	public void setPress(String press) {
		this.press = press;
	}
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	
	
	public float getPrice(){
		return price;
	}
	public void setPrice(float price)  throws BookExeception{
		if(price<0){
			throw new BookExeception("ͼ��۸�Ϊ��ֵ");
		}
		else  this.price = price;
	}
	
	
	public int getPage() {
		return page;
	}
	public void setPage(int page) throws BookExeception{
		if(page<=0){
			throw new BookExeception("ҳ����Ӧ��Ϊ������");
		}
		this.page = page;
	}
	public Book(String num,String press,String author,float price,int page) throws BookExeception{
		setNum(num);
		setPress(press);
		setPrice(price);
		setPage(page);
	}
}
