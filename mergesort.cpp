
#include <bits/stdc++.h>
using namespace std;
int f1, f2, f3=0;


int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
		
	return (int)ceil(gap / 2.0);
}


void swap(int nums[], int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}



void inPlaceMerge(int nums[], int start,
							int end)
{
	int gap = end - start + 1;
	
	for(gap = nextGap(gap);
		gap > 0; gap = nextGap(gap))
	{
		for(int i = start; i + gap <= end; i++)
		{
			int j = i + gap;
			if (nums[i] > nums[j])
				swap(nums, i, j);
				f2++;
		}
		f1++;
	}
}


void mergeSort(int nums[], int s, int e)
{
	if (s == e)
		return;


	int mid = (s + e) / 2;

	
	mergeSort(nums, s, mid);
	mergeSort(nums, mid + 1, e);
	
	inPlaceMerge(nums, s, e);
}


int main()
{
	int nums[] = {2,3,4,5,6,7,8,9,15};
	int nums_size = sizeof(nums) / sizeof(nums[0]);

	
	mergeSort(nums, 0, nums_size-1);
	
	for(int i = 0; i < nums_size; i++)
	{
		cout << nums[i] << " ";
		f3++;
	}
	cout<<"\nf1:"<<f1;
	cout<<"\nf2:"<<f2;
	cout<<"\nf3:"<<f3;
	return 0;
}



