/*20.矩阵相乘 题目描述
小明最近在为线性代数而头疼，线性代数确实很抽象（也很无聊），可惜他的老师正在讲这 矩阵乘法这一段内容。 当然，小明上课打瞌睡也没问题，但线性代数的习题可是很可怕的。 小明希望你来帮他完成这个任务。
现在给你一个 ai 行 aj 列的矩阵和一个 bi 行 bj 列的矩阵， 要你求出他们相乘的积（当然也是矩阵）。 (输入数据保证 aj=bi,不需要判断)
输入
输入文件共有 ai+bi+2 行，并且输入的所有数为整数（long long 范围内）。 第 1 行：ai 和 aj 第 2~ai+2 行：矩阵 a 的所有元素 第 ai+3 行：bi 和 bj 第 ai+3~ai+bi+3 行：矩阵 b 的所有元素
输出
输出矩阵 a 和矩阵 b 的积（矩阵 c) （ai 行 bj 列）
样例输入
2 2
12 23
45 56
2 2
78 89
45 56
样例输出
1971 2356
6030 7141
*******************/
//12*78+23*45	12*89+23*56
//45*78+56*45	45*89+56*56