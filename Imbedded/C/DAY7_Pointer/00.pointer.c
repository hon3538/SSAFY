int main(){
    int x=10;
    int *p=&x;

    printf("%d\n",*p);
    scanf("%d",&(*p));
    printf("%d",*p);
}