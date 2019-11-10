/*
 *  解法1：使用二叉树作为存储结构，节点需要一个计数器，保存已自己为根节点的子节点个数。
 *  解法2：维护一个K元素的数组，正序排列，新添加的元素如果小于最小值则丢弃，大于则插入进去，并返回第K大元素
 */
typedef struct tnode{
    int key;
    int nums;
    struct tnode *left, *right;    
}*tNode;

typedef struct{
    tNode root;
    int kth;
} KthLargest;

tNode newNode(int key)
{
    tNode n = (tNode)calloc(1, sizeof(struct tnode));
    n->key = key;
    n->nums = 1;
    return n;
}

tNode insertNode(tNode root, int key)
{
    tNode n;
    
    if (!root)
    {
        n = newNode(key);
        return n;
    }  
    n = root;
    while (n)
    {
        
        if (n->key == key)
        {
            n->nums++;
            break;
        }
        else if (n->key > key)
        {
            if (n->left)
                n = n->left;
            else
            {
                n->left = newNode(key);
                break;
            }
        }else{
            if (n->right)
                n = n->right;
            else
            {
                n->right = newNode(key);
                break;
            }                
        }
    }
    return root;
}

void freetNode(tNode root)
{
    tNode n;
    if (root->left)
        freetNode(root->left);
    if (root->right)
        freetNode(root->right);
    free(root);
    return;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    int i = 0;
    KthLargest* obj = (KthLargest*)calloc(1, sizeof(KthLargest));
    obj->kth = k;
    while (i < numsSize)
    {
        obj->root = insertNode(obj->root, nums[i]);
        i++;
    }
    return obj;
}


int findKthInBST(tNode root, int k, int *t)
{
    int ret;
    tNode n = root;

    if (root->right)
        ret = findKthInBST(root->right, k, t);
        if (*t >= k)
            return ret;
    
    *t = *t + root->nums;
    if (*t >= k)
        return root->key;
    if (root->left)
        ret = findKthInBST(root->left, k, t);
        if (*t >= k)
            return ret; 
    
    return -1;
}

//每次添加一个数都要返回当前第K大的数
int kthLargestAdd(KthLargest* obj, int val) {
    int t = 0;
    obj->root = insertNode(obj->root, val);
    return findKthInBST(obj->root, obj->kth, &t);
}

void kthLargestFree(KthLargest* obj) {
    freetNode(obj->root);
    free(obj);
    return;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/

/*==================================================*/
//排名第一的堆排序解法

typedef struct {
	int *data;
	int size, n;
} KthLargest;

int kthLargestAdd(KthLargest* obj, int val);

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest *obj = (KthLargest*) malloc (sizeof(KthLargest));
	//0下标保留不用
	obj->data = (int*) malloc (sizeof(int) * (k + 1));
	obj->size = k;
	obj->n = 0;
	for (int i = 0; i < numsSize; i++) {
		kthLargestAdd(obj, nums[i]);
	}
	return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
	if (obj->n < obj->size) {
		obj->data[++(obj->n)] = val;
		int ind = obj->n;
		while(ind != 1 && obj->data[ind] < obj->data[ind >> 1]) {
			swap(obj->data[ind], obj->data[ind >> 1]);
			ind >>= 1;
		}
	} else if(val > obj->data[1]) {
		obj->data[1] = val;
		int ind = 1;
		while (ind << 1 <= obj->size) {
			int temp = ind, l = ind << 1, r = ind << 1 | 1;
			if (obj->data[l] < obj->data[temp]) temp = l;
			if (r <= obj->size && obj->data[r] < obj->data[temp]) temp = r;
			if (temp == ind) break;
			swap(obj->data[ind], obj->data[temp]);
			ind = temp;
		}
	}
	return obj->data[1];
}

void kthLargestFree(KthLargest* obj) {
	if (obj == NULL) return;
	free(obj->data);
	free(obj);
	return ;
}


#define swap(a, b) { \
		__typeof(a) _temp = a;\
		a = b, b = _temp; \
	}
	
/*==================================================*/
//自己的代码
	
	/*
	 *	维持一个K大小的数组，每次添加返回最小值
	 */
	
	//两个数值互换
	void swap(int *a, int *b)
	{
		if (a == b)
			return;
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
	 
	/* 
	 *	建立一个数量大小为K的最小堆，如果新元素比堆顶小则丢弃，反之则替代堆顶，然后调整堆，最终返回堆顶
	 */
	
	
	typedef struct {
		int maxSize;
		int heapSize;
		int *heap;
	} KthLargest;
	
	//最小堆调整函数，s表示数组下标，e表示堆尾下标
	void heapAdjust(int *heap, int s, int e)
	{
		int i,j,key = heap[s];
	
		for (j = 2*(s+1); j <= (e+1); j*=2)
		{
			if (j < (e+1) && heap[j-1] > heap[j])j++;
			if (heap[j-1] >= key)	break;
			heap[s] = heap[j-1];	s = j-1;
		}
		heap[s] = key;
		return;
	}
	
	//调用者负责增加堆的现有长度，传递进来的参数是数组下标，计算时候需要加1
	void heapInsert(int *heap, int e, int val)
	{
		int f;
		f = (e + 1) / 2;
		if (e == 0)
		{
			heap[e] = val;
			return;
		}
		else
		{
			while (f >= 1)
			{
				if (val < heap[f-1])
				{
					swap(heap+e, heap+f-1);
					e = f-1; f = (e + 1) / 2; 
				}
				else
					break;				  
			}
			heap[e] = val;
		}
		return;
	}
	
	KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
		int i = 0, j = 0;
		KthLargest* n = (KthLargest*)calloc(1, sizeof(KthLargest));
		n->maxSize = k;
		n->heapSize = 0;
		n->heap = (int *)calloc(k, sizeof(int));
		
		for (i = 0; i < k && i < numsSize; i++){
			n->heapSize++;
			heapInsert(n->heap, i, nums[i]);
		}
		
		if (i >= numsSize)
			return n;
		else if (i >= k && i < numsSize)
		{
			while (i < numsSize)
			{
				if(n->heap[0] < nums[i])
				{
					n->heap[0] = nums[i];
					heapAdjust(n->heap, 0, n->heapSize-1);
				}			 
				i++;
			}
		}
		return n;
	}
	
	int kthLargestAdd(KthLargest* obj, int val) {
		int i = 0;
		
		if (obj->heapSize < obj->maxSize)
		{
			heapInsert(obj->heap, obj->heapSize, val);
			obj->heapSize++;
		}
		else
		{
			if(obj->heap[0] < val)
			{
				obj->heap[0] = val;
				heapAdjust(obj->heap, 0, obj->heapSize-1);
			}		  
		}
		return obj->heap[0];
	}
	
	void kthLargestFree(KthLargest* obj) {
		free(obj);
		return;
	}
	
	/**
	 * Your KthLargest struct will be instantiated and called as such:
	 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
	 * int param_1 = kthLargestAdd(obj, val);
	 
	 * kthLargestFree(obj);
	*/
	
	
	
	/**
	 * Your KthLargest struct will be instantiated and called as such:
	 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
	 * int param_1 = kthLargestAdd(obj, val);
	 
	 * kthLargestFree(obj);
	*/


