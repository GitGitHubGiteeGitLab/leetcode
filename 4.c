double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //ʹ�ù鲢�ķ�ʽ���ϲ������������飬�õ�һ������������顣�������������м�λ�õ�Ԫ�أ���Ϊ��λ��
    double ret = 0.0;
    int size = nums1Size + nums2Size;
    int res[size];
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j])res[k++] = nums1[i++];
        else res[k++] = nums2[j++];
    }
    if (i == nums1Size) {
        while (j < nums2Size) {
            res[k++] = nums2[j++];
        }
    }
    else {
        while (i < nums1Size) {
            res[k++] = nums1[i++];
        }
    }
    if ((size & 1) == 1)ret = res[k / 2];
    else ret = (res[k / 2] + res[k / 2 - 1]) * 1.0 / 2;
    return ret;
}