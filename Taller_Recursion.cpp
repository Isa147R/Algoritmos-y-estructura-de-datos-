//Dise˜ne e implemente un programa que utilice recursi´on para calcular la k-´esima potencia de un n´umero entero n, donde k es un entero no negativo.
int calcularPotencia(int n, int k) {
    // Caso base: si k es 0, la potencia es 1
    if (k == 0) {
        return 1;
    }
    // Caso recursivo: n multiplicado por la potencia (k-1) de n
    return n * calcularPotencia(n, k - 1);
}

//Dise˜ne e implemente un programa que reciba un string y retorne la versi´on invertida de ese string
void reverseString(std::string str) {
    if (str.size() == 0) {
        return;
    }
    reverseString(str.substr(1));
    std::cout << str[0];
}

//Dise˜ne e implemente un programa que utilice recursi´on para determinar si un string es un pal´ındromo. 
bool isPalindrome(std::string str) {
    // Convertir el string a minúsculas
    for (char& c : str) {
        c = std::tolower(c);
    }
    
    // Caso base: si el string está vacío o tiene un solo carácter, es un palíndromo
    if (str.size() <= 1) {
        return true;
    }
    
    // Comparar el primer y último carácter del string
    if (str[0] != str[str.size() - 1]) {
        return false;
    }
    
    // Llamar a la función recursivamente con el string sin el primer y último carácter
    return isPalindrome(str.substr(1, str.size() - 2));
}

//Dise˜ne e implemente un programa que utilice recursi´on para calcular
int binomialCoefficient(int n, int k) {
    // Caso base: C(n, 0) y C(n, n) son siempre 1
    if (k == 0 || k == n) {
        return 1;
    }
    
    // Llamada recursiva para calcular C(n-1, k-1) + C(n-1, k)
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

//Es decir para un vector {1,3,...,5,7} se debe obtener el resultado {7,5,..,3,1}
// Función auxiliar para invertir los elementos del vector
void reverse_helper(std::vector<int>& vec, int start, int end) {
    // Caso base: si start >= end, no hay más elementos para intercambiar
    if (start >= end) {
        return;
    }
    
    // Intercambiar los elementos en las posiciones start y end
    int temp = vec[start];
    vec[start] = vec[end];
    vec[end] = temp;
    
    // Llamada recursiva para invertir los elementos restantes
    reverse_helper(vec, start + 1, end - 1);
}

// Función principal para invertir los elementos del vector
void reverse_vector(std::vector<int>& vec) {
    int start = 0;
    int end = vec.size() - 1;
    
    reverse_helper(vec, start, end);
}

//Dise˜ne e implemente un algoritmo recursivo para determinar todas las permutaciones de los caracteres en una cadena s.
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// Función auxiliar para generar todas las permutaciones posibles
void generatePermutations(std::string& str, int index, std::set<std::string>& permutations) {
    // Caso base: si hemos llegado al final de la cadena, agregamos la permutación al conjunto de resultados
    if (index == str.length()) {
        permutations.insert(str);
        return;
    }
    
    // Recorrer todos los caracteres a partir del índice actual
    for (int i = index; i < str.length(); i++) {
        // Intercambiar el carácter en el índice actual con el carácter en el índice i
        std::swap(str[index], str[i]);
        
        // Llamar recursivamente a la función para generar permutaciones con el siguiente índice
        generatePermutations(str, index + 1, permutations);
        
        // Restaurar el intercambio para generar otras permutaciones
        std::swap(str[index], str[i]);
    }
}

// Función principal para encontrar todas las permutaciones de una cadena
void permute(string str, int l, int r, set<string>& permutations) {
    if (l == r) {
        permutations.insert(str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, permutations);
            swap(str[l], str[i]);
        }
    }
}

void findAllPermutations(string str) {
    set<string> permutations;
    permute(str, 0, str.length() - 1, permutations);
    
    for (const string& permutation : permutations) {
        cout << permutation << endl;
    }
}

//Devuelve los la suma de los primeros N numeros enteros
int sumaRecursiva(int n, int suma, int count)
{
    if (++count <= n)
        return sumaRecursiva(n, suma + count, count);
    else
        return suma;
}

//Escriba una definición recursiva de una función que tiene un parámetro n de tipo entero y que devuelve el n-ésimo número de Fibonacci. 
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// La forma para calcular cuantas maneras diferentes tengo para elegir r cosas distintas de un conjunto de n cosas 
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int combination(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
}

//Escribir un programa que encuentre la suma de los enteros positivos pares desde N hasta 2. Chequear que si N es impar se imprima un mensaje de error.
int sumaNumerosPares(int N) {
    if (N % 2 != 0) {
        std::cout << "Error: El número ingresado es impar." << std::endl;
        return 0;
    }

    int sum = 0;
    for (int i = N; i >= 2; i -= 2) {
        sum += i;
    }

    return sum;
}

//Escribir un programa que calcule el máximo común divisor (MCD) de dos enteros positivos.
int gcd(int M, int N) {
    if (M < N) {
        // Intercambiar los valores de M y N si M es menor que N
        int temp = M;
        M = N;
        N = temp;
    }
  if (N == 0) {
        return M;
    }
    return gcd(N, M % N);
}

//Programe un método recursivo que transforme un número entero positivo a notación binaria.
void decToBin(int n) {
    if (n > 1) {
        decToBin(n / 2);
    }
    std::cout << n % 2;
}

//Programe un método recursivo que transforme un número expresado en notación binaria a un número entero.
int binaryToDecimal(std::string binary, int index = 0) {
    if (index == binary.length()) {
        return 0;
    }
    int digit = binary[index] - '0';
    return digit * pow(2, binary.length() - index - 1) + binaryToDecimal(binary, index + 1);
}

//Programe un método recursivo que invierta el valor de un número entero (123 -> 321).
int reverseNumber(int n) {
    if (n < 10) {
        return n;
    }
    int lastDigit = n % 10;
    int remainingDigits = n / 10;
    int reversedNumber = reverseNumber(remainingDigits);
    int numDigits = 1;
    int temp = remainingDigits;
    while (temp > 9) {
        temp /= 10;
        numDigits *= 10;
    }
    return lastDigit * numDigits + reversedNumber;
}



