#include "./s21_string.h"

int d_check(char c, const char *delim) {
    int res = 0, f = 0;
    while (*delim != '\0' && f == 0) {
        if (c == *delim) {
            res = 1;
            f = 1;
        } else {
            delim++;
        }
    }
    return res;
}

char *s21_strchr(const char *s, int c) {
    char *answ = S21_NULL;
    int flag = 0;
    do {
        if (*s == c) {
            answ = (char *)s;
            flag = 1;
        }
    } while (*s++ != '\0' && flag != 1);
    if (flag == 0) {
        answ = S21_NULL;
    }
    return answ;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *a = (char*)dest;
    const char *b = (const char*)src;
    void *new = dest;
    if (a != S21_NULL && b != 0) {
        while (n--) {
            *a++ = *b++;
        }
    }
    return new;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t res = (s21_size_t)S21_NULL;
    if (str1 != S21_NULL) {
        res = s21_strlen(str1);
        int i = 0, f = 0;
        while (f == 0 && str1[i] != '\0') {
            if (d_check(str1[i], str2) == 1) {
                res = i;
                f = 1;
            }
            i++;
        }
    }
    return res;
}

s21_size_t s21_strspn(const char *s1, const char *s2) {
    const char *s = s1;
    const char *c;
    int f2 = 1;
    while (*s1 && f2 != 0) {
        int f1 = 1;
        for (c = s2; *c && f1 != 0; c++) {
            if (*s1 == *c) {
                f1 = 0;
                c--;
            }
        }
        if (*c == '\0')
            f2 = 0;
        if (f2 != 0)
            s1++;
    }
    return s1 - s;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; *(str + len); len++) { ; }
    return len;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    char *str_tmp = str;
        while (n > 0) {
        *str_tmp = (char)c;
        str_tmp++;
        n--;
    }
    return str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    char *s1 = (char*)str1;
    char *s2 = (char*)str2;
    int f = 0;
    int result = 0;
    while (n-- && f == 0) {
        if (*s1 == '\0' && *s2 == '\0') {
            result = 0;
            f = 1;
        } else if (*s1 != *s2) {
            result = *s1 - *s2;
            f = 1;
        } else {
        s1++;
        s2++;
        }
    }
    return result;
}
char *s21_strtok(char *str, const char *delim) {
    static char *s_str;
    char *str1 = S21_NULL;
    if (str == S21_NULL) {
        str = s_str;
        }
    if (*str != '\0') {
        int f = 0;
        while (f != 1) {
            if (*str == '\0') {;}
            while (d_check(*str, delim) == 1) {
                str++;
            }
            f = 1;
        }
        f = 0;
        if (*str == '\0') {
            s_str = str;
            f = 0;
        } else {
            str1 = str;
        }
        while (f != 1) {
            if (*str == '\0') {
                s_str = str;
                f = 1;
            } else if (d_check(*str, delim) == 1) {
                *str = '\0';
                s_str = str + 1;
                f = 1;
            } else {
                str++;
            }
        }
    }
    return str1;
}

char *s21_strcat(char *restrict a, const char *restrict b) {
    int i = 0, j = 0;
    while (a[i] != '\0') {
        i++;
    }
    for (j = 0; b[j] != '\0'; j++) {
        a[i + j] = b[j];
    }
    a[i + j] = '\0';
    return a;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *res = S21_NULL;
    if ((unsigned char*)str!= S21_NULL) {
        int f = 0;
        while (n-- && f == 0) {
            if (*(unsigned char*)str == (unsigned char)c) {
                res = (unsigned char*)str;
                f = 1;
            } else {
                str = ((unsigned char*)str) + 1;
            }
        }
    }
    return res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char *r = S21_NULL;
    for (; *str1 != '\0' && flag == 0; str1++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (*str1 == str2[j]) {
                flag = 1;
                r = (char *)str1;
            }
        }
    }
    return r;
}

char *s21_strcpy(char *dest, const char *src) {
    int i = 0, j = 0;
    while (i < (int)s21_strlen(src)) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    const char *s1 = str1;
    const char *s2 = str2;
    int flag = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (*s1 != *s2 && flag != 1) {
            result = *s1 - *s2;
            flag = 1;
        }
    s1++;
    s2++;
    }
    return result;
}

char* s21_strncat(char *dest, const char *src, s21_size_t n) {
    char* temp = dest + s21_strlen(dest);
    if (n > s21_strlen(src)) {
        n = s21_strlen(src);
    }
    while (*src != '\0' && n--) {
        *temp++ = *src++;
    }
        *temp = '\0';
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    int i = 0, j = 0;
    while (i < (int)n) {
        dest[j] = src[i];
        i++;
        j++;
    }
    return dest;
}

char *s21_strrchr(const char *str, int c) {
    char *answ = S21_NULL;
    do {
        if (*str == (char)c) {
            answ = (char *)str;
        }
    } while (*str++);
    return answ;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *destination = dest;
    const char *source = src;
    s21_size_t i;
    if (source >= destination) {
        for (i = 0; i < n; i++) {
            destination[i] = source[i];
        }
    } else {
        for (i = n; i > 0; i--) {
            destination[i-1] = source[i-1];
        }
    }
    return destination;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
        while (*str1 && *str1 == *str2) {
            str1++;
            str2++;
        }
    if (*str1 - *str2 == 0) {
        res = 0;
    } else if (*str1 - *str2 < 0) {
        res = -1;
    } else {
        res = 1;
    }
    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    const char *c = haystack;
    int f = 0;
    int same = 0;
    for (int i = 0; haystack[i] != '\0'; i++) {
        int a = i;
        int j = 0;
        while (haystack[i++] == needle[j++] && same == 0) {
            if (needle[j] == '\0') {
                f++;
                c = (char *)&haystack[a];
                same++;
            }
        }
    i = a;
    }
    if (*needle == 0) {
        f++;
    }
    if (f == 0) {
        c = S21_NULL;
    }
    return (char *)c;
    }



int s21_sprintf(char *str, const char *format, ...) {
    str[0] = '\0';
    int f = 1, answ = 0;
    int i = 0;
    va_list ap;
    va_start(ap, format);
    while (*format != '\0') {
        str[0] = '\0';
        struct processing strNew;
        s21_init(&strNew);
        int change = 0;
        int length = 0;
        if (*format != '%' && f == 1) {
            *str = *format;
            str++, format++;
            i++;
            *str = '\0';
        } else if (*++format == '%') {
            format += 1;
            *str++ = '%';
            i++;
            *str = '\0';
        } else {
            length = s21_structure(&strNew, format);
            if (strNew.type == '\0') {
                f = 0;
            }
        }
        if (strNew.type != '\0') {
            change = s21_ch_type(&strNew, str, ap, &change);
            str += change;
            *str = '\0';
        }
        format += length;
        answ += change;
    }
    *str = '\0';
    va_end(ap);
    return answ + i;
}

void s21_init(struct processing *p) {
    p->minus = 0;
    p->plus = 0;
    p->space = 0;
    p->zero = 0;
    p->width = 0;
    p->accuracy = 0;
    p->length = 0;
    p->point = 0;
    p->type = '\0';
}

int s21_structure(struct processing *p, const char *format) {
    int length = 0;
    while (p->type == '\0' && *format != '\0' && *format != '%') {
        if (!p->width && !p->length && !p->accuracy && !p->type) {
            int stat = 0;
            stat += s21_structure_flags(p, format);
            length += stat;
            format += stat;
        }
        if (!p->width && !p->accuracy) {
            int stat = 0;
            stat += s21_structure_width(p, format);
            length += stat;
            format += stat;
        }
        if (!p->length) {
            int stat = 0;
            stat += s21_structure_length(p, format);
            length += stat;
            format += stat;
        }
        if (!p->accuracy) {
            int stat = 0;
            stat += s21_structure_accuracy(p, format);
            length += stat;
            format += stat;
        }
        if (!p->type) {
            int stat = 0;
            stat += s21_structure_type(p, format);
            length += stat;
            format += stat;
        }
    }
    return length;
}

int s21_structure_flags(struct processing *p, const char *format) {
    const char *str = format;
    int length = 0;
    if (*str == '-' || *str == '+' || *str == ' ' || *str == '0') {
        if (*str == '-') {
            p->minus = 1;
            length += 1;
        }
        if (*str == '+') {
            p->plus = 1;
            length += 1;
            if (*(++str) == '-') {
                p->minus = 1;
                length += 1;
            }
        }
        if (*str == ' ') {
            p->space = 1;
            length += 1;
            if (*(++str) == '+' || *str == '-') {
                if (*str == '+') {
                p->plus = 1;
                length += 1;
                } else if (*str == '-') {
                p->minus = 1;
                length += 1;
            }
        }
        }
        if (*str == '0') {
            p->zero = 1;
            length += 1;
        }
    }
    return length;
}

int s21_structure_width(struct processing *p, const char *format) {
    const char *str = format;
    int length = 0;
    if (*str >= '1' && *str <= '9' && p->width == 0) {
        while (*str >= '0' && *str <= '9') {
            if (*str) {
                int stat_value = *str - 48;
                str++;
                length += 1;
                if (*str && *str >= '0' && *str <= '9' && p->width == 0) {
                    stat_value *= 10;
                    int stat_value2 = *str - 48;
                    stat_value += stat_value2;
                    p->width = stat_value;
                    str += 1;
                    length += 1;
                    if (*str && *str >= '0' && *str <= '9' && p->width != 0)  {
                        stat_value *= 10;
                        int stat_value3 = *str - 48;
                        stat_value += stat_value3;
                        p->width = stat_value;
                        str += 1;
                        length += 1;
                    } else {
                        p->width = stat_value;
                    }
                } else {
                    p->width = stat_value;
                }
            }
        }
    }
    return length;
}

int s21_structure_accuracy(struct processing *p, const char *format) {
    const char *str = format;
    int length = 0;
    if (*str == '.') {
        p->point = 1;
        length += 1;
        while (*(str + 1) >= '0' && *(str + 1) <= '9') {
            if (*str) {
                str++;
                int stat_value = *str - 48;
                length += 1;
                if (*(str + 1) >= '0' && *(str + 1) <= '9') {
                    int stat_value2 = 0;
                    str += 1;
                    stat_value *= 10;
                    stat_value2 = *str - 48;
                    stat_value += stat_value2;
                    p->accuracy = stat_value;
                    length += 1;
                } else {
                    p->accuracy = stat_value;
                }
            }
        }
    } else {
        if ((*(str+1) == 'f' || *str == 'f')) {
            if (p->length == 0 || (p->width == 0 && p->point == 0)) {
                p->accuracy = 6;
            }
        }
    }
    return length;
}

int s21_structure_length(struct processing *p, const char *format) {
    const char *str = format;
    int length = 0;
    if (*str == 'h' || *str == 'l') {
        if (*str == 'h') {
            p->length = 1;
            length += 1;
        }
        if (*str == 'l') {
            p->length = -1;
            length += 1;
        }
    }
    return length;
}

int s21_structure_type(struct processing *p, const char *format) {
    const char *str = format;
    int length = 0;
    if (*str == 'c' || *str == 'd' || *str == 'i' || *str == 'f' ||
        *str == 's' || *str == 'u' || *str == '%') {
        p->type = *str;
        length += 1;
    }
    return length;
}

int s21_ch_type(struct processing *p, char *str, va_list arg, int *change) {      // проверка типа
    if  (p->type == 'c') {
        *change = s21_cString(p, str, arg);
    } else if (p->type == 'd' || p->type == 'i') {
        *change = s21_dString(p, str, arg);
    } else if (p->type == 'f') {
        *change = s21_fString(p, str, arg);
    } else if (p->type == 's') {
        *change = s21_sString(p, str, arg);
    } else if (p->type == 'u') {
        *change = s21_uString(p, str, arg);
    }
    return *change;
}

int s21_cString(struct processing *p, char *str, va_list arg) {
    int i = 0, space = 1;
    if ((!p->minus && !p->width) || (p->minus && !p->width)) {
        char a = (char)va_arg(arg, int);
        *(str) = a;
        i++;
    } else if (p->minus && !p->zero && p->width) {
        int len_str = p->width;
            char a = (char)va_arg(arg, int);
            *(str) = a;
            i = len_str;
            for (int j = 1; j < p->width; j++) {
                str[j] = ' ';
            }
    } else if (!p->minus && !p->zero && p->width) {
        char buff[10000] = {'\0'};
        buff[0] = (char)va_arg(arg, int);
        int dif = p->width - (int)s21_strlen(buff);
        s21_add_SpaceZero_L(buff, dif, p, space);
        s21_strcat(str, buff);
        if (p->width > (int)s21_strlen(str)) {
            i = p->width;
        } else {
            i = (int)s21_strlen(str);
       }
    }
    return i;
}

int s21_dString(struct processing *p, char *str, va_list arg) {
    long int value = 0;
    int flag = 0;
    if (p->length == -1) {
        value = (long int)value;
        value = va_arg(arg, long int);
    } else if (p->length == 1) {
        value = (short int)value;
        value = va_arg(arg, int);
    } else {
        value = (int)value;
        value = va_arg(arg, int);
    }
    char ft[10000] = {'\0'}, b[10000] = {'\0'};
    int space = 1, simF = 0;
    s21_itoaINT(value, ft);
    if (p->accuracy > (int)s21_strlen(ft)) {
        int dif = p->accuracy - s21_strlen(ft);
        s21_add_SpaceZero_L(ft, dif, p, 0);
    }
    if (p->zero) {
        space = 0;
    }
    if ((p->plus && value > 0) || value < 0) {
        simF = -1;
    }
    if (p->width > (int)s21_strlen(ft) || p->space == 1) {
        if (p->minus || (p->plus && p->minus)) {
            s21_add_Space_R(p, ft, space);
            if ((p->plus && value > 0) || value < 0) {
                if (p->space) {
                    ft[s21_strlen(ft)] = '\0';
                } else {
                    ft[s21_strlen(ft) - 1] = '\0';
                }
            }
        } else {
            int i = 0;
            int minus_l = 0;
            if (space == 1) {
                if (p->plus && value > 0) {
                    b[0] = '+';
                    flag = 1;
                } else if (value < 0) {
                    b[0] = '-';
                } else if (p->space == 1) {
                    b[0] = ' ';
                }
                s21_strcat(b, ft);
                for (int j = s21_strlen(b); j; j--, i++) {
                    ft[i] = b[i];
                    b[i] = '\0';
                }
                simF += 1;
            }
            if (value < 0 && simF == -1 && p->zero) {
                b[0] = '-';
                minus_l = 1;
            }
            if (p->accuracy < p->width) {
                int dif = p->width - s21_strlen(ft);
                if (minus_l == 1) {
                    s21_add_SpaceZero_L(ft, (dif - 1), p, space);
                } else {
                    s21_add_SpaceZero_L(ft, dif, p, space);
                }
                space = 1;
                s21_strcat(b, ft);
                i = 0;
                for (int j = s21_strlen(b); j; j--, i++) {
                    ft[i] = b[i];
                    b[i] = '\0';
                }
                simF = 1;
                dif = p->width - s21_strlen(ft);
                s21_add_SpaceZero_L(ft, dif, p, space);
            }
        }
    }
    if (p->point && p->accuracy == 0 && value == 0) {
        ft[0] = '\0';
    }
    if ((p->plus && value > 0 && simF < 0) || (flag != 1 && p->space == 1
    && !p->minus && value > 0 && p->plus && p->width < (int)s21_strlen(ft))) {
        b[0] = '+';
    } else if (value < 0 && simF < 0) {
        b[0] = '-';
    } else if (p->space == 1 && value > 0 && !p->plus && ft[0] != ' ') {
        b[0] = ' ';
    }
    s21_strcat(b, ft);
    s21_strcat(str, b);
    return s21_strlen(str);
}

int s21_fString(struct processing *p, char *str, va_list arg) {
    long double value = va_arg(arg, double);
    char ft[10000] = {'\0'}, b[10000] = {'\0'};
    int space = 1;
    int simF = 0;
    s21_ftoa(p, ft, value);
    if (p->zero) {
        space = 0;
    }
    if ((p->plus && value > 0) || value < 0) {
        simF = -1;
    }
    if (p->width > (int)s21_strlen(ft)) {
        if (p->minus || (p->plus && p->minus)) {
            s21_add_Space_R(p, ft, space);
            if ((p->plus && value > 0) || value < 0) {
                if (p->space) {
                    ft[s21_strlen(ft)] = '\0';
                } else {
                    ft[s21_strlen(ft) - 1] = '\0';
                }
            }
        } else {
            if (space == 1) {
                if (p->plus && value > 0) {
                    b[0] = '+';
                }
                if (value < 0) {
                    b[0] = '-';
                }
                if (p->space == 1 && simF != -1 && !p->plus) {
                    b[0] = ' ';
                }
                s21_strcat(b, ft);
                int i = 0;
                for (int j = s21_strlen(b); j; j--, i++) {
                    ft[i] = b[i];
                    b[i] = '\0';
                }
                simF += 1;
            }
            int dif = p->width - s21_strlen(ft);
            s21_add_SpaceZero_L(ft, dif, p, space);
        }
    }
    if (p->plus && value > 0 && simF < 0) {
        b[0] = '+';
    } else if (value < 0 && simF < 0) {
        b[0] = '-';
    } else if (p->space == 1 && value > 0 && !p->plus && ft[0] != ' ') {
        b[0] = ' ';
    } else if (p->space == 1 && !p->minus && value > 0 && p->plus && p->width < (int)s21_strlen(ft)) {
        b[0] = '+';
    } else if (p->space == 1 && !p->minus && value == 0 && p->width < (int)s21_strlen(ft)) {
        b[0] = ' ';
    }
    s21_strcat(b, ft);
    s21_strcat(str, b);
    return s21_strlen(str);
}

int s21_sString(struct processing *p, char *str, va_list arg) {
    int i = 0, space = 1;
    char buff[10000] = {'\0'};
    char *argument = va_arg(arg, char *);
    if (argument == S21_NULL) {
        argument = "(null)";
    }
    int size_of_arg = s21_strlen(argument);
    s21_strcat(buff, argument);
    if ((p->accuracy < size_of_arg && p->accuracy) || ((p->width < size_of_arg) && p->accuracy == -1)) {
        s21_end_accuracy(buff, p);
    }
    if ((p->width > size_of_arg) && p->minus) {
        s21_add_Space_R(p, buff, space);
    }
    if ((p->width > size_of_arg) && !p->minus) {
        int dif = p->width - s21_strlen(buff);
        s21_add_SpaceZero_L(buff, dif, p, space);
    }

    if (p->accuracy < (int)s21_strlen(argument) && p->accuracy != 0
        && p->width <= (int)s21_strlen(argument)) {
        int dif = p->width - p->accuracy;
        buff[p->accuracy + 1] = '\0';
        if (p->minus) {
            s21_add_Space_R(p, buff, space);
        } else if (p->width) {
            s21_add_SpaceZero_L(buff, dif, p, space);
        }
    }

    for (int j = 0; j < (int)s21_strlen(buff) + 1; j++) str[j] = buff[j];
    if (p->accuracy == 0 && p->point && p->width != 0) {
        str[0] = '\0';
        int dif = p->width - s21_strlen(str);
        s21_add_SpaceZero_L(str, dif, p, space);
        i = p->width;
    } else if (p->width > (int)s21_strlen(str) && p->minus) {
        i = p->width;
    } else {
        i = s21_strlen(str);
    }
    return i;
}

int s21_uString(struct processing *p, char *str, va_list arg) {
    unsigned long value = 0;
    if (p->length == -1) {
        value = va_arg(arg, long int);
    } else if (p->length == 1) {
        value = (short unsigned)value;
        value = va_arg(arg, long int);
    } else {
        value = (unsigned)value;
        value = va_arg(arg, long int);
    }
    char ft[10000] = {'\0'}, b[10000] = {'\0'};
    int space = 1;
    s21_itoaUN(value, ft);
    if (p->accuracy > (int)s21_strlen(ft)) {
        int dif = p->accuracy - s21_strlen(ft);
        s21_add_SpaceZero_L(ft, dif, p, 0);
    }
    if (p->zero) {
        space = 0;
    }
    if (p->width > (int)s21_strlen(ft)) {
        if (p->minus || (p->plus && p->minus)) {
            s21_add_Space_R(p, ft, space);
        } else {
            if (p->accuracy < p->width) {
                int dif = p->width - s21_strlen(ft);
                s21_add_SpaceZero_L(ft, dif, p, space);
                space = 1;
                s21_strcat(b, ft);
                int i = 0;
                for (int j = s21_strlen(b); j; j--, i++) {
                    ft[i] = b[i];
                    b[i] = '\0';
                }
                dif = p->width - s21_strlen(ft);
                s21_add_SpaceZero_L(ft, dif, p, space);
            }
        }
    }
    s21_strcat(b, ft);
    s21_strcat(str, b);
    return s21_strlen(str);
}

void s21_add_Space_R(struct processing *p, char *str, int f) {
    char *stat_array = calloc((int)p->width + 1, sizeof(char));
    if (S21_NULL == stat_array) { exit(0); }
    stat_array[(int)p->width] = '\0';

    if (p->width > (int)s21_strlen(str) && p->space) {
        if ((int)s21_strlen(str) == 1) {
            s21_memset(stat_array, ' ', p->width - 1);
        } else {
            s21_memset(stat_array, ' ', p->width - (int)s21_strlen(str) - 1);
        }
    } else {
        for (int i = 0; i < (int)p->width - (int)s21_strlen(str); i++) {
            if (f == 1)
                stat_array[i] = ' ';
            }
    }
    s21_strcat(str, stat_array);
    s21_memset(stat_array, '\0', s21_strlen(stat_array));
    free(stat_array);
}

void s21_add_SpaceZero_L(char *buff, int dif, struct processing *p, int f) {
    char *stat_array = calloc((int)(p->width + (int)s21_strlen(buff)
        + p->minus + p->plus + p->accuracy + 1), sizeof(char));
    if (S21_NULL == stat_array) { exit(0); }
    stat_array[(int)(p->width + (int)s21_strlen(buff))] = '\0';
    for (int i = 0; i < dif; i++) {
        if (f == 1) {
            stat_array[i] = ' ';
        } else if (f == 0) {
            stat_array[i] = '0';
            if (dif > 0) {
                stat_array[0] = '0';
            }
        }
    }
    s21_strcat(stat_array, buff);
    s21_memset(buff, '\0', s21_strlen(buff));
    s21_strcat(buff, stat_array);
    free(stat_array);
}

void s21_end_accuracy(char *buff, struct processing *p) {
    buff[p->accuracy] = '\0';
}

void s21_itoaINT(long int value, char *str) {
    if (value < 0) {
        int f = 0;
        if (value == LONG_MIN || value == INT_MIN) {
            f = 1;
            value += 1;
            value = (-1)*(value);
        } else {
            value = (-1)*(value);
        }
        long int sink = 0;
        long int j = value;
        int flag_edge = 0;
        for (sink = 1; j >= 10; j /= 10) sink *= 10;
        for (; sink > 0; sink /= 10) {
            *str++ = '0' + value / sink;
            if (f == 1 && flag_edge == 0 && sink <=10) {
                value += 1;
                flag_edge = 1;
            } else {
                value %= sink;
            }
           value %= sink;
        }
        *str = '\0';
    } else {
        long int sink = 0;
        long int j = value;
        for (sink = 1; j >= 10; j /= 10) {
            sink *= 10;
        }
        for (; sink > 0; sink /= 10) {
            *str++ = 48 + value / sink;
            value %= sink;
        }
        *str = '\0';
    }
}

void s21_itoaUN(unsigned long value, char *str) {
    unsigned long sink = 0, j = value;
    for (sink = 1; j >= 10; j /= 10) sink *= 10;
    for (; sink > 0; sink /= 10) {
        *str++ = 48 + value / sink;
        value %= sink;
    }
    *str = '\0';
}


void s21_reverse(char* str, int len) {
    int i = 0, j = len - 1;
    while (i < j) {
        int temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int s21_ToStr(long int x, char str[], int d) {
    int i = 0;
    long int v = x;
    if (x < 0) {
        v = v*(-1);
    }
    if (x != 0) {
        while (v) {
        str[i++] = (v % 10) + '0';
        v = v / 10;
        }
    } else {
        str[i++] ='0';
    }
    while (i < d)
        str[i++] = '0';
    s21_reverse(str, i);
    str[i] = '\0';
    return i;
}

void s21_ftoa(struct processing *n, char *str, long double value) {
    int ipart = (int)value;
    int i = 0;
    long double fpart = value - (double)ipart;
    if (fpart >= 0.99999 && n->accuracy < 6) {
        ipart += 1;
    } else if (fpart <= -0.99999 && n->accuracy < 6) {
        ipart -= 1;
    }
    if ((value > 0 && value < 1) || (value < 0 && value > -1)) {
        i = s21_ToStr(0, str, 0);
    } else {
        i = s21_ToStr(ipart, str, 0);
    }
    long double fpart_n = fpart;
    if (n->accuracy != 0) {
        str[i] = '.';
        for (int i_c = 0; i_c < n->accuracy; i_c++) {
            fpart = fpart * 10;
        }
        if (n->accuracy > 9) {
            long int end_val = 0;
            long int k;
            int length_k = 0;
            if (n->accuracy > 13 && n->accuracy < 20) {
                k = fpart/pow(10, (n->accuracy/2) - 1);
            } else {
                k = round(fpart/pow(10, (n->accuracy/2) - 1));
            }
            int i_n = s21_ToStr(round(k), str + i + 1, (n->accuracy)/2 - 1);
            for (int j = 0; j < n->accuracy/2 - 1; j++) {
                k = k * 10;
            }
            long int v_k = k;
            while (v_k) {
                length_k += 1;
                v_k /= 10;
            }
            long double end = round(fpart -  k/pow(10, ((n->accuracy) - length_k)));
            if (length_k != 0) {
                end_val = end*pow(10, (n->accuracy - length_k));
            } else {
                end_val = end;
            }
            s21_ToStr(round(end_val), str + i + i_n + 1, n->accuracy - i_n);
        } else {
            if ((fpart_n >= 0.99999 || fpart_n <= -0.99999) && n->accuracy < 6) {
                s21_ToStr(0, str + i + 1, n->accuracy);
            } else {
                s21_ToStr((int)round(fpart), str + i + 1, n->accuracy);
            }
        }
    } else {
        if (value < 0) {
            fpart = (-1) * fpart;
        }
        if (ipart > 0) {
            ipart += 1;
        } else {
            ipart -= 1;
        }
        if (fpart >= 0.5) {
            s21_ToStr(ipart, str, 0);
        }
    }
}

void *s21_to_lower(const char *str) {
    char *s = S21_NULL;
    if (str != S21_NULL) {
        s = (char *)calloc((s21_strlen(str)+1), sizeof(char));
        s21_strcpy(s, str);
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + ('a' - 'A');
            i++;
        }
    }
    return s;
}

void *s21_to_upper(const char *str) {
    char *s = S21_NULL;
    if (str != S21_NULL) {
        s = (char *)calloc((s21_strlen(str)+1), sizeof(char));
        s21_strcpy(s, str);
        int i = 0;
        while (s[i] != '\0') {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - ('a' - 'A');
            i++;
        }
    }
    return s;
}

int start_trim_chars(const char *s, const char *tc, s21_size_t len_src,
    s21_size_t len_trim) {
    int start = 0, f = 0;
    s21_size_t i = 0;
    while (i < len_src && f == 0) {
        s21_size_t j = 0;
        while (j < len_trim && s[i] != tc[j]) { j++; }
        if (s[i] == tc[j]) {
            start++;
            i++;
        } else {
            f = 1;
        }
    }
    return start;
}

int end_trim_chars(const char *s, const char *tc, s21_size_t len_src,
        s21_size_t len_trim) {
    int end = len_src, f = 0;
    int i = len_src - 1;

    while (i > -1 && f == 0) {
        s21_size_t j = 0;
        while (j < len_trim && s[i] != tc[j]) { j++; }
        if (s[i] == tc[j]) {
            end--;
            i--;
        } else {
            f = 1;
        }
    }
    return end;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *s = (char *)src;
    char *tc = (char *)trim_chars;
    char *res = S21_NULL;
    if (tc == S21_NULL || *tc == '\0') {
        trim_chars = " ";
        tc = (char *)trim_chars;
    }
    if (s != S21_NULL) {
        s21_size_t len_src = s21_strlen(src);
        s21_size_t len_trim = s21_strlen(trim_chars);
        int arr = 0;

        res = (char *)malloc((len_src + 1) * sizeof(char));
        if (S21_NULL == res) { exit(0); }
        res[len_src] = '\0';
        int start = start_trim_chars(s, tc, len_src, len_trim);
        int end = end_trim_chars(s, tc, len_src, len_trim);
        for (int i = start; i < end; i++) {
            res[arr] = src[i];
            arr++;
        }
        res[arr] = '\0';
    }
    return (char *)res;
}


void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *s = S21_NULL;
    if (str == S21_NULL && src != S21_NULL) {
        s = (char *)calloc((s21_strlen(src) + 1), sizeof(char));
        s21_strcpy(s, src);
    }
    if (src != S21_NULL && str != S21_NULL&& start_index <= s21_strlen(src)) {
        s = (char *)calloc((s21_strlen(src) + s21_strlen(str) + 1), sizeof(char));
        s21_strncpy(s, src, start_index);
        s21_strcat(s, str);
        s21_strcat(s, src + start_index);
    }
    return s;
}


char *s21_strerror(int errnum) {
    int max_n = 0;
    const char *error = S21_NULL;
    static char temp[100];
    #ifdef __APPLE__
        max_n = 106;
    #elif defined __linux__
        max_n = 133;
    #endif  // __APPLE__ && linux
    if (errnum >= 0 && errnum <= max_n) {
        const char *ERROR[] = ERRORS;
        error = ERROR[errnum];
    } else {
    #ifdef __APPLE__
        s21_sprintf(temp, "Unknown error: %d", errnum);
    #elif defined __linux__
        s21_sprintf(temp, "Unknown error %d", errnum);
    #endif  // __APPLE__ && __linux__
    }
    return (char *)error == S21_NULL ? temp : (char *)error;
}

