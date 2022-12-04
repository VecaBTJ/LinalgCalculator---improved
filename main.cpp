#include<iostream>
#include <cmath>
#define MATRIX 1
#define VECTOR 2

using namespace std;
typedef int Math_Entity;
#include "Matrix.h"
#include "Vector.h"

bool isValidOperation(Math_Entity entity, int dimension, char operation){
    if (operation == 'X' && entity == VECTOR){
        if (dimension != 3) {
            cout << "Cross product is possible with 3-dimensional vectors!\n-------------------------------------"
                    "-----------------------" << endl;
            return false;
        }
        return true;
    }
    if((entity == VECTOR && (operation == 'M')) || operation == '+' || operation == '0' || operation == '-' ||
         operation == '*' || operation == '.' || operation == 'P' || (entity == MATRIX && (operation == 'T' ||
         operation == 'D' || operation == 'r'))){
        return true;
    }
    return false;

}

char chooseOperation(Math_Entity entity, int dimension){
    char operation;
    do {
        if (entity == VECTOR) {
            cout
                    << "Choose operation:\n+ for ADDITION of vectors\n- for SUBTRACTION of vectors\n* for SCALAR MULTIPLICATION"
                       " of a vector\n. for DOT PRODUCT of vectors\nX for CROSS PRODUCT of 3-dimensional vectors\nM for MODULE"
                       "of a vector\nP to print current vector\n0 for EXIT\n> ";
        } else if (entity == MATRIX) {
            cout
                    << "Choose operation:\n+ for ADDITION of matrices\n- for SUBTRACTION of matrices\n* for SCALAR MULTIPLICATION"
                       "of a matrix\n. for MULTIPLICATION of matrices\nT for TRANSPOSE of a matrix\nD for matrix DETERMINANT"
                       "\nr for matrix RANGE\nP to print current matrix\n0 for EXIT\n> ";
        }
        cin >> operation;
        cout << "------------------------------------------" << endl;
        if(!isValidOperation(entity, dimension, operation)){
            cout << "--Invalid value inputted!--" << endl;
            cout <<"------------------------------------------" << endl;
        }
    }while(!isValidOperation(entity, dimension, operation));
    return operation;
}

int main(){

    Math_Entity entity;
    bool chosen = false;
    int dimension = 0;
    int row = 0;
    int column = 0;

    while(!chosen) {
        cout << "Choose math entity:\n1 for MATRICES\n2 for VECTORS\n0 for END PROGRAM\n> ";
        cin >> entity;

        if(entity == VECTOR){
            cout << "Input vector dimension > ";
            cin >> dimension;
            chosen = true;
        }

        else if(entity == MATRIX){
            cout << "Input matrix dimensions:\nNumber of rows > ";
            cin >> row;
            cout << "Number of columns > ";
            cin >> column;
            chosen = true;
        }

        else if (entity == 0) {
            cout << "--PROGRAM ENDED--" << endl;
            return 0;
        }
        else cout << "--Invalid value inputted!--\n" << endl;
    }

    Vector<double> v(dimension); //no "invalid dimension" message
    Matrix<double> m(row, column); //no "invalid size" message

    char operation;
    while(1){
        operation = chooseOperation(entity, dimension);

        if(operation == '0'){
            cout << "--PROGRAM ENDED--" << endl;
            break;
        }

        if(entity == VECTOR) { // vector operations
            if (operation == '*') {
                double scalar;
                cout << "Input scalar > ";
                cin >> scalar;
                v *= scalar;
                cout << "RESULT:" << endl;
                v.print();
            }
            else if (operation == 'M') {
                cout << "Module of this vector is " << v.module() << endl;
                cout << "------------------------------------------" << endl;
            }
            else if (operation == 'P') {
                v.print();
            }

            else { // operations which create a new vector
                Vector<double> v2(dimension);

                if (operation == '+') {
                    cout << "RESULT:" << endl;
                    v += v2;
                    v.print();
                }
                else if (operation == '-') {
                    cout << "RESULT:" << endl;
                    v -= v2;
                    v.print();
                }
                else if (operation == '.') {
                    cout << "Scalar product of the given two vectors is " << v.dot_product(v2) << endl;
                    cout << "------------------------------------------" << endl;
                }
                else if (operation == 'X') {
                    cout << "RESULT:" << endl;
                    v.cross_product(v2);
                    v.print();
                }
            }
        }

        else if(entity == MATRIX) {
            if (operation == '*') {
                double scalar;
                cout << "Input scalar > ";
                cin >> scalar;
                m *= scalar;
                cout << "RESULT:";
                m.print();
            }
            else if(operation == 'T'){
                cout << "The transpose of the matrix is:" << endl;
                m.transpose();
                m.print();
            }
            else if (operation == 'P') {
                m.print();
            }

            else { // operations which create a new matrix
                Matrix<double> m2(row, column);

                if(operation == '+'){
                    cout << "RESULT:" << endl;
                    m += m2;
                    m.print();
                }
                else if(operation == '-'){
                    cout << "RESULT:" << endl;
                    m -= m2;
                    m.print();
                }
            }
        }

    }

    return 0;
}
