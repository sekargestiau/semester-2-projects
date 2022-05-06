#include <iostream>
#include <set>
#include <cmath> // penambahan header <cmath> agar dapat menggunakan fungsi sqrt() 

// mengecek apakah `n` adalah bilangan prima
// return: `true` jika bilangan prima, `false` jika tidak
bool is_prime(int n) {
    // perbaikan fungsi is_prime dengan while loop sehingga fungsi is_prime() memiliki kompleksitas O(sqrt n)
    int i=2;
    while(i <= sqrt(n))
    {
        if (n % i == 0) {
            return false;
        }
        i++; 
    } 
    // fungsi is_prime() pada soal yang memiliki kompleksitas O(n)
        /*for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }*/
    return true;
}

int main() {
    std::set<int> prime_numbers;
    int i=2;
    // generate bilangan prima dari 1 sampai 100
    // dan masukkan ke dalam himpunan `prime_numbers`
    // tulis code anda di sini
    for (int j=2; j<=100; j++){
        if(is_prime(j)){
            prime_numbers.insert(j);
        }  
    }
    
    
    // cek bilangan prima
    std::cout << "Send Ctrl+C to exit" << std::endl;
    while (true) {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        // cek apakah `num` adalah bilangan prima dari 1 dan 100
        // fungsi is_prime() memiliki kompleksitas O(N), adakah versi yang lebih baik?
        // jika ada, perbaiki kondisi dalam if di bawah
        std::set<int>::iterator it = prime_numbers.find(num);
        if (it != prime_numbers.end()){
            std::cout << num << " is a prime number between 1 and 100" << std::endl;
        } else {
            std::cout << num << " is not a prime number between 1 and 100" << std::endl;
        }
    }
    
    return 0;
} 
