#include <stdio.h>

/*
 堆排序(Heap_Sort),这里用到一个特别的数据结构--堆.具体结构可以参考数据结构相关书籍的定义.
 堆的定义如下:n个元素的序列{a[0],a[1],...,a[n-1]}当且仅当满足下关系时,称为堆.
             1). a[i] <= a[2*i+1] 且 a[i] <= a[2*i] (称为最小堆)
    或者满足:2). a[i] <= a[2*i+1] 且 a[i] <= a[2*i] (称为最大堆)
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
void Heap_create(int heap[],int nums)
{
    if(nums<1)   //堆中没元素,不需要调整  
        return ;
    
    int i = (nums-1-1)/2;//获取最后一个元素的父节点
    for (; i>=0; i--) 
	{
        //开始遍历结点,然后对该结点进行自上往下调整
        heap_adjust(heap,i,nums);
        printHeap(heap, nums);
    }
}
/*
 2)自上往下的堆调整,对当前pos 结点往它的子结点进行调整,保证该结点的值小于其子结点的.
 */
void heap_adjust(int heap[],int pos,int nums)
{
	int i = 0;
    for (i=2*pos+1; i<nums; i=2*i+1) 
	{
        if (i+1<nums&&heap[i+1]<heap[i]) 
		{//在左结点和右结点中找到较小的结点
            i++;
        }
        if (heap[(i-1)/2]>heap[i]) 
		{//较小的结点若比父节点小,则交换
            //swap(&heap[(i-1)/2], &heap[i]);
			int temp = heap[(i-1)/2];
			heap[(i-1)/2] = heap[i];
			heap[i] = temp;
        }
    }
}
void printHeap(int heap[],int n)
{
	int i=0;
    for (i=0; i<n; i++) 
	{
        printf("%d --- ",heap[i]);
    }
    printf("\n");
}
/*
 堆排序
 步骤:取堆顶元素与最后元素交换,堆长度相应-1,然后调整新堆,当取堆顶次数达到数组元素个数时,这时数组中的元素就是有序的了,这里是从大到小排序,因为每次从堆中取最小元素(最小堆)放在数组后面.(而最大堆得到的堆排序是从小到大的)
 */
void heap_sort(int heap[],int nums)
{
    if (nums<1) 
        return ;
    
    Heap_create(heap, nums);
    //printHeap(heap,nums);
    int i=0;
    for (i=nums-1; i>=1; i--) 
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
        heap_adjust(heap, 0, i);
    }
}

int main()
{
	int Numbers[10] = {1,4,2,3,4,5,6,11111,2222,333};
	heap_sort(Numbers,10);

	int i;
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}

	printf("\n");

	return 0;
}