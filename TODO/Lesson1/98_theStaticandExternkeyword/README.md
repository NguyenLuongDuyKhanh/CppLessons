8. Inline vs static
static int f() { return 1; }
inline int g() { return 2; }

Keyword	Purpose
static	Internal linkage
inline	Multiple definitions allowed + inline hint

They solve different problems.