#include <ctype.h>
#include <glib.h>
/**
 * @brief Replaces ',' and '/' by ' ', deduplicates spaces within the string
 *        and strips spaces from both ends of the string
 *
 * @param pointer to the string to cleanup
 * @return pointer to the cleaned up string
 */
char *search_fix_spaces(const char *str) {
    size_t i, len=strlen(str);
    char c,*s,*d,*ret=g_strdup(str);

    if (len == 0) {
        return ret;
    }
    for (i = 0 ; i < len ; i++) {
        if (ret[i] == ',' || ret[i] == '/')
            ret[i]=' ';
    }
    s=ret;
    d=ret;
    len=0;
    do {
        c=*s++;
        // When the space is at the beginning of the line, just go to the next iteration to move the pointer further.
        if (0 != isspace(c) && len == 0){
           continue;
        }else{
            *d++=c;
            len++;
        }
        while (0 != isspace(c) && 0 != isspace(*s))
            s++;
        // This trims the last space of the string as it has already been de-duplicated.
        if (0 != isspace(c) && *s == '\0') {
            d--;
            len--;
        }
    } while (c);
    return ret;
}
