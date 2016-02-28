int lower(int c) {
    /* if c is upper perform (c + 'a' - 'A') else return original c */
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; 
}

