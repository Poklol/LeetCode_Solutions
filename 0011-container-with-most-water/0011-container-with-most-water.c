int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    long long max_area = 0;

    while (left < right) {
        int h = (height[left] < height[right]) ? height[left] : height[right];
        long long width = (long long)(right - left);
        long long area = h * width;
        if (area > max_area) max_area = area;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return (int)max_area;
}
