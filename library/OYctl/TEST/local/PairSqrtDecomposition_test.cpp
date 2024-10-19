#include "IO/FastIO.h"
#include "MATH/PairSqrtDecomposition.h"

int main() {
    uint32_t n1 = 105;
    uint32_t n2 = 432;
    OY::PairSqrtDecomposition<uint32_t> sd(n1, n2);
    for (auto range : sd)
        cout << "floor(" << n1 << " / x) = " << range.quot1() << ", floor(" << n2 << " / x) = " << range.quot2() << ", \t" << range.left() << " <= x <= " << range.right() << endl;

    // 也可以反向迭代
    cout << "\nreversed:\n";
    for (auto it = sd.rbegin(); it != sd.rend(); ++it)
        cout << "floor(" << n1 << " / x) = " << it.quot1() << ", floor(" << n2 << " / x) = " << it.quot2() << ", \t" << it.left() << " <= x <= " << it.right() << endl;
}
/*
#输出如下
floor(105 / x) = 0, floor(432 / x) = 1, 	217 <= x <= 432
floor(105 / x) = 0, floor(432 / x) = 2, 	145 <= x <= 216
floor(105 / x) = 0, floor(432 / x) = 3, 	109 <= x <= 144
floor(105 / x) = 0, floor(432 / x) = 4, 	106 <= x <= 108
floor(105 / x) = 1, floor(432 / x) = 4, 	87 <= x <= 105
floor(105 / x) = 1, floor(432 / x) = 5, 	73 <= x <= 86
floor(105 / x) = 1, floor(432 / x) = 6, 	62 <= x <= 72
floor(105 / x) = 1, floor(432 / x) = 7, 	55 <= x <= 61
floor(105 / x) = 1, floor(432 / x) = 8, 	53 <= x <= 54
floor(105 / x) = 2, floor(432 / x) = 8, 	49 <= x <= 52
floor(105 / x) = 2, floor(432 / x) = 9, 	44 <= x <= 48
floor(105 / x) = 2, floor(432 / x) = 10, 	40 <= x <= 43
floor(105 / x) = 2, floor(432 / x) = 11, 	37 <= x <= 39
floor(105 / x) = 2, floor(432 / x) = 12, 	36 <= x <= 36
floor(105 / x) = 3, floor(432 / x) = 12, 	34 <= x <= 35
floor(105 / x) = 3, floor(432 / x) = 13, 	31 <= x <= 33
floor(105 / x) = 3, floor(432 / x) = 14, 	29 <= x <= 30
floor(105 / x) = 3, floor(432 / x) = 15, 	28 <= x <= 28
floor(105 / x) = 3, floor(432 / x) = 16, 	27 <= x <= 27
floor(105 / x) = 4, floor(432 / x) = 16, 	26 <= x <= 26
floor(105 / x) = 4, floor(432 / x) = 17, 	25 <= x <= 25
floor(105 / x) = 4, floor(432 / x) = 18, 	23 <= x <= 24
floor(105 / x) = 4, floor(432 / x) = 19, 	22 <= x <= 22
floor(105 / x) = 5, floor(432 / x) = 20, 	21 <= x <= 21
floor(105 / x) = 5, floor(432 / x) = 21, 	20 <= x <= 20
floor(105 / x) = 5, floor(432 / x) = 22, 	19 <= x <= 19
floor(105 / x) = 5, floor(432 / x) = 24, 	18 <= x <= 18
floor(105 / x) = 6, floor(432 / x) = 25, 	17 <= x <= 17
floor(105 / x) = 6, floor(432 / x) = 27, 	16 <= x <= 16
floor(105 / x) = 7, floor(432 / x) = 28, 	15 <= x <= 15
floor(105 / x) = 7, floor(432 / x) = 30, 	14 <= x <= 14
floor(105 / x) = 8, floor(432 / x) = 33, 	13 <= x <= 13
floor(105 / x) = 8, floor(432 / x) = 36, 	12 <= x <= 12
floor(105 / x) = 9, floor(432 / x) = 39, 	11 <= x <= 11
floor(105 / x) = 10, floor(432 / x) = 43, 	10 <= x <= 10
floor(105 / x) = 11, floor(432 / x) = 48, 	9 <= x <= 9
floor(105 / x) = 13, floor(432 / x) = 54, 	8 <= x <= 8
floor(105 / x) = 15, floor(432 / x) = 61, 	7 <= x <= 7
floor(105 / x) = 17, floor(432 / x) = 72, 	6 <= x <= 6
floor(105 / x) = 21, floor(432 / x) = 86, 	5 <= x <= 5
floor(105 / x) = 26, floor(432 / x) = 108, 	4 <= x <= 4
floor(105 / x) = 35, floor(432 / x) = 144, 	3 <= x <= 3
floor(105 / x) = 52, floor(432 / x) = 216, 	2 <= x <= 2
floor(105 / x) = 105, floor(432 / x) = 432, 	1 <= x <= 1

reversed:
floor(105 / x) = 105, floor(432 / x) = 432, 	1 <= x <= 1
floor(105 / x) = 52, floor(432 / x) = 216, 	2 <= x <= 2
floor(105 / x) = 35, floor(432 / x) = 144, 	3 <= x <= 3
floor(105 / x) = 26, floor(432 / x) = 108, 	4 <= x <= 4
floor(105 / x) = 21, floor(432 / x) = 86, 	5 <= x <= 5
floor(105 / x) = 17, floor(432 / x) = 72, 	6 <= x <= 6
floor(105 / x) = 15, floor(432 / x) = 61, 	7 <= x <= 7
floor(105 / x) = 13, floor(432 / x) = 54, 	8 <= x <= 8
floor(105 / x) = 11, floor(432 / x) = 48, 	9 <= x <= 9
floor(105 / x) = 10, floor(432 / x) = 43, 	10 <= x <= 10
floor(105 / x) = 9, floor(432 / x) = 39, 	11 <= x <= 11
floor(105 / x) = 8, floor(432 / x) = 36, 	12 <= x <= 12
floor(105 / x) = 8, floor(432 / x) = 33, 	13 <= x <= 13
floor(105 / x) = 7, floor(432 / x) = 30, 	14 <= x <= 14
floor(105 / x) = 7, floor(432 / x) = 28, 	15 <= x <= 15
floor(105 / x) = 6, floor(432 / x) = 27, 	16 <= x <= 16
floor(105 / x) = 6, floor(432 / x) = 25, 	17 <= x <= 17
floor(105 / x) = 5, floor(432 / x) = 24, 	18 <= x <= 18
floor(105 / x) = 5, floor(432 / x) = 22, 	19 <= x <= 19
floor(105 / x) = 5, floor(432 / x) = 21, 	20 <= x <= 20
floor(105 / x) = 5, floor(432 / x) = 20, 	21 <= x <= 21
floor(105 / x) = 4, floor(432 / x) = 19, 	22 <= x <= 22
floor(105 / x) = 4, floor(432 / x) = 18, 	23 <= x <= 24
floor(105 / x) = 4, floor(432 / x) = 17, 	25 <= x <= 25
floor(105 / x) = 4, floor(432 / x) = 16, 	26 <= x <= 26
floor(105 / x) = 3, floor(432 / x) = 16, 	27 <= x <= 27
floor(105 / x) = 3, floor(432 / x) = 15, 	28 <= x <= 28
floor(105 / x) = 3, floor(432 / x) = 14, 	29 <= x <= 30
floor(105 / x) = 3, floor(432 / x) = 13, 	31 <= x <= 33
floor(105 / x) = 3, floor(432 / x) = 12, 	34 <= x <= 35
floor(105 / x) = 2, floor(432 / x) = 12, 	36 <= x <= 36
floor(105 / x) = 2, floor(432 / x) = 11, 	37 <= x <= 39
floor(105 / x) = 2, floor(432 / x) = 10, 	40 <= x <= 43
floor(105 / x) = 2, floor(432 / x) = 9, 	44 <= x <= 48
floor(105 / x) = 2, floor(432 / x) = 8, 	49 <= x <= 52
floor(105 / x) = 1, floor(432 / x) = 8, 	53 <= x <= 54
floor(105 / x) = 1, floor(432 / x) = 7, 	55 <= x <= 61
floor(105 / x) = 1, floor(432 / x) = 6, 	62 <= x <= 72
floor(105 / x) = 1, floor(432 / x) = 5, 	73 <= x <= 86
floor(105 / x) = 1, floor(432 / x) = 4, 	87 <= x <= 105
floor(105 / x) = 0, floor(432 / x) = 4, 	106 <= x <= 108
floor(105 / x) = 0, floor(432 / x) = 3, 	109 <= x <= 144
floor(105 / x) = 0, floor(432 / x) = 2, 	145 <= x <= 216
floor(105 / x) = 0, floor(432 / x) = 1, 	217 <= x <= 432

*/