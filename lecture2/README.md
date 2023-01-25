# Lecture 2

1. value semantics
`void swap_val(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}`

2. reference semantics
`void swap_ref(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}`