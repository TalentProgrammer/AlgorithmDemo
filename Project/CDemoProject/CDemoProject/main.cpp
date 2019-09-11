#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>

int plus(int x, int y)
{
    return x * y;
}

//void getNarcissisticNumbers(int n)
//{
//    int nStart;
//    int nEnd;
//    if (n == 1)
//    {
//        nStart = 0;
//    }
//    else
//    {
//        nStart = pow(10, (n - 1));
//    }
//
//    nEnd = pow(10, n);
//    int nTotal = 0;
//    std::string str;
//    for (; nStart < nEnd; nStart++)
//    {
//        sprintf(str.c_str(), "%d", nStart);
//        std::string str = ch[0];
//        {
//            printf("%d\n", nStart);
//        }
//    }
//
//    //1  // int sprintf( char *buffer, const char *format, [ argument] … );
//    //    2  //参数列表
//    //    3  // buffer：char型指针，指向将要写入的字符串的缓冲区。
//    //    4  // format：格式化字符串。
//    //    5  // [argument]...：可选参数，可以是任何类型的数据。
//    //    6  // 返回值：字符串长度（strlen）
//    //    7
//    //    8  int aa = 30;
//    //9  char c[8];
//    //10  int length = sprintf(c, "%05X", aa);
//
//    //int nBit = 0;
//    //while (n % 10 > 0)
//    //{
//    //    n = n % 10;
//    //    nBit++; // 位数
//    //}
//
//    //int nNum = nBit;
//    //int nTotal = 0;
//    //while (nNum > 0)
//    //{
//    //    nTotal += (n / (10 ^ (nBit - 1))) ^ nNum;
//    //    nNum--;
//    //}
//    int x = 0;
//}
//

void GetNShuiNum(int nBit)
{
    int a[20] = { 0 }; // 存储个 十 百 千等的位数
    int i = 100; // 默认位数 >= 3
    int l = 3;   // 位数
    int k = (int)pow(10, nBit);

    while (i >= 10 && i < k && l <= nBit)
    {
        int sum = 0;
        int temp = i;
        if (i >= pow(10, l - 1) && i < pow(10, l))
        {
            for (int j = 0; j < nBit; j++)
            {
                a[j] = temp % 10;
                temp /= 10;
                sum += pow(a[j], l);
            }
            if (i == sum)
            {
                printf("%d\n", i);
            }
        }
        else
        {
            l++;
        }
        i++;
    }
}

void Fun()
{
    while (1)
    {
        printf("*********");
    }
}

int check()
{
    int arr[8];
    arr[9] = (int)&Fun;
    return 0;
}

void main()
{
    //plus(1, 2);
    //GetNShuiNum(3);
    check();
    getchar();
    return;
}

