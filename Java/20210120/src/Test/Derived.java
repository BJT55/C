package Test;


class Base{

    public Base(String s){

        System.out.print("B");

    }

    public Base() {

    }
}

public class Derived extends Base{

    public Derived (String s) {
        super();

        System.out.print("D");

    }

    public static void main(String[] args){

        new Derived("C");

    }

}