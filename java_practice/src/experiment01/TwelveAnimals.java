package experiment01;

public class TwelveAnimals {
		public static void main(String[] args){
			Year.printAnimal(2000);
		}

	}
class Year{
	    public static void printAnimal (int n){
			int animal= (n-1900)%12;
			if(n<1900){
				System.out.println("�����������");
			}
			else{
				switch(animal){
				case 0:
					System.out.println("��");break;
				case 1:
					System.out.println("ţ");break;
				case 2:
					System.out.println("��");break;
				case 3:
					System.out.println("��");break;
				case 4:
					System.out.println("��");break;
				case 5:
					System.out.println("��");break;
				case 6:
					System.out.println("��");break;
				case 7:
					System.out.println("��");break;
				case 8:
					System.out.println("��");break;
				case 9:
					System.out.println("��");break;
				case 10:
					System.out.println("��");break;
				case 11:
					System.out.println("��");break;
				}
			}	
		}
}


