### **递归算法的优缺点**
* 优点：代码整洁，易于理解；如在树的前/中/后序遍历中，递归的实现明显比循环简单。
* 缺点：
    + 时间和空间的消耗比较大。递归由于是函数调用自身，而函数的调用是消耗时间和空间的，每一次函数调用，都需要在内存栈中分配空间以保存参数，返回值和临时变量，而往栈中压入和弹出数据也都需要时间，所以降低了效率；
    + 重复计算。递归中又有很多计算是重复的，递归的本质是把一个问题分解成两个或者多个小问题，多个问题存在重叠的部分，即存在重复计算，例如斐波那契数列的递归实现；
    + 调用栈溢出。递归可能导致调用栈溢出。系统栈或者虚拟机栈空间一般都不大。如果递归求解的数据规模很大，调用层次很深，一直压入栈，会导致堆栈溢出。（解决方法，在代码中限制递归调用的最大深度）。