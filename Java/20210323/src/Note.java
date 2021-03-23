public class Note {
//    堆：
//    1.完全二叉树，数组
//    2.大堆、小堆
//    3.基本操作：创建堆（O(N)）、插入堆、取堆顶、删除堆顶
//    向上调整、向下调整

//    基本应用：
//    1.排序
//    2.topk

//    插入排序：
//    1.较小数组排列效率快
//    2.数组本身有序性高时效率快
//      希尔排序 shell （分组插排）
//      gap较大， 分组多，元素少，插入排序快
//      gap逐渐变小，分组少，包含元素多，但数组整体有序性高，插入排序快
//    稳定性：不稳定

//    选择排序：
//    每次从待排序列中找到最小值，放到待排序区间的最开始的位置
//    时间复杂度： O(N^2)
//    空间复杂度： O(1)
//    稳定性：不稳定

//    堆排序：
//    堆排序可以看做是一个选择排序的优化
//    1.找到第一个不为叶子结点的数，按照大堆（小堆）的规律，将二叉树重新调整
//    2.将堆顶元素和最后一个元素交换，并将交换后的二叉树 size--；即将原先堆顶元素（最大）排出堆
//    3.重复步骤一，直到 size 的值为 0
//    时间复杂度：O(NlogN)
//    空间复杂度：O(1)
//    稳定性：不稳定

//    冒泡排序：
//    比较两个相邻元素，将最大/小值放在最后面（从前往后遍历）/（从后往前遍历）
//    时间复杂度：O(N^2)
//    空间复杂度：O(1)
//    稳定性：稳定

//    快速排序：
//    时间复杂度：平均——O(NlogN) 最坏——O(N^2)
//    空间复杂度：平均——O(log)  最坏——O(N)
//    稳定性：不稳定
//      优化手段——
//          1.基准值选择（采用三数取中值）
//          2.数组过大可能会导致递归深度很大，如果当前处理的区间已经比较小了，就直接进行插入排序
//          3.若递归深度已经达到一定程度并且当前这个区间元素数目仍很多，还可以对这个区间进行堆排序



}