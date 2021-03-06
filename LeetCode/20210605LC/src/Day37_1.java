import java.util.Scanner;

public class Day37_1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()){
            int n = in.nextInt();
            in.nextLine();
            int res = 0;
            int count = 0;
            for (int i = 0; i < n; ++i){
                String s = in.nextLine();
                if (s.contains("disconnect")){
                    count--;
                }
                else if (s.contains("connect")){
                    count--;
                }
                res = Math.max(res,count);
            }
            System.out.println(res);
        }
    }
}
