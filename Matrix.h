#ifndef LINALGCALCULATOR_MATRIX_H
#define LINALGCALCULATOR_MATRIX_H


template <typename T> class Matrix {
    T *matrix;
    int row;
    int column;
    int size;


    void setMatrix(){
        matrix = (T*) malloc((this->size)* sizeof(T));
        if(!matrix) throw runtime_error("Allocation of memory failed!"); //if matrix == nullptr, allocation failed
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                cout << "Input element on index (" << i+1 << ", " << j+1 << ") > ";
                cin >> matrix[i*column + j];
            }
        }
    }

    void switch_dimensions(){
        int temp = row;
        row = column;
        column = temp;
    }


    public:
        Matrix(){
            row = 0;
            column = 0;
            size = 0;
            matrix = nullptr;
        }
        Matrix(int row, int column){
            this->row = row;
            this->column = column;
            this->size = row*column;
            if(!size){ // if size == 0
                cout << "Invalid matrix dimensions!" << endl;
            }
            this->setMatrix();
        }


        void print(){
            for(int i = 0; i < row; i++){
                cout << "| ";
                for(int j = 0; j < column; j++){
                    cout << matrix[i*column + j] << " ";
                }
                cout << "|" << endl;
            }
            cout << "------------------------------------------" << endl;
        }

        void transpose(){ // needs fixing
            T *temp = (T*)malloc(this->size * sizeof(T));
            if(!temp) throw runtime_error("Allocation of memory failed!");
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    temp[j*row + i] = this->matrix[i*column + j];
                }
            }
            this->matrix = temp;
            delete temp;
            switch_dimensions();
        }

        Matrix<T> operator+(Matrix<T> m2){
            *this += m2;
            return *this;
        }

        Matrix<T> operator+=(Matrix<T> m2){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    this->matrix[i*column + j] += m2.matrix[i*column + j];
                }
            }
            return *this;
        }

        Matrix<T> operator-(Matrix<T> m2){
            *this -= m2;
            return *this;
        }

        Matrix<T> operator-=(Matrix<T> m2){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    this->matrix[i*column + j] -= m2.matrix[i*column + j];
                }
            }
            return *this;
        }


        Matrix<T> operator*=(const T scalar){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    this->matrix[i*column + j] *= scalar;
                }
            }
            return *this;
        }

        Matrix<T> operator*(const T scalar){
            *this *= scalar;
            return *this;
        }





};


#endif //LINALGCALCULATOR_MATRIX_H
