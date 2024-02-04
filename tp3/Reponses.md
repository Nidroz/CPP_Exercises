# Réponses - TP3 - C++ - Nadir SIDHOUM

## EXERCICE 1
### CAS A
#### Question 1
Pourquoi n'y a-t-il pas de relation entre last_wheel et wheels[3] contrairement à first_wheel et wheels[0] ?

> Il n'y a pas de relation entre last_wheel et wheels[3]last_wheel et wheels[3],
contrairement à first_wheel et wheels[0], car last_wheel n'est pas un référence.
last_wheel copie uniquement car.wheels.back(); (wheels[3]).
Ce n'est last_wheel qui instancie wheels[3] (ou wheeles tout court).


### CAS B
#### Question 1
Dans le graphe d'ownership, on distingue un pointeur d'une référence, via une référence (pointeur: flèche en pointillée qui part d'un bloc de donnée).
(référence: flèche en pointillée qui part d'un bloc de référence (bloc en pointillé))

#### Question 2
Un pointeur nul (`nullptr`) est représenté par une référence à un cercle vide avec une croix à l'intérieur.

#### Question 3
En termes de code, les deux différences principales entre un pointeur-observant et une référence sont:
- On peut créer un pointeur vide (= à `nullptr`), mais pas une référence vide (référence vers toujours référence à une zone de donnée).
 
- Les pointeurs-obersants sont mutables dans les données qu'ils observent, de plus ils sont réassignables.
Alors que les références feront toujours référence au même bloc de données.


### CAS C
(Voir de notes, et fichier `CasC.cpp`)
```cpp
#include <memory>
#include <vector>

struct Product
{};

struct Client
{
    public:
        ~Client() {
            for (auto* product : products) {
                delete product;
            } 
        }

    std::vector<Product*> products;
};

int main()
{
    auto client = Client {};

    client.products.push_back(new Product{});
    client.products.push_back(new Product{});

    auto* first_product = client.products.front();
                                                    // <-- on est ici
    client.products.push_back(new Product{});
    return 0;
}
```



## EXERCICE 2
### Question 1
(voir fichier `exo2.cpp`)
```cpp
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

void add_to(int& a, int b)
{
    a += b;
}

int main()
{
    int x = 10;
    int y = add(x, x);
    add_to(y, 22);
    std::cout << x << " " << y << std::endl;
    return 0;
}
```

### Question 2
(voir le fichier `exo2_qts2.cpp`)
```cpp
#include <string>
#include <vector>

// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string& s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(float dt, std::string& errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(const std::vector<int>& values, std::vector<int>& negative_indices_out, size_t& negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
const std::string& concatenate(const std::string& str1, const std::string& str2);
```


## EXERCICE 3
=> Voir le sujet du `TP3.md`.

### 1. Architecture
- Architecture A:
Trop complexe, imaginons que l'on ajoute ou supprime un élément, il faut s'assurer 
que toutes les références soient correctes, et ainsi toujours maintenir la cohérence.
Faire attention que chaque référence fasse référence au bon élément.

- Architecture B:
Ici, on peut beaucoup plus facilement faire attention à cohérence des éléments et des références. 
En plus, chaque employé est directement associé à leur département (via des owners),
et donc plus facilement modifiable et vérifiable.

- Architecture C:
Pas lui, on peut avoir des dandling-references.

=> Donc ici, la meilleure architecture possible sera la B.


### 2. Compilation via CMake
1. Ouvrez le fichier 3-hrsoft/CMakeLists.txt et regardez son contenu.
Quels sont les exécutables présents dans ce projet ?
>  Les exécutables présents sont:
=> hrsoft-tests
- `HRSoftTests.cpp`
- `HRSoft/HRSoftSystem.hpp`
- `HRSoft/Department.hpp`
- `HRSoft/Employee.hpp`
=> hrsoft
- `HRSoftMain.cpp`
- `HRSoft/HRSoftSystem.hpp`
- `HRSoft/Department.hpp`
- `HRSoft/Employee.hpp`


2. 3. 4. FAITS


### 3. Implémentation du système
1. Pour quelle raison le programme utilise-t-il des `std::list` plutôt que des `std::vector` pour stocker les départements et les employés ?
> Le programme utilise des `std::list` plutôt que des `std::vector`, car `std::list` utilise 
les références pour stocker les éléments, et donc les éléments sont plus facilement modifiables.
Alors que `std::vector`, les éléments sont stockés dans un tableau, à savoir de manière contiguë.

> Voir le code directement dans le dossier `3-hrsoft`.
