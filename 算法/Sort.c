#include <stdio.h>

void inputArray(int arr[],int *nums){
    printf("please input the number of array:");
    scanf("%d",nums);
    printf("please input %d numbers:",*nums);
    int i = 0 ;
    for (; i<*nums; i++) {
        scanf("%d",&arr[i]);
    }
}
void printArray(int arr[],int nums){
    int i = 0 ;
    for (; i<nums; i++) {
        if (i==nums-1) {
            printf("%d\n",arr[i]);
        }else{
            printf("%d ->",arr[i]);
        }
    }
}
void swap(int *a,int *b){
    int temp  = *a;
    *a = *b;
    *b = temp;
}

//一.选择排序 从小到大排序
/*
 算法思路:i,j; n为数组长度，下标从0到n-1;
 i从0遍历到n-2:
    对于每个i:
        j每次从i+1遍历到n-1,选出[i,n-1]最小的元素下标minIndex,然后把该次遍历的最小元素arr[minIndex]与arr[i]交换.
    当i遍历完n-2时就确定了整个数组的有序.
 算法复杂度:O(n*n),核心在于记录一个最小值，然后换。
 */
void select_sort(int arr[],int nums){
    int i,j;
    for (i=0; i<nums-1; i++) {
        int minIndex = i;
        for (j=i+1; j<nums; j++) {
            if (arr[i]>arr[j]) {
                minIndex = j;
            }
        }
        if (minIndex!=i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}
//二.冒泡排序 从小到大排序
/*
 算法思路:
    i从0到n-2,对于每个i:
        j从n-1到i+1(递减1)，对于每个j：
            都要比较arr[j]和arr[j-1],如果arr[j]小于arr[j-1]则交换两数,确保每个arr[j-1]大于arr[j].
 这样对于每个i,j遍历完后,arr[i]是j从n-1遍历到i+1"冒泡"上来的最小值,这样i遍历完后,就确定了整个数组的有序了.
 算法复杂度为:O(n*n)，核心是相邻比较，将最小的往一个方向推。
 */
void bubble_sort(int arr[],int n){
    int i =0 ,j = 0 ;
    for (; i<n-1; i++) {
        for (j=n-1; j>i; j--) {
            if (arr[j]<arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}
//三.直接插入排序 从小到大排序
/*
 算法思路:
 i从0到n-2,对于每个i:   
    j从i+1递减到1,对于每个j:
        判断arr[j]和arr[j-1]，如果arr[j]<arr[j-1],则交换两数,否则跳出内循环.
 上面的整体思路是:每次把arr[j=i+1]的元素,插入到前面有序的子数组(arr[0],...,arr[i])中,当i=0,子数组为(arr[0]).
  算法复杂度为:O(n*n)，可以想象成打扑克，摸一张插一张。从一个方向比较，小于右边大于左边就放那里。
 */
void insert_sort(int arr[],int n){
    int i =0 , j = 0 ;
    for (i=0; i<n-1; i++) {
        for (j=i+1; j>0; j--) {
            if (arr[j-1]<arr[j]) {
                break;
            }
            swap(&arr[j-1], &arr[j]);
        }
    }
}


//四.希尔排序 从小到大排序
/* 希尔排序算法 也称缩小增量排序算法 是一种特殊的插入排序
    这里需要假设一个增量dk,
 我这里的dk一开始dk=3,然后每次循环递减1,dk--:
 对于每个增量长度dk,有:原数组的子数组(0,0+dk,0+2*dk,.....,0+i*dk),然后对该子数组进行直接插入排序.
 这里的dk的值可以按情况设置.
 我这里的是dk=3,dk=2,dk=1.
 
 总结希尔排序的算法复杂度有点麻烦,取于dk(dlta[k])的值和数组.
 有人指出,当dlta[k] = 2^(t-k+1)-1时,希尔排序的时间复杂度为:O(n^(3/2)),其中t为排序躺数. 1<=k<=t<=向下取整[log2 (n+1)]
 还有人经过大量实验,有,当n在特定范围内,希尔排序所需的比较和移动次数约为n^(1.3),当n->∞,可减少到n*(log2(n))^2*[2].
 */
void shell_sort(int arr[],int n){
    int dk = 3 ;
    int i = 0 ,j=0;
    for (dk = 3; dk>0; dk--) {
        //对于每个增量dk,对子数组进行直接排序
        for (i=0; i+dk<n; i+=dk) {
            for (j=i+dk; j-dk>=0; j-=dk) {
                if (arr[j]<arr[j-dk]) {
                    swap(&arr[j], &arr[j-dk]);
                }else{
                    break;
                }
            }
        }
    }
}


//五.快速排序 从小到大排序
/*
 快速排序是对冒泡排序的一种改进,基本思想是通过一趟排序将待排序记录分割成独立的两部分,其中左边的value比右边的value小,则然后再分别对这两部分递归处理,从而继续进行排序,以达到整个序列有序.
 每一趟都要选取一个枢轴pivotkey(这里选取pivotkey = arr[low]),遍历该当前部分的元素,默认把比pivotkey小的放在左边,比pivotkey大的放在右边,然后得到两个子数组,对该子数组再进行相同操作.
 这里设置了一个low和high,(low,high)作为该当前数组的第一个元素位置和最后一个元素位置,
 具体做法是:首先从high所指位置起向前搜索,找到第一个关键值比当前pivotkey小的元素,与枢轴记录互相交换,然后从low所指的位置起向后搜索,找到第一个关键值比pivotkey的元素,和枢轴记录相互交换,重复这两步直至low = high为止.
 
 算法时间复杂度为O(n*log2(n));
 
 */
int partition(int arr[],int low,int high){
    if (low>=high) {
        return low;
    }
    int pivotkey = arr[low];
    while (low<high) {
        while (low<high&&arr[high]>=pivotkey)high--;
        arr[low] = arr[high];
        while (low<high&&arr[low]<=pivotkey)low++;
        arr[high] = arr[low];
    }
    arr[low] = pivotkey ;
    return low ;
}
void quick_sort(int arr[],int low,int high){
    if (low>=high) {
        return;
    }
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
    
}


//六.堆排序 从大到小排序
/*
 堆排序(Heap_Sort),这里用到一个特别的数据结构--堆.具体结构可以参考数据结构相关书籍的定义.
 堆的定义如下:n个元素的序列{a[0],a[1],...,a[n-1]}当且仅当满足下关系时,称为堆.
             1). a[i] <= a[2*i+1] 且 a[i] <= a[2*i+2] (称为最小堆)
    或者满足:2). a[i] <= a[2*i+1] 且 a[i] <= a[2*i+2] (称为最大堆)
 其中, i=1,2,3,...,[n/2]向下取整
 这里的序列可以将一个一维数组相对应进行存储.
 
 堆的逻辑结构其实就是一个完全二叉树.第一个结点a[0]就是堆的根结点(就是堆顶),若是最小堆,则a[0]是最小堆的最小值的元素,若是最大堆,则a[0]是最大堆中的最大值元素.
    对于a[i]结点,它的左结点是a[2*i+1],右结点是a[2*i+2].
    对于某一结点a[k](除了根节点a[0],k!=0),其父节点是a[(k-1)/2].
 
 堆的基本函数有:
 1). 堆的创建(自下往上)
 2). 堆调整(自上往下调整)
 3). 取堆顶:访问堆的根节点,并删除该结点,其结点由堆最后的结点补上(堆顶与堆最后一个元素交换),并进行堆调整.
 4). 堆排序
 
 这里需要了解过堆的逻辑结构才能比较容易看懂函数代码,请先查阅相关数据结构的书籍再研究以下算法.
 */


/*
    以下是创建最小堆的例子,最小堆得到的堆排序是从大到小的,最大堆得到的堆排序是从小到大的.最大堆可以由读者来实现.
 */
void Heap_create(int heap[],int nums);
void heap_adjust(int heap[],int pos,int nums);
void printHeap(int heap[],int n);
void heap_sort(int heap[],int nums);
/*
 // 1)堆的创建(自下往上)
 步骤: 1) 假设待调整数组为heap[],其元素个数为nums,则从最后一个元素的父节点开始遍历调整,即从heap[(nums-1-1)/2]开始自上往下调整子堆.
 */
void Heap_create(int heap[],int nums){
    if(nums<1){
        //堆中没元素,不需要调整
        return ;
    }
    int i = (nums-1-1)/2;//获取最后一个元素的父节点
    for (; i>=0; i--) {
        //开始遍历结点,然后对该结点进行自上往下调整
        heap_adjust(heap,i,nums);
        printHeap(heap, nums);
    }
}
/*
 2)自上往下的堆调整,对当前pos 结点往它的子结点进行调整,保证该结点的值小于其子结点的.
 */
void heap_adjust(int heap[],int pos,int nums){
    int i = 0;
    for (i=2*pos+1; i<nums; i=2*i+1) {
        if (i+1<nums&&heap[i+1]<heap[i]) {//在左结点和右结点中找到较小的结点
            i++;
        }
        if (heap[(i-1)/2]>heap[i]) {//较小的结点若比父节点小,则交换
            swap(&heap[(i-1)/2], &heap[i]);
        }
    }
}
void printHeap(int heap[],int n){
    int i=0;
    for (i=0; i<n; i++) {
        printf("%d --- ",heap[i]);
    }
    printf("\n");
}
/*
 堆排序
 步骤:取堆顶元素与最后元素交换,堆长度相应-1,然后调整新堆,当取堆顶次数达到数组元素个数时,这时数组中的元素就是有序的了,这里是从大到小排序,因为每次从堆中取最小元素(最小堆)放在数组后面.(而最大堆得到的堆排序是从小到大的)
 */
void heap_sort(int heap[],int nums){
    if (nums<1) {
        return ;
    }
    Heap_create(heap, nums);
    //printHeap(heap,nums);
    int i=0;
    for (i=nums-1; i>=1; i--) {
        swap(&heap[0], &heap[i]);
        heap_adjust(heap, 0, i);
    }
}

int main(int argc, const char * argv[])
{
    int array[1024*1024]={0};
    int numberOfArray = 0;
    inputArray(array, &numberOfArray);
    
    //选择排序
    printf("排 序 前 :");printArray(array, numberOfArray);
    select_sort(array, numberOfArray);
    printf("选择排序后:");printArray(array, numberOfArray);
    printf("\n");
    
//     冒泡排序
//      printf("排 序 前 :");printArray(array, numberOfArray);
//      bubble_sort(array, numberOfArray);
//      printf("选择排序后:");printArray(array, numberOfArray);
//      printf("\n");
//      
//      //直接插入排序
//      printf("排 序 前 :");printArray(array, numberOfArray);
//      insert_sort(array, numberOfArray);
//      printf("直接插入排序后:");printArray(array, numberOfArray);
//      printf("\n");
//      
//      //希尔排序
//      printf("排 序 前 :");printArray(array, numberOfArray);
//      shell_sort(array, numberOfArray);
//      printf("希尔排序后:");printArray(array, numberOfArray);
//      printf("\n");
//      
//      //快速排序
//      printf("排 序 前 :");printArray(array, numberOfArray);
//      quick_sort(array, 0,numberOfArray-1);
//      printf("快速排序后:");printArray(array, numberOfArray);
//      printf("\n");
//      
//      //堆排序
//      printf("排 序 前 :");printArray(array, numberOfArray);
//      heap_sort(array, numberOfArray);
//      printf("堆排序后(从大到小):");printArray(array, numberOfArray);
//      printf("\n");
    
    return 0;
}

