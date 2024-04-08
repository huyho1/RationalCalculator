#include "rational.h"

Rational create_rational(const int num, const int denom) {
    struct Rational r1;
    r1.num = num;
    r1.denom = denom;
    simplify (&r1);
    return r1;
}

Rational copy_rational(const Rational* orig) {
    return create_rational(orig->num, orig->denom);
}

void simplify(Rational* r){
    int a = gcd (r->num, r->denom);
    if (r->denom < 0) {
        r->denom = 0 - r->denom;
        r->num = 0 - r->num;
    }
    r->num = r->num/a;
    r->denom = r->denom/a;
}

int gcd (int a, int b) {
    if (b==0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

Rational add (const Rational* num1, const Rational* num2) {
    Rational a1 = copy_rational(num1);
    Rational a2 = copy_rational(num2);
    int newDenom = num1->denom * num2->denom;
    a1.num = a1.num * a2.denom;
    a2.num = a2.num * a1.denom;
    int newNum = a1.num + a2.num;
    return create_rational(newNum, newDenom);
}

Rational subtract (const Rational* num1, const Rational* num2) {
    Rational a1 = copy_rational(num1);
    Rational a2 = copy_rational(num2);
    int newDenom = num1->denom * num2->denom;
    a1.num = a1.num * a2.denom;
    a2.num = a2.num * a1.denom;
    int newNum = a1.num - a2.num;
    return create_rational(newNum, newDenom);
}

Rational multiply (const Rational* num1, const Rational* num2) {
    int newNum = num1->num * num2->num;
    int newDenom = num1->denom * num2->denom;
    return create_rational(newNum, newDenom);
}

Rational divide (const Rational* num1, const Rational* num2) {
    int newNum = num1->num * num2->denom;
    int newDenom = num1->denom * num2->num;
    return create_rational(newNum, newDenom);
}

void print(FILE* file, const Rational* rational) {
    if (rational->denom == 1) {
        fprintf(file, "%d", rational->num);
    } else {
        fprintf(file, "%d/%d", rational->num, rational->denom);
    }
}

bool equal (const Rational* num1, const Rational* num2) {
    Rational a = copy_rational(num1);
    Rational b = copy_rational(num2);
    if (a.num == b.num && a.denom == b.denom) {
        return true;
    }
    else return false;
}

int compare (const Rational* num1, const Rational* num2) {
    if (equal (num1, num2)) { //if they are equal
        return 0;
    }
    if (num1->num < 0 && num2->num > 0) { //if first rational might be negative but second isnt
        return -1;
    }
    if (num1->num > 0 && num2->num < 0) { //if second rational might be negative but first isnt
        return 1;
    }
    int ad = num1->num * num2->denom;
    int bc = num1->denom * num2->num;
    if (ad < bc) {
        return -1;
    }
    if (ad > bc) {
        return 1;
    }
    return 0;
}
