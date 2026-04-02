#include <stdio.h>
#include <stdbool.h>

#include "zho_util.h"
#include "zho_sort.h"

static void base_insert_step_sort(int start, int step, int *array, int count);
static void adjust_heap(int root, int *array, int count);

static void base_insert_step_sort(int start, int step, int *array, int count) {
	int s_index = start;
	int index;
	int i;
	int t;
	int temp;
	
	for (index = start + step; index < count; index += step) {	//控制遍历编组所有元素
		temp = array[index];				//将未排序的第一个元素赋值给temp
		for (i = start; i <= s_index; i += step) {	//控制遍历已排序部分
			if (array[i] > temp) {					//查找已排序中待插入的位置
				break;
			}
		}
		
		for (t = s_index + step; t > i; t -= step) {	//将待插入位置到已排序位置结束的编组元素向右移动一个步长的距离
			array[t] = array[t - step];
		}
		
		array[i] = temp;		//将元素插入位置
		s_index += step;		//已排序部分下标标识增加一个步长
	}
}

static void adjust_heap(int root, int *array, int count) {
	int left_child;
	int right_child;
	int max_child;
	
	while (root <= count / 2 - 1) {			//当前节点存在叶子节点时入循环。
		left_child = (root + 1) * 2 - 1;	//获取当前节点的左节点坐标
		right_child = (root + 1) * 2;		//获取当前节点的右节点坐标
		max_child = (right_child >= count) ? (left_child) : (
				array[left_child] > array[right_child] ? left_child : right_child);	/*若不存在右节点时，max子节点为左节点；
														                            若存在右节点时，max子节点为左右节点中值较大的那个*/
		
		if (array[root] >= array[max_child]) {	//如果当前节点>=max节点时，不交换
			return;
		}
		
		swap_int(array + root, array + max_child);		//将max节点的值和当前节点的值替换。
		root = max_child;								//将max节点赋给当前节点。
	}
	
}

void heap_sort(int *array, int count) {
	int root;
	
	for (root = count / 2 - 1; root >= 1; root--) {	//从最后一个叶子节点的父节点开始遍历，直到根节点（即数组开头）的下个节点为止。
		adjust_heap(root, array, count);			//将当前子树变为大根树
	}
	
	while (count >= 1) {			//当编组中有数据时入循环
		adjust_heap(0, array, count);		//将根节点进行大根树变换
		swap_int(array + 0, array + count - 1);		//交换根节点和编组最后一个节点
		--count;		//编组末尾前移
	}											//本质：将数组由逆序排列变为顺序排列。由于前面选择排序无法将左右子节点进行排序，只能求出最大值
												//于是直接将换的的最大值的根节点与数组当前末尾交换，再在下个循环大根树变换后找到下个树的最大值的根节点，再次放入。
												//这样，我们就将一个排序变为了寻找当前树的最大值的问题，就可以得到正确的顺序排序的数组。
}

void Shell_sort(int *array, int count) {	//希尔排序
	int step;
	int start;
	
	for (step = count / 2; step; step /= 2) {	//控制步长循环减半
		for (start = 0; start < step; start++) {	//控制遍历步长内的每个元素作编组首元素
			base_insert_step_sort(start, step, array, count);
		}
	}
}

void base_swap_sort(int *array, int count) {
	int i;
	int index;
	int tmp;
	bool has_swap;
	
	for (i = 0; i < count - 1; i++) {
		has_swap = false;
		for (index = 0; index < count - i - 1; index++) {
			if (array[index] > array[index + 1]) {
				has_swap = true;
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
			}
		}
		
		if (!has_swap) {
			return;
		}
	}
}

void base_select_sort(int *array, int count) {
	int index;
	int min_index;
	int i;
	int tmp;
	
	for (index = 0; index < count - 1; index++) {
		for (min_index = index, i = index + 1; i < count; i++) {
			if (array[i] < array[min_index]) {
				min_index = i;
			}
		}
		
		if (min_index != index) {
			tmp = array[min_index];
			array[min_index] = array[index];
			array[index] = tmp;
		}
	}
}

void base_insert_sort(int *array, int count) {
	int s_index = 0;
	int index;
	int i;
	int t;
	int temp;
	
	for (index = 1; index < count; index++) {
		temp = array[index];
		for (i = 0; i <= s_index; i++) {
			if (array[i] > temp) {
				break;
			}
		}
		
		for (t = s_index + 1; t > i; t--) {
			array[t] = array[t - 1];
		}
		
		array[i] = temp;
		++s_index;
	}
}
