#include <iostream>
#include <vector>
#include <cstdlib>


std::vector<std::vector<int>> multiply(int N, std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    std::vector<std::vector<int>> C;
    C.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {           
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
            std::cout << C[i][j] << " " ;
        }   
        std::cout << std::endl;
    }
    return C;
}

std::vector<std::vector<int>> plus(int N, std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    std::vector<std::vector<int>> D;
    D.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = A[i][j] + B[i][j];
            std::cout << D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return D;
}

std::vector<std::vector<int>> minus(int N, std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    std::vector<std::vector<int>> E;
    E.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            E[i][j] = A[i][j] - B[i][j];
            std::cout << E[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return E;
}
                

int main() {

	srand(time(0));

	std::cout << "Hello! Enter matrix diagonal: " << std::endl;
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> A;
    A.assign(N, std::vector<int>(N));
    std::vector<std::vector<int>> B;
    B.assign(N, std::vector<int>(N));

    // Generating first Matrix and trade it to triangle Matrix A:
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1 + rand() % (15 - 1 + 1);
            for (int j = 0; j < i; j++) {
                A[i][j] = 0;
            }
       }        
    }
    std::cout << "Matrix A (triangle) is: " << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Generating second Matrix and trade it to triangle Matrix B:
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = 1 + rand() % (15 - 1 + 1);
            for (int j = 0; j < i; j++) {
                B[i][j] = 0;
            }
        }
    }
    std::cout << "Matrix B (triangle) is: " << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << B[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Multiply:
    std::vector<std::vector<int>> multiply_res;
    std::cout << "Matrix C (Multiply): " << std::endl;
    multiply_res = multiply(N, A, B);
    //Plus:
    std::vector<std::vector<int>> plus_res;
    std::cout << "Matrix D (Plus): " << std::endl;
    plus_res = plus(N, A, B);
    //Minus:
    std::vector<std::vector<int>> minus_res;
    std::cout << "Matrix E (Minus): " << std::endl;
    minus_res = minus(N, A, B);
}

