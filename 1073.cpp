#include <iostream>
#include <string>
#include <cmath>
#define корень sqrt
#define корень_из_N sqrtN
#define пока while
#define счетчик iter
#define счетчик2 jiter
#define счетчик3 kiter

#define целое int
#define глав main
#define ввод cin
#define вывод cout
#define класс class
#define статическое static
#define публичное public
#define новое new
#define массив get_aray
#define вернуть return
#define решатель solver
#define если if
#define коли if
#define при if
#define иначе else
#define коли_нет else
#define минимум min
#define прервать break
#define ы //
#define кореньN1 sqrtN1
#define один 1
#define половина 0.5
#define нецелое float
#define корень_макс_N 250 // Корень от макс N
#define макс_N 60500
#define цикл for

//Митя если ты скачал это с моего гитхаба, не списывай пожалуйста решай задачи сам

ы ы
ы ы ы
ы ы ы ы

статическое целое d[корень_макс_N][макс_N];

using namespace std;
ы
целое решатель(целое N);
целое глав()
{

    целое N;
    ввод >> N;
//     целое корень_из_N = корень(N);
//     если((целое)((нецелое)корень(N)-половина)<корень_из_N){корень_из_N+=один;}
    вывод << решатель(N)<<"\n";
    вернуть 0;

}
целое решатель(целое N)
{
        если (N==0) return 0;
        цикл (целое счетчик=1; счетчик*счетчик<макс_N; счетчик++)
        {
        коли (счетчик*счетчик==N) вернуть один;
        }
        цикл (целое счетчик=1; счетчик*счетчик<макс_N; счетчик++)
        {
            цикл (целое счетчик2=1; счетчик*счетчик+счетчик2*счетчик2<макс_N; счетчик2++)
            {
                коли (счетчик*счетчик+счетчик2*счетчик2==N) вернуть 2;
            }
        }
        цикл (целое счетичик3=1; счетичик3*счетичик3<макс_N; счетичик3++)
        {
            цикл (целое счетчик=1; счетчик*счетчик+счетичик3*счетичик3<макс_N; счетчик++)
            {
                цикл (целое счетчик2=1; счетчик*счетчик+счетчик2*счетчик2+счетичик3*счетичик3<макс_N; счетчик2++)
                {
                    коли (счетичик3*счетичик3+счетчик*счетчик+счетчик2*счетчик2==N) вернуть 3;
                }
            }
        }
        вернуть 4;
}

//     целое кореньN1 = корень_из_N;
//     целое счетчик = один;
//     пока (счетчик<макс_N)
//     {
//         счетчик+=один;
//         d[кореньN1][счетчик]=корень_макс_N;
//
//         вывод<<"Я завис тут 1  "<< счетчик << "\n";
//     }
//
//     d[кореньN1][0]=0;
//     счетчик = корень_из_N;
//     пока(счетчик>0)
//     {
//         счетчик-=один;
//         d[счетчик][0]=0;
//         целое счетчик2=один;
//         счетчик2=один;
//         пока(счетчик2<=N)
//         {
//             счетчик2+=один;
//             d[счетчик][счетчик2]=d[счетчик+один][счетчик2];
//             коли(счетчик2>=счетчик*счетчик)
//             {
//
//                 вывод<<"Я завис тут 2"<<"\n";
//                 d[счетчик][счетчик2]=минимум(один+d[счетчик][счетчик2-счетчик*счетчик], d[счетчик+один][счетчик2]);
//             }
//             d[счетчик][счетчик2]=минимум(d[счетчик][счетчик2], d[счетчик+один][счетчик2]);
//
//         }
//
//     }
//     вывод<<d[один][N]<<"\n"; ы ы ы ы ы


//     Это решение неправильно, жадный алгоритм неправильно решает задачу

//     целое счетчик = 0;
//     пока(корень_из_N>0)
//     {
//
//         cout << корень_из_N*корень_из_N << "\n";
//         счетчик+=1;
//         N-=(корень_из_N*корень_из_N);
//         корень_из_N = корень(N);
//     }
//     счетчик+=1;

//     вывод<<счетчик;


    //Как решать через динамику не понял (вроде выразил формулу, но ниче не получилось) - Решаю через теорему Лагранжа


//     вернуть 0;
/*
}*/
/*
 Метод Лагранжа (не дописал чуть)
целое решатель(целое N)
{
    целое корень_из_N = корень(N);
    при(N == корень_из_N*корень_из_N) вернуть 1;
    иначе
    {
        целое a, b ;
        счетчик=корень_из_N;
        пока (счетчик > 0)
        {
            a = n - корень_из_N*корень_из_N;
            b = корень(a)
            коли(корень_из_N<b) прервать;
            коли_нет если(a == корень_из_N*корень_из_N) вернуть 2;
            счетчик-=1;
        }
        счетчик=корень_из_N;


        пока (счетчик > 0)
        {
            a = n - корень_из_N*корень_из_N;
            b = корень(a)
            коли(корень_из_N<b) прервать;
            коли_нет если(a == корень_из_N*корень_из_N) вернуть 2;
            счетчик-=1;
        }
    }
    вернуть 0;
}*/



//Классный жираф
// _____________________***
// ______________***___*___*
// _____________*___*__*_**__***
// ______________*___*_**___*___*
// ______________******_*__*__**
// _____________***____****__*
// _______********_______*********
// _____*_______*_____**__*_______*
// ____*_**______*___***___**___**
// ____*_**_***___*____**__*_***
// ____**___***___*___*__***
// _____*________*___*__*__*
// ______***____*****___*__*
// _________****____*___*__*
// _________________*____*_*
// _________________*_____**
// _________________***____*
// _________________*__*___*
// _________________*__*___*
// _________________***__***
// ________________*____*__*
// ________________*___*___*
// _______________*___*____*
// _______________*____**___*_________*****
// ______________*_______*****_______*_____*
// ______________****_________*******______*
// _____________*____*___________*****_____***
// _____________*_____*___**____*_____*___*___*
// ____________*___****__*_*_____***___*___***
// ___________**__*_____**__***_____*****
// __________*__**____**_______*________*
// _________*__________********___*******
// ________*______________________********
// _______*______________________________*
// ______*_____**______*******______*____*
// _____*_____*__*____*_______*____*_*___*
// ____*_____*___*____*________*___*__*___*
// ____******____*___**________*___*__******
// ____*****____******_________*****__******
// _____**_______****__________*****
