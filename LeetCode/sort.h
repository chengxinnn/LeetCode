#pragma once
#pragma warning(disable:4996)
#include <time.h>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <array>
#include <memory>

const int thread_num = 4;



using namespace std;

template <class T>
void mergee(vector<T>&a, vector<T>&b, int left, int mid, int right);


//******************************** ð������ **********************************
//******************************** ð������ **********************************
void bubblesort(vector<int>&vec)
{
	int size = vec.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (vec[j] < vec[j - 1])
				swap(vec[j], vec[j - 1]);
	}
}



//******************************** �������� **********************************
//******************************** �������� **********************************
template <typename T>
void insertSort(vector<T>&nums)
{
	if (nums.size() <= 1) return ;
	int n = nums.size(), minele = 0;
	for (int i = 1; i < n; i++)
		if (nums[i] < nums[i - 1])
		{
			minele = nums[i];
			int j = i;
			while(--j >= 0)
				if (nums[j] > minele)
					nums[j + 1] = nums[j];
				else break;
			nums[j + 1] = minele;
		}
}

//******************************** ϣ������  **********************************
//******************************** ϣ������ **********************************
template <typename T>
void shellSort(vector<T>&vec)
{
	int size = vec.size();
	if (size <= 1) return;
	int i, j,minele, gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = gap; i < size; i+= gap)
			if (vec[i] < vec[i - gap])
			{
				minele = vec[i];
				for(j = i - gap; j >= 0 && vec[j] > minele; j -= gap)
					vec[j + gap] = vec[j];
				vec[j + gap] = minele;
			}
	}
}


//********************************��������**********************************
//********************************��������**********************************
/*
��������ѡȡĳһ��ֵ��Ϊ��׼��С�ڸû�׼ֵ��Ԫ�ط����������ߣ� ���ڸû�׼ֵ��Ԫ�ط���������ұߡ�
�����Ч��ȡ���ڻ�׼ֵ��ѡ��
�������£�������������ʱ�򣬻�׼ֵ���Ƿָ�һ��Ԫ���Լ�n-1��Ԫ�أ���ʱ�临�Ӷȴﵽn����
����õ�����£�ÿ��ѡȡ�Ļ�׼ֵ������ֵ����ôÿ�ζ��ܻ�������N/2��������ʱ�临�Ӷ�Ϊnlgn��
*/
template <class T>
int partition(vector<T>&vec, int left, int right)
{
	if (left >= right) return left;
	int pivot = vec[left];
	while (left < right)
	{
		while (left < right && vec[right] > pivot) right--;
		vec[left] = vec[right];
		while (left < right && vec[left] <= pivot)  left++;
		vec[right] = vec[left];

	}
	vec[left] = pivot;
	return left;
}


template<class T>
void quickSort(vector<T>& nums, int left , int right)
{
	if (left >= right) return;
	if (left < right)
	{
		int pivot = partition(nums, left, right);
		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);

	}

}

void quicksort(vector<int>&nums)
{
	int size = nums.size();
	quickSort(nums, 0, size - 1);
}

//********************************��������Ľ�1**********************************
int partition_three(vector<int>&nums, int left, int right)
{
	int mid = left + (right - left) >> 1;
	if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
	if (nums[left] > nums[right]) swap(nums[left], nums[right]);
	if (nums[mid] > nums[left]) swap(nums[mid], nums[left]);
	int pivot = nums[left];
	while (left < right)
	{
		while (right > left && nums[right] > pivot) right--;
		nums[left] = nums[right];
		while (left < right && nums[left] <= pivot) left++;
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;
}
void quicksort_three(vector<int>&nums,const int left,const int right)
{
	if (left >= right) return;
	if (left < right)
	{
		int pivot = partition_three(nums, left, right);
		quicksort_three(nums, left, pivot - 1);
		quicksort_three(nums, pivot + 1, right);
	}
}

void quickSort_three(vector<int>&nums)
{
	int n = nums.size();
	quicksort_three(nums, 0, n - 1);

}
//********************************��������Ľ�1**********************************

//********************************��������Ľ�2**********************************
/*
�����Ŵﵽһ������Ժ󣬻��ֵ������С����ʹ�ÿ��ŵ�Ч�ʲ��ߡ�
�;�����ԣ������ŵĳ���Ϊ5-20��ʱ���ò���������Ա���һЩ�˷ѡ�
*/
void quicksort_insert(vector<int>&nums, int left, int right)
{
	if (right - left + 1 <= 5) insertSort(nums);
	if (left < right)
	{
		int pivot = partition_three(nums, left, right);
		quicksort_three(nums, left, pivot - 1);
		quicksort_three(nums, pivot + 1, right);
	}
}

void quickSort_insert(vector<int>&nums)
{
	int n = nums.size();
	quicksort_three(nums, 0, n - 1);
}
//********************************��������Ľ�2**********************************


//********************************��������Ľ�3**********************************
/*
�ݹ�����ں���ִ�е������䣬���䷵��ֵ�������ڱ��ʽ��һ���ֵ�ʱ��
����ݹ���þ���β�ݹ���ã�������β�ݹ��Ż������ٶ�ջ����ȣ���O��n) ����Ϊ O(lgn)��
*/
void quicksort_tail(vector<int>&nums, int left, int right)
{
	if (right - left + 1 > 5) insertSort(nums);
	while (left < right)
	{
		int pivot = partition_three(nums, left, right);
		quicksort_tail(nums, left, pivot - 1);
		left = pivot + 1;
	}
}

void quickSort_tail(vector<int>nums)
{
	int size = nums.size();
	quicksort_tail(nums, 0, size - 1);
}

//********************************��������Ľ�3**********************************


//********************************��������Ľ�4**********************************
/*
�ۼ�Ԫ���Ż���
ÿ��ѡȡ��׼ֵ�󣬽���С��ͬ��׼ֵ��Ԫ�ط��ڻ�׼ֵ����Χ���������򣬡����ɴ����ظ�Ԫ�ص�ʱ����Ч
*/
//********************************��������Ľ�4**********************************


//********************************��������Ľ�5**********************************
/*
���߳�
*/
#include <mutex>
mutex m;
void quicksort_thread(vector<int>&nums, const int left, const int right)
{
	if (left >= right) return;
	if (left < right)
	{
		int pivot = partition_three(nums, left, right);
		thread t1(quicksort_thread, ref(nums), left, pivot - 1);
		thread t2(quicksort_thread, ref(nums), pivot + 1, right);
		t1.join();
		t2.join();
		lock_guard<mutex>muguard(m);
	}
}

void quickSort_thread(vector<int>&nums)
{
	int size = nums.size();
	int gap = int(float(size) / thread_num + 0.5);;
	array<thread, thread_num>threads;
	vector<int>temp(size);
	
	for (int i = 0; i < thread_num; i++)
	{ 
		if (i != thread_num - 1)
		{
			int left = gap * i, right = gap *(i + 1) - 1;
			threads[i] = thread(quicksort_three, ref(nums), left, right);
			threads[i].join();
			lock_guard<mutex>muguard(m);
		}
		else
		{
			threads[i] = thread(quicksort_three, nums, gap * i, size - 1);
			threads[i].join();
			lock_guard<mutex>muguard(m);

		}

	}

	mergee(nums, temp, 0, gap - 1, 2 * gap - 1);
	mergee(nums, temp, 2 * gap, 3 * gap - 1, size - 1);
	mergee(temp, nums, 0, 2 * gap - 1, size - 1);
}

//********************************��������Ľ�5**********************************

//********************************���������ȶ���**********************************
int spartition(int A[], int p, int r)
{
	int x, i, j, a1, a2, b1, b2, len;

	len = r - p;
	i = p;
	j = r;
	a1 = p;
	a2 = r - 1;
	b1 = -1;
	b2 = len;

	int *B = (int *)malloc(len * sizeof(int));
	memset(B, 0, len * sizeof(int));
	B[++b1] = A[i];
	x = A[i];

	while (1) {
		while (A[--j] > x && i < j) {
			A[a2--] = A[j];
		}
		while (A[++i] <= x && i <= j) {
			A[a1++] = A[i];
		}
		if (i < j) {
			B[++b1] = A[i];
			B[--b2] = A[j];
		}
		else {
			break;
		}
	}
	if (b2 < len) {
		memcpy(&A[a1], &B[b2], sizeof(int)* (len - b2));
		a1 += len - b2;
	}
	memcpy(&A[a1], &B[0], sizeof(int)* (b1 + 1));

	return a1;
}

int stable_partition(vector<int>& a, int left, int right) {
	if (left >= right) return left;


	vector<int>b(right - left + 1, 0);
	int pa1 = left, pa2 = right, pb1 = 0, pb2 = right - left;
	int pivot = a[left];
	while (pa1 < pa2)
	{
		while (pa1 < pa2 && a[pa1] < pivot)
			a[left++] = a[pa1++];
		while (pa1 < pa2 && a[pa2] >= pivot)
			a[right--] = a[pa2--];
		if (pa1 < pa2)
		{
			b[pb1++] = a[pa1++];
			b[pb2--] = a[pa2--];
		}
	}
	for (int i = pb2 + 1; i < b.size(); i++)
		a[left++] = b[i];
	for (int i = pb1 - 1; i >= 0; i--)
		a[right--] = b[i];
	return left;
}

void quicksort_stable(int nums[], const int left, const int right)
{
	if (left >= right) return;
	if (left < right)
	{
		int pivot = spartition(nums, left, right);
		quicksort_stable(nums, left, pivot);
		quicksort_stable(nums, pivot + 1, right);
	}
}

void quickSort_stable(vector<int>&nums)
{
	int n = nums.size();
	quicksort_stable(&nums[0], 0, n);

}
//********************************���������ȶ���**********************************




//********************************  �鲢����ĵݹ�ʵ�� **********************************
//********************************  �鲢����ĵݹ�ʵ�� **********************************
/*
�鲢����ĵݹ�ʵ��
*/
template <class T>
void mergee(vector<T>&a, vector<T>&b, int left, int mid, int right)
{
	int j = left, k = mid + 1, l = left;
	for (; j <= mid && k <= right; l++)
	{
		if (a[j] < a[k]) { b[l] = a[j++]; }
		else b[l] = a[k++];
	}
	while (j <= mid) b[l++] = a[j++];
	while (k <= right) b[l++] = a[k++];
}

template<class T>
void mergesort(vector<T>&nums, vector<T>&temp, int left, int right)
{
	if (left < right)
	{
		
		int mid = (left + right) >> 1;
		mergesort(nums, temp, left, mid);
		mergesort(nums, temp, mid + 1, right);
		mergee(nums, temp, left, mid, right);
		for (int i = left; i <= right; i++)
			nums[i] = temp[i];
	}
}

template <class T>
void mergeSort(vector<T>&nums)
{
	int size = nums.size();
	vector<int>a(size, 0);
	mergesort(nums, a, 0, size - 1);
}
//******************************** �ǵݹ�ʵ�ֹ鲢����  **********************************
//********************************  �ǵݹ�ʵ�ֹ鲢���� **********************************
/*
2.�ǵݹ�ʵ�ֹ鲢����
1)   ����˼�룺
�������е�����Ԫ��������ԡ���Merge()�������������򣬹���n/2�鳤��Ϊ2������õ�������Σ�Ȼ���ٽ����Ǻϲ��ɳ���Ϊ4��������Σ���˼�����ȥ��ֱ�����������ź���
*/
template<class T>
void mergeSort1(vector<T>&nums)
{
	int n = nums.size();
	vector<T>temp(n, 0);
	int gap = 1;
	while (gap < n)
	{
		int i = 0;
		while (i + 2 * gap - 1 < n)
		{
			mergee(nums, temp, i, i + gap - 1, i + 2 * gap - 1);
			i += 2 * gap;
		}
		if (i + gap < n)
			mergee(nums, temp, i, i + gap - 1, n - 1);
		else
			while (i < n) { temp[i] = nums[i]; i++; };
		nums.swap(temp);
		gap *= 2;
	}
}
//********************************   **********************************
//********************************   **********************************




//******************************** ��Ȼ�ϲ�����  **********************************
//******************************** ��Ȼ�ϲ�����  **********************************
/*
3.��Ȼ�ϲ�����
1)����˼�룺
���ڳ�ʼ����������a��ͨ�����ڶ�����ȴ���1�����ź����������Ρ������һ�ζ�a������ɨ��Ϳ����ҳ�������Щ�ź����������Σ�Ȼ�����ڵ��ź����������������ϲ�
2)������
������a��Ԫ��Ϊ{ 4,8,3,7,1,5,6,2}������Ȼ�ź�������������{ 4,8 }��{ 3,7 }��{ 1,5,6 }��{ 2 }����һ�κϲ���õ�2���ϲ�����������{ 3,4,7,8 }��{ 1,2,5,6 }�������ϲ������ź����������Σ�ֱ�������������ź������ս��{ 1,2,3,4,5,6,7,8 }
*/
template<class T>
int  mergePass(vector<T>&nums, vector<int>&ll)
{
	int size = nums.size();
	ll.resize(0);
	ll.emplace_back(0);
	T begin = nums[0];
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (nums[i] < begin)
		{
			ll.emplace_back(i);
			count++;
		}
		begin = nums[i];
	}
	
	ll.push_back(size);
	count++;
	return count;
}

template<class T>
void mergeSort2(vector<T>&nums)
{
	int size = nums.size();
	vector<T>ll, temp(size, 0);
	while (mergePass(nums, ll) != 2)
	{
		for (int i = 0; i < ll.size() - 2; i+= 2)
		{
			mergee(nums, temp, ll[i], ll[i + 1] - 1, ll[i + 2] - 1);
			for (int j = ll[i]; j <= ll[i + 2] - 1; j++)
				nums[j] = temp[j];
		}

	}


}

//********************************  ѡ������ **********************************
//********************************  ѡ������ **********************************
void selectsort(vector<int>&vec)
{
	int size = vec.size();
	for (int i = 0; i < size - 1; i++)
	{
		int pos = min_element(vec.begin() + i + 1, vec.end()) - vec.begin();
		if(i != pos) swap(vec[i], vec[pos]);

	}
}


//********************************  ������ **********************************
//********************************  ������ **********************************

void heapAdjust(vector<int>&vec, int root, int len)
{
	int l = 1 + (root << 1);
	if (l < len)
	{
		int r = l + 1 < len ? l + 1 : l;
		int maxson = vec[l] > vec[r] ? l : r;
		if (vec[maxson] > vec[root])
		{
			swap(vec[root], vec[maxson]);
			heapAdjust(vec,maxson, len);
		}
	}
}


void heapsort(vector<int>&vec)
{
	int size = vec.size();
	for (int i = size / 2 - 1; i >= 0; i--)
		heapAdjust(vec, i, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(vec[0], vec[i]);
		heapAdjust(vec, 0, i);
	}

}

//********************************  �������� **********************************
//********************************  �������� **********************************
/*
��������
*/
class newint
{
public:
	int x;
	newint() { x = 0; };
	newint(int z) :x(z) {};

	~newint() {
		//cout << "i " << x << " dead" << endl;
	};
};

void countsort(vector<int>&vec)
{
	int size = vec.size(), mine = INT_MAX, maxe = INT_MIN;
	for (const int & x : vec)
	{
		maxe = max(maxe, x);
		mine = min(mine, x);
	}
	unique_ptr<newint[]>count(new newint[maxe - mine + 1]());
	for (const int & x : vec)
		count[x - mine].x++;
	for (int i = 1; i < maxe - mine + 1; i++)
		count[i].x += count[i - 1].x;
	vector<int>temp(vec.begin(), vec.end());
	for (int i = size - 1; i > -1; i--)
	{
		vec[count[temp[i] - mine].x - 1] = temp[i];
		count[temp[i] - mine].x--;
	}
}
//********************************   **********************************
//********************************   **********************************
/*
Ͱ����
Ͱ�����ǶԼ��ϲ��Ϊ���Ͱ������ͬһֵ���Ԫ�ش���һ��Ͱ�С�
��ÿ��Ͱ�е�Ԫ�ؽ�����������Ͱ�е�Ԫ�ع��ɵļ���Ҳ��������ġ�
����Ҫȷ�������е������СԪ���Լ�ӳ�������ȷ��Ͱ�ĸ�����
���������������н�ģ���Ԫ�ؾ��ȷֲ�ʱ��Ч�ʸߡ�
*/
void bucketsort(vector<int>&vec)
{
	int size = vec.size(), mx = *max_element(vec.begin(), vec.end()), mn = *min_element(vec.begin(), vec.end());
	int diff = mx - mn;
	vector<vector<int>> buck(diff / 10 + 1);
	for (const int & x : vec)
		buck[(x - mn) / 10].push_back(x);
	int id = 0;
	for (int i = 0; i < diff / 10 + 1; i++)
	{
		sort(buck[i].begin(), buck[i].end());
		for (const int & x : buck[i])
			vec[id++] = x;
	}
}

//********************************   **********************************
//********************************   **********************************
/*
��������
��������Ҳ�Ƿ���ʽ����ͨ����Ԫ�ذ�λ�Ƚϣ�������벻ͬ��Ͱ��
������������ȶ���
��������Ļ���˼�룺�����е���ֵͳһΪͬ������λ���ȣ�����ĸ�λ���㡣Ȼ������λ��ʼ��һ�ν�������ֱ�����λ��
���͵Ŀռ任ʱ��ķ�ʽ�����������ݵ�ʱ�򣬻��ڴ������
�����и����������������
*/
void radixsort(vector<int>&vec)
{
	vector<vector<int>>buck(10, vector<int>(vec.size(), 0));
	vector<int>temp(10, 0);
	int mx = *max_element(vec.begin(), vec.end());
	int mxlen = to_string(mx).size();

	int id, m, n;

	for (int i = 0; i < mxlen; i++)
	{
		for (int & x : vec)
		{
			id = x / static_cast<int>(pow(10, i)) % 10;
			buck[id][temp[id]++] = x;
		}
		m = 0, n = 0;
		for (const int & x : temp)
		{
			for (int k = 0; k < x; k++)
				vec[m++] = buck[n][k];

			temp[n++] = 0;
		}


	}
}

//********************************   **********************************
//********************************   **********************************

void sorts(void(*func)(vector<int>&nums), vector<int>vec, string sortans)
{

	LARGE_INTEGER start, end, tc;
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&start);
	func(vec);
	QueryPerformanceCounter(&end);
	cout << "******" << sortans << " ��ʱ ��" << float(end.QuadPart - start.QuadPart) / float(tc.QuadPart) * 1000 << endl;
	for_each(vec.begin(), vec.end(), [](int&x) {cout << x << " "; });
	cout << endl; cout << endl;
}

void init()
{
	const int size = 50;
	vector<int>nums(size, 0);
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		nums[i] = rand() % (size);
	}
	cout << "����ǰ����Ϊ  ��";
	for_each(nums.begin(), nums.end(), [](int&x) {cout << x << " "; });
	cout << endl;
	vector<int>nums1 = nums;
	vector<int>nums2 = nums;
	vector<int>nums3 = nums;
	vector<int>nums4 = nums;
	vector<int>nums5 = nums;


	LARGE_INTEGER start, end, tc;
	QueryPerformanceFrequency(&tc);

	//ð������
	sorts(bubblesort, nums, "ð������");
	//���š�
	sorts(quicksort, nums, "����");
	//������ֵȡ�С�
	sorts(quickSort_three, nums, "����-��ֵȡ��");
	//���Ų��롣
	sorts(quickSort_insert, nums, "����-��������");
	//����-�ȶ���
	sorts(quickSort_stable, nums, "����-�ȶ���");



	//��������
	sorts(insertSort, nums, "��������");
	//ϣ������
	sorts(shellSort, vector<int>({ 49, 38, 65, 97, 76, 13, 27, 49, 55, 04 }), "ϣ������");



	//�鲢����
	sorts(mergeSort, nums, "�鲢����");
	//�鲢����-�ǵݹ�
	sorts(mergeSort1, nums, "�鲢����-�ǵݹ�");
	//��Ȼ�ϲ�����
	sorts(mergeSort2, nums, "�鲢����-��Ȼ�ϲ�����");

	//ѡ������
	sorts(selectsort, nums, "ѡ������");
	//������
	sorts(heapsort, nums, "������");


	//��������
	sorts(countsort, nums, "��������");
	//Ͱ����
	sorts(bucketsort, nums, "Ͱ����");
	//��������
	sorts(radixsort, nums, "��������");

}

