public class test04 {
    //创建方法求两个数的最大值max2，随后再写一个求3个数的最大值的函数max3。
    //
    //​ 要求：在max3这个函数中，调用max2函数，来实现3个数的最大值计算
    public static int max2(int a,int b){
        return a > b ? a : b;
    }

    public static int max3(int a,int b,int c){
        return max2(a,b) > c ? max2(a,b) : c;
    }

    public static void main(String[] args) {
        int a = 33, b = 21, c = 67;
        System.out.println("max2:"+max2(a,b));
        System.out.println("max3:"+max3(a,b,c));
    }
}
