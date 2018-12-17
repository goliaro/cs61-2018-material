// This code, which claims to concatenate two input strings
// (so `combine("a", "b")` should return a string containing
// `"ab"`), is adapted from a published textbook called
// “Mastering C Pointers” (first edition, 1990).
//
// Read it and despair.
//
// https://wozniak.ca/blog/2018/06/25/Massacring-C-Pointers/
//
// As of 2018, the book is still available for sale!!!
// https://www.amazon.com/Mastering-Pointers-Tools-Programming-Power-ebook-dp-B01E549SAY/dp/B01E549SAY/

char* combine(char* s, char* t) {
    int x, y;
    char r[100];

    strcpy(r, s);
    y = strlen(r);
    for (x = y; *t != '\0'; ++x)
        r[x] = *t++;

    r[x] = '\0';

    return(r);
}
