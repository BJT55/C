package Team;

public class Teamwork {
	public static void main(String[] args){
		Teacher teacher=new Teacher("����ʦ","��",42);
		Postgraduate post1=new Postgraduate("����","��",23);
		Postgraduate post2=new Postgraduate("����","Ů",22);
		Undergraduate under=new Undergraduate("����","Ů",20);
		People.end("2020.11.28");
		People.start("2020.10.28");
	    teacher.teach();
		post1.design();
		post2.design();
		under.collect();
	}

}
