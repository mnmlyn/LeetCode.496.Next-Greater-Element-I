/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//这种方法的效率更低，比master中的方法效率还低
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* numsReturnSize) {
    int *numsReturn = (int *)malloc(sizeof(int)*nums1Size);
    //用栈来辅助，求num2中，每个数字后面更大的数
    int *stack = (int *)malloc(sizeof(int)*nums2Size);
    int *greater = (int *)malloc(sizeof(int)*nums2Size);
    int *sb = stack,*sp = stack;
    int i,j;
    *sp = nums2[nums2Size-1];sp++;//入栈
    greater[nums2Size-1] = -1;
    for(i=nums2Size-2; i>=0; i--){
        while(nums2[i]>*(sp-1) && sp!=sb){
            sp--;
        }
        if(sp!=sb){
            greater[i] = *(sp-1);
        }
        else{
            greater[i] = -1;
        }
        *(sp++) = nums2[i]; 
    }
    //从nums1中寻找对应的数字
    for(i=0; i<nums1Size; i++){
        for(j=0; j<nums2Size; j++){
            if(nums1[i] == nums2[j]){
                numsReturn[i] = greater[j];
            }
        }
    }
    *numsReturnSize = nums1Size;
    return numsReturn;
}
