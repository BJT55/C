import java.util.Scanner;
//获取一个数二进制序列中所有的偶数位和奇数位， 分别输出二进制序列
public class binaryList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        System.out.print("odd sequence:");
        for ( int i = 30; i >= 0; i -= 2){
            System.out.print((num >> i) & 1);
        }
        System.out.println();
        System.out.print("even sequence:");
        for ( int i = 31; i > 0; i -= 2){
            System.out.print((num >> i) & 1);
        }
    }
}
