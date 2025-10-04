bool isPalindrome(int x) {
    long ans=0;
    long temp=(long)x;
    while(temp>0){
        long rem=temp%10;
        ans=(ans*10)+rem;
        temp=temp/10;
    }
    if(ans==x)
        return true;
    return false;
}