/*
2014年巴西世界杯（2014 FIFA World Cup）开踢啦！为了方便球迷观看比赛，里约街道上很多路口都放置了的直播大屏幕，但是人群散去后总会在这些路口留下一堆垃圾。为此巴西政府决定动用一种最新发明——“垃圾炸弹”。这种“炸弹”利用最先进的量子物理技术，爆炸后产生的冲击波可以完全清除波及范围内的所有垃圾，并且不会产生任何其他不良影响。炸弹爆炸后冲击波是以正方形方式扩散的，炸弹威力（扩散距离）以d给出，表示可以传播d条街道。

    例如下图是一个d=1的“垃圾炸弹”爆炸后的波及范围。



    假设里约热内卢市的布局为严格的1025*1025的网格状，由于财政问题市政府只买得起一枚“垃圾炸弹”，希望你帮他们找到合适的投放地点，使得一次清除的垃圾总量最多（假设垃圾数量可以用一个非负整数表示，并且除设置大屏幕的路口以外的地点没有垃圾）。

输入
第一行给出“炸弹”威力d(1 <= d <= 50)。第二行给出一个数组n(1 <= n <= 20)表示设置了大屏幕(有垃圾)的路口数目。接下来n行每行给出三个数字x, y, i, 分别代表路口的坐标(x, y)以及垃圾数量i. 点坐标(x, y)保证是有效的（区间在0到1024之间），同一坐标只会给出一次。
输出
输出能清理垃圾最多的投放点数目，以及能够清除的垃圾总量。
*/
#include <iostream>
#include <cstring>
#define MAXN 1024

struct Node
{
    int x, y, garbageCount;
} a[21];

int main() {
//  freopen("in.txt", "r", stdin);
//  int cases;
//  scanf("%d", &cases);
//  while (cases--) {
        int d, n;
        scanf("%d", &d);
        scanf("%d", &n);
        int minX = MAXN, minY = MAXN, maxX = 0, maxY = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].garbageCount);
            //圈定搜索范围。
            minX = a[i].x < minX ? a[i].x : minX;
            minY = a[i].y < minY ? a[i].y : minY;
            maxX = a[i].x > maxX ? a[i].x : maxX;
            maxY = a[i].y > maxY ? a[i].y : maxY;
        }
        int maxSum = 0, maxSumCount = 0;
        //换成这种循环就不行，不知为何。
//      for (int r = minX - d; r <= maxX + d; r++) {
//          if ((r < 0) && (r > MAXN)) continue;
//          for (int c = minY - d; c <= maxY + d; c++) {
//              if ((c < 0) && (c > MAXN)) continue;

        for (int r = 0; r < 1025; r++) {
            for (int c = 0; c < 1025; c++) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i].x >= r - d && a[i].x <= r + d && a[i].y >= c - d && a[i].y <= c + d) {
                        sum += a[i].garbageCount;
                    }
                }
                if (sum > maxSum) {
                    maxSum = sum;
                    maxSumCount = 1;
                }
                else if (sum == maxSum) {
                    maxSumCount++;
                }
            }
        }
        printf("%d %d\n", maxSumCount, maxSum);
//  }
}
    return 0;

