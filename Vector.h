#ifndef LINALGCALCULATOR_VECTOR_H
#define LINALGCALCULATOR_VECTOR_H



template <typename T> class Vector {
    T* vector;
    int dimension;


    void setVector(){
        vector = (T*) malloc(dimension * sizeof(T));
        for(int i = 0; i < dimension; i++){
            cout << "Input v" << i+1 << " component of vector > ";
            cin >> vector[i];
        }
        cout << "------------------------------------------" << endl;
    }

    void cross_product_setVector(double i, double j, double k){ // creating a vector that is the result of cross-product
        this->vector[0] = i;
        this->vector[1] = j;
        this->vector[2] = k;
    }


    public:
        Vector(){
            vector = nullptr;
            dimension = 0;
        }
        Vector(int dimension){
            if(!dimension){
                cout << "Invalid vector dimension!" << endl;
                return;
            }
            this->dimension = dimension;
            this->setVector();
        }
        int getDimension(){
            return this->dimension;
        }

        void print(){
            cout << "[";
            for(int i = 0; i < dimension; i++){
                if(i != dimension-1) cout << vector[i] << ", ";
                else cout << vector[i] << "]" << endl;
            }
            cout << "------------------------------------------" << endl;
        }

        double module(){
            double mod;
            for(int i = 0; i < dimension; i++){
                mod += pow(vector[i], 2);
            }
            return sqrt(mod);
        }

        double dot_product(Vector<T> v2) {
            double product = 0;
            for(int i = 0; i < dimension; i++){
                product += this->vector[i] * v2.vector[i];
            }
            return product;
        }

        void cross_product(Vector<T> v2){
            int i = this->vector[1] * v2.vector[2] - this->vector[2] * v2.vector[1];
            int j = this->vector[2] * v2.vector[0] - this->vector[0] * v2.vector[2];
            int k = this->vector[0] * v2.vector[1] - this->vector[1] * v2.vector[0];
            this->cross_product_setVector(i, j, k);

        }

        Vector<T> operator+(Vector<T> other){
            *this += other;
            return *this;
        }

        Vector<T> operator+=(Vector<T> other){
            for(int i = 0; i < this->dimension; i++){
                this->vector[i] += other.vector[i];
            }
            return *this;
        }

        Vector<T> operator-(Vector<T> other){
            *this -= other;
            return *this;
        }

        Vector<T> operator-=(Vector<T> other){
            for(int i = 0; i < this->dimension; i++){
                this->vector[i] -= other.vector[i];
            }
            return *this;
        }

        Vector<T> operator*(const T scalar){
            *this *= scalar;
            return *this;
        }

        Vector<T> operator*=(const T scalar){
            for(int i = 0; i < this->dimension; i++){
                this->vector[i] *= scalar;
            }
            return *this;
        }


};


#endif //LINALGCALCULATOR_VECTOR_H
