public class Note {
//    标准库中的 LinkedList，增删改查的时间复杂度都是O(N)
//    都是需要先进行遍历链表，找到相关节点，再进行操作
//    特殊情况列外，比如头插头删，尾插尾删

//    对比链表和顺序表
//    本质：内存连续和不连续，能否随机访问

//    队列：
//    复杂的队列：
//    1.优先队列
//    2.消息队列（队列中的元素带有类型，出队列的时候可以按照类型来取元素）
//    3.阻塞队列 （如果队列已满，此时继续插入数据，就会 阻塞 ）
//              （如果队列为空，此时继续取元素，也会阻塞）
//    4.无锁队列，更高的 线程安全 的队列
//              保证线程安全的常见手段——加锁
//              但加锁的效率比较低
//              无锁队列就是不用锁，实现线程安全（CAS）
//              加锁速度慢，但节省CPU资源，CAS速度快，但更消耗CPU
}