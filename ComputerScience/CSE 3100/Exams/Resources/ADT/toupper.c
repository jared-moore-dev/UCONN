int main()
{
    int j = 0;
    char str[] = "geekforgeeks\n";
    char ch;

    while (str[j]) {
        ch = str[j];
        putchar(toupper(ch));
        j++;
    }

    return 0;
}