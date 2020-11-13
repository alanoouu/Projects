// Polynomial.h

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Alan Ou
// St.# : 301320642
// Email: alano@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "cmpt_error.h"
#include <vector>
#include <cmath>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients;
    int degree;
public:
    // Default constructor
    Polynomial()
            : coefficients(), degree(0) {}

    // Copy constructor
    Polynomial(const Polynomial &other)
            : coefficients(other.coefficients), degree(other.degree) {}

    // Fill constructor
    Polynomial(vector<double> coefficients)
            : coefficients(coefficients), degree(coefficients.size() - 1) {}

    // Assignment operator
    Polynomial &operator=(const Polynomial &other) {
        if (this == &other) {
            return *this;
        } else {
            for (int i = 0; i < other.degree; i++) {
                coefficients.at(i) = other.coefficients.at(i);
            }
        }
        return *this;
    }

    // Degree getter
    int get_degree() const {
        return degree;
    }

    // Coefficient getter
    vector<double> get_coefficients() const {
        return coefficients;
    }

    // [] operator overload
    double &operator[](int i) {
        return coefficients.at(i);
    }

    // Evaluate polynomial at x
    double eval(double x) const {
        double result = 0;
        double total = 0;
        for (int i = 0; i <= degree; i++) {
            result = coefficients.at(i) * pow(x, i);
            total = total + result;
        }
        return total;
    }

}; // class Polynomial

// Overload + for polynomial + polynomial
Polynomial operator+(Polynomial p, Polynomial q) {
    if (p.get_degree() > q.get_degree()) {
        for (int i = 0; i <= q.get_degree(); i++) {
            p[i] = p[i] + q[i];
        }
    } else if (p.get_degree() < q.get_degree()) {
        for (int i = 0; i <= p.get_degree(); i++) {
            q[i] = p[i] + q[i];
        }
        return q;
    } else {
        for (int i = 0; i <= p.get_degree(); i++) {
            p[i] = p[i] + q[i];
        }
    }
    return p;
}

// Overload + for constant + polynomial
Polynomial operator+(double x, Polynomial p) {
    p[0] = p[0] + x;
    return p;
}

// Overload + for polynomial + constant
Polynomial operator+(Polynomial p, double x) {
    p[0] = p[0] + x;
    return p;
}

// Overload - for polynomial - polynomial
Polynomial operator-(Polynomial p, Polynomial q) {
    if (p.get_degree() > q.get_degree()) {
        for (int i = 0; i <= q.get_degree(); i++) {
            p[i] = p[i] - q[i];
        }
    } else if (p.get_degree() < q.get_degree()) {
        // Distribute the negative to every term in the second polynomial
        for (int i = 0; i <= q.get_degree(); i++) {
            q[i] = q[i] * -1;
        }

        for (int i = 0; i <= p.get_degree(); i++) {
            q[i] = p[i] + q[i];
        }
        return q;
    } else {
        for (int i = 0; i <= p.get_degree(); i++) {
            p[i] = p[i] - q[i];
        }
    }
    return p;
}

// Overload - for constant - polynomial
Polynomial operator-(double x, Polynomial p) {
    p[0] = x - p[0];
    for (int i = 1; i <= p.get_degree(); i++) {
        p[i] = p[i] * -1;
    }
    return p;
}

// Overload - for polynomial - constant
Polynomial operator-(Polynomial p, double x) {
    p[0] = p[0] - x;
    return p;
}

// Overload * for polynomial * polynomial
Polynomial operator*(Polynomial p, Polynomial q) {
    int sumDegree = p.get_degree() + q.get_degree();
    vector<double> resultPoly;

    // add 0's to temp
    for (int k = 0; k <= sumDegree; k++) {
        resultPoly.push_back(0);
    }

    for (int i = 0; i <= p.get_degree(); i++) {
        for (int j = 0; j <= q.get_degree(); j++) {
            resultPoly.at(i + j) = resultPoly.at(i + j) + (p[i] * q[j]);
        }
    }
    return resultPoly;
}

// Overload * for constant * polynomial
Polynomial operator*(double x, Polynomial p) {
    for (int i = 0; i <= p.get_degree(); i++) {
        p[i] = p[i] * x;
    }

    // if multiply by 0
    if (x == 0) {
        vector<double> result = {0};
        return result;
    }
    return p;
}

// Function idea from www.cs.sfu.ca/CourseCentral/135/tjd/a3.html
// By: Toby Donaldson
//
// Overload * for polynomial * constant
Polynomial operator*(Polynomial p, double x) {
    for (int i = 0; i <= p.get_degree(); i++) {
        p[i] = p[i] * x;
    }

    // if multiply by 0
    if (x == 0) {
        vector<double> result = {0};
        return result;
    }
    return p;
}

// Overload << operator
ostream &operator<<(ostream &out, const Polynomial &p) {
    // Print the first coefficient and its power
    if (p.get_degree() == 0) {
        out << 0;
    } else {
        if (p.get_coefficients().at(0) == 0) {
            // don't print
        } else {
            out << p.get_coefficients().at(0);
        }

        // Print the second up to the second last coefficients and their powers
        for (int i = 1; i < p.get_degree(); i++) {
            // if the number before the second number before is a 0, don't print signs
            if (i == 1 && p.get_coefficients().at(0) == 0) {
                if (p.get_coefficients().at(1) == 0) {
                    // don't print
                } else if (p.get_coefficients().at(1) == 1) {
                    out << "x";
                } else if (p.get_coefficients().at(1) == -1) {
                    out << "x";
                } else if (p.get_coefficients().at(1) < 0) {
                    out << -1 * p.get_coefficients().at(1) << "x";
                } else {
                    out << p.get_coefficients().at(1) << "x";
                }
            } else if (i == 1) {
                if (p.get_coefficients().at(1) == 0) {
                    // don't print
                } else if (p.get_coefficients().at(1) == 1) {
                    out << " + " << "x";
                } else if (p.get_coefficients().at(1) == -1) {
                    out << " - " << "x";
                } else if (p.get_coefficients().at(1) < 0) {
                    out << " - " << -1 * p.get_coefficients().at(1) << "x";
                } else {
                    out << " + " << p.get_coefficients().at(1) << "x";
                }
            } else {
                if (p.get_coefficients().at(i) == 0) {
                    // don't print
                } else if (p.get_coefficients().at(i) == 1) {
                    out << " + " << "x";
                } else if (p.get_coefficients().at(i) == -1) {
                    out << " - " << "x";
                } else if (p.get_coefficients().at(i) < 0) {
                    out << " - " << -1 * p.get_coefficients().at(i) << "x^" << i;
                } else {
                    out << " + " << p.get_coefficients().at(i) << "x^" << i;
                }
            }
        }

        // Print the last coefficient and its power
        if (p.get_coefficients().at(p.get_degree()) == 0) {
            // don't print
        } else if (p.get_degree() == 1 && p.get_coefficients().at(p.get_degree()) < 0) {
            out << " + " << -1 * p.get_coefficients().at(p.get_degree()) << "x";
        } else if (p.get_degree() == 1) {
            out << " + " << p.get_coefficients().at(p.get_degree()) << "x";
        } else if (p.get_coefficients().at(p.get_degree()) == 1) {
            out << " + " << "x";
        } else if (p.get_coefficients().at(p.get_degree()) == -1) {
            out << " - " << "x";
        } else if (p.get_coefficients().at(p.get_degree()) < 0) {
            out << " - " << -1 * p.get_coefficients().at(p.get_degree()) << "x^" << p.get_degree();
        } else {
            out << " + " << p.get_coefficients().at(p.get_degree()) << "x^" << p.get_degree();
        }
    }
    return out;
}