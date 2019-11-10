#include <iostream>
#include <stdlib.h>

using namespace std;

int m_plus(int a, int b)
{
    int result = 0;
    for(int i = 0; i < 32; i++)
    {
        result += (b & (1 << i)) != 0 ? (a << i) : 0;
    }
    return result;
}

int divide(int dividend, int divisor)
{
    //排除3种边界情况
    if(divisor == 1)
    {
        return dividend;
    }
    if(divisor == -1)
    {
        if(dividend == INT32_MIN)
        {
            //这种情况下，不能返回-INT32_MIN，会溢出
            return INT32_MAX;
        }else{
            return -dividend;
        }
        
    }
    if(divisor == INT32_MIN)
    {
        if(dividend == divisor)
        {
            return 1;
        }else{
            return 0;
        }
    }
    //求结果符号
    int sign = 1;
    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    int result = 0;
    /*将dividend和divisor都转换为正数。花括号里的步骤其实就相当于取反。因为二进制求相反数就是各位取反再加1。
    这是补码。注意，之后的过程中，我们都将dividend看做一个UInt32。在不溢出的情况下，直接取反即可。但当
    dividend == INT32_MIN，它按bit表示就是0x8000 0000，而如果我们将这4个字节作为UInt32来看待，其实就是2^31 = -INT32_MIN了。
    并不需要额外的取反操作。所以，只要之后我们将dividend看做UInt32，就不会有溢出需要考虑了。只是在取反这一步需要注意这种情况。
    而由于已经排除了divisor = INT32_MIN的情况，所以它接下来也可以被放心地看做是UInt32。但题目要求只能出现Int32。因此不得不绕一点。
    */
    if(dividend < 0 && dividend > INT32_MIN)
    {
        dividend = (~dividend) + 1;
    }
    if(divisor < 0)
    {
        divisor = (~divisor) + 1;
    }
    /*由于长除法其实就是不断地移位，然后做减法和加法。但是需要注意，dividend已经被我们看做
    UInt32了。在长除法中，有个减法的过程。但对于极限情况，比如dividend = INT32_MIN，divisor = INT32 / 2 - 1的情况下，
    我们都知道结果是1，也就是长除法会进行到最后一位时才会得出结果，这个时候就有了-INT32_MIN + (INT32 / 2 - 1)的情况出现
    （因为全部取正，并且编译器仍然将这两个数作为Int32看待）。这个时候得出结果肯定是溢出的，虽然并不致命，但在LeetCode的编译器中溢出就会报错，因此将一个Int32拆分成
    两个Int32，并且拆出来的部分都要作为正数。同时有另外一种情况，
    由于需要比较大小，0x8000 0000作为Int32肯定是最小的，但作为UInt32却是永远大于divisor的。*/
    int dH = (divisor >> 16) & 0x0000ffff;
    int dL = divisor & 0x0000ffff;
    int rH = 0, rL = 0;
    int remain = 0;
    for(int i = 31; i >= 0; i--)
    {
        remain = (remain << 1) | (0x01 & (dividend >> i));
        rH = (remain >> 16) & 0x0000ffff;
        rL = remain & 0x0000ffff;
        //利用高低位判断两个UInt32的大小。
        if(rH > dH || (rH == dH && rL >= dL))
        {
            /*
            为避免溢出，拆分成两个UInt32分别进行减法，低16位的减法时，被减数首先要向高16位借1从而避免出现负数的情况，借的这个1放在低16位的第16位上。由于if条件的限制，绝对不会出现
            高16位减之后出现负值的情况。高低位分别做减法之后，要先将低位的借来的1还回去，如果这个1没被用掉的话。
            */
            result = (result << 1) | 1;
            rL = (1 << 16) | rL;
            rH -= 1;
            rL -= dL;
            rH -= dH;
            rH += (rL >> 16) & 0x01;
            rL &= 0x0000ffff;
            remain = (rH << 16) | rL;
        }else{
            result <<= 1;
        }
    }
    

    if(sign == -1)
    {
        return -result;
    }

    return result;
}

int divide(int dividend, int divisor)
{
    //排除3种边界情况
    if(divisor == 1)
    {
        return dividend;
    }
    if(divisor == -1)
    {
        if(dividend == INT32_MIN)
        {
            //这种情况下，不能返回-INT32_MIN，会溢出
            return INT32_MAX;
        }else{
            return -dividend;
        }
        
    }
    if(divisor == INT32_MIN)
    {
        if(dividend == divisor)
        {
            return 1;
        }else{
            return 0;
        }
    }
    //求结果符号
    int sign = 1;
    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    int result = 0;

    if(divisor < 0)
    {
        divisor = -divisor;
    }

    /*
    首先从被除数的绝对值中去掉一个除数的绝对值，这样之后再做转换的时候一定就不会溢出了，因此也可以放心地全程使用Int32进行加减法而不必担心溢出。
    经过这一步操作后，默认的结果已经多了一个1。因为避免这一步溢出，所以被除数仍然是带符号去进行操作的。
    */
    int tempDividend = dividend;
    if(dividend < 0)
    {
        tempDividend += divisor;
    }else{
        tempDividend -= divisor;
    }

    /*
    如果被除数在去掉除数的绝对值之后符号变化，说明被除数的绝对值小于除数的绝对值，这种情况下显然结果就是0。
    */
    if((dividend < 0 && tempDividend > 0) || (dividend > 0 && tempDividend < 0))
    {
        return 0;
    }

    if(tempDividend < 0)
    {
        tempDividend = -tempDividend;
    }
    dividend = tempDividend;

    int remain = 0;
    for(int i = 31; i >= 0; i--)
    {
        remain = (remain << 1) | (0x01 & (dividend >> i));
        
        if(remain >= divisor)
        {
            result = (result << 1) | 1;
            remain -= divisor;
        }else{
            result <<= 1;
        }
    }
    result += 1;
    if(sign == -1)
    {
        return -result;
    }
    return result;
}

// -2147483648
// -1109186033
int main()
{
    // cout << m_plus(-38, 20) << endl;
    int dividend = -2;
    int divisor = -3;
    int result = divide(dividend, divisor);
    cout << result << endl;

    getchar();
}