/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* numsReturnSize) {
    int i,j;
    int *numsReturn = (int *)malloc(sizeof(int)*nums1Size);
    int flag;
    *numsReturnSize = nums1Size;
    for(i=0; i<nums1Size; i++){
        flag = 0;
        for(j=0; j<nums2Size; j++){
            if(!flag){
                if(nums1[i] != nums2[j]){
                    continue;
                }
                else{
                    flag = 1;
                }
            }
            else{
                if(nums2[j] > nums1[i]){
                    numsReturn[i] = nums2[j];
                    break;
                }
            }
        }//for j
        if(j == nums2Size)numsReturn[i] = -1;
    }//for i
    return numsReturn;
}
